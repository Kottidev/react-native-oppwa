package org.oppwa;

import android.app.Activity;
import android.app.Application;
import android.content.BroadcastReceiver;
import android.content.Context;

import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.util.Log;
import android.content.ServiceConnection;
import android.content.ComponentName;
import android.os.IBinder;

import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.LifecycleEventListener;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.oppwa.mobile.connect.exception.PaymentError;
import com.oppwa.mobile.connect.exception.PaymentException;
import com.oppwa.mobile.connect.payment.CheckoutInfo;
import com.oppwa.mobile.connect.payment.card.CardPaymentParams;
import com.oppwa.mobile.connect.provider.Connect;
import com.oppwa.mobile.connect.provider.ITransactionListener;
import com.oppwa.mobile.connect.provider.Transaction;
import com.oppwa.mobile.connect.service.IProviderBinder;
import com.oppwa.mobile.connect.service.ConnectService;

import javax.annotation.Nullable;

public class RNOppwaModule extends ReactContextBaseJavaModule implements ITransactionListener {
  private final static String TAG = RNOppwaModule.class.getCanonicalName();
  private IProviderBinder binder;
  private Context mApplicationContext;
  private Intent bindIntent;
  // private Promise promiseModule;

  private ServiceConnection serviceConnection = new ServiceConnection() {
    @Override
    public void onServiceConnected(ComponentName name, IBinder service) {
      binder = (IProviderBinder) service;
      /* we have a connection to the service */
      try {
        binder.initializeProvider(Connect.ProviderMode.LIVE);
      } catch (PaymentException ee) {
        /* error occurred */
      }
    }

    @Override
    public void onServiceDisconnected(ComponentName name) {
      binder = null;
    }
  };

  public RNOppwaModule(ReactApplicationContext reactContext) {
    super(reactContext);
    mApplicationContext = reactContext.getApplicationContext();
    Intent intent = new Intent(mApplicationContext, ConnectService.class);

    mApplicationContext.startService(intent);
    mApplicationContext.bindService(intent, serviceConnection, Context.BIND_AUTO_CREATE);

  }


  public void unBindService() {
    if (serviceConnection != null) {
      // Unbind from the In-app Billing service when we are done
      // Otherwise, the open service connection could cause the device’s performance to degrade
      mApplicationContext.unbindService(serviceConnection);
    }
  }

  @Override
  public String getName() {
    return "RNOppwa";
  }

  @ReactMethod
  public void transactionPayment(ReadableMap options, Promise promise) {
    try {

      boolean isTokenizationEnabled = true;
      CardPaymentParams cardPaymentParams = new CardPaymentParams(options.getString("checkoutID"),
          options.getString("paymentBrand"), options.getString("cardNumber"), options.getString("holderName"),
          options.getString("expiryMonth"), options.getString("expiryYear"), options.getString("cvv"));

      if (!CardPaymentParams.isNumberValid(options.getString("cardNumber"), options.getString("paymentBrand"))) {
        promise.reject("oppwa/card-invalid", "The card number is invalid.");
      }

      cardPaymentParams.setTokenizationEnabled(true);

      Transaction transaction = null;

      try {

        transaction = new Transaction(cardPaymentParams);

        binder.submitTransaction(transaction);
        binder.addTransactionListener(RNOppwaModule.this);
        promise.resolve(null);
      } catch (PaymentException ee) {
        promise.reject(null, ee.getMessage());
      }
    } catch (PaymentException e) {
      promise.reject(null, e.getMessage());
    }

  }

  @Override
  public void paymentConfigRequestSucceeded(CheckoutInfo checkoutInfo) {
    Log.i("W99l-payment-hyperpsy", "RequestSucceeded " + checkoutInfo.getCurrencyCode());

  }

  @Override
  public void paymentConfigRequestFailed(PaymentError paymentError) {
    Log.i("W99l-payment-hyperpsy",
        "RequestFailed " + paymentError.getErrorInfo() + " : " + paymentError.getErrorMessage());
  }

  @Override
  public void transactionCompleted(Transaction transaction) {
    // shoud add listner 

    // promiseModule.resolve(transaction);

  }

  @Override
  public void transactionFailed(Transaction transaction, PaymentError paymentError) {
    Log.i("W99l-payment-hyperpsy",
        "transactionFailed " + paymentError.getErrorMessage() + " : " + paymentError.getErrorInfo());
  }
}