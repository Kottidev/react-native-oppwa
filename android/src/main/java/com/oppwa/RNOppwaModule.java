
package com.oppwa;

import android.util.Log;
import android.app.Activity;
import android.content.IntentSender;

import java.util.Map;
import java.util.List;
import java.util.HashMap;
import java.util.ArrayList;

// react
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;

// play services

@SuppressWarnings("WeakerAccess")
public class RNOppwaModule extends ReactContextBaseJavaModule {
  private static final String TAG = "RNOppwa";

  public RNOppwaModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  public String getName() {
    return TAG;
  }


  @ReactMethod
  public void transactionPayment(ReadableMap options, Callback callback) {
    binder.initializeProvider(Connect.ProviderMode.LIVE); 

    WritableMap response = Arguments.createMap();
    response.putString("result", "success");
    callback.invoke(null, response);
  }

}