#import "RNOppwa.h"
#import <OPPWAMobile/OPPWAMobile.h>

@implementation RNOppwa
RCT_EXPORT_MODULE(RNOppwa);

- (id)init {
    self = [super init];
    self.provider = [OPPPaymentProvider paymentProviderWithMode:OPPProviderModeTest];
    // self.provider = [OPPPaymentProvider paymentProviderWithMode:OPPProviderModeLive];
    if (self != nil) {
        NSLog(@"Setting up RNOppwa instance");
    }
    return self;
}

- (NSArray<NSString *> *)supportedEvents {
    return @[];
}

/**
 * transaction
 */
RCT_EXPORT_METHOD(transactionPayment:
    (NSString *) appName
            options:
            (NSDictionary *) options
            resolver:
            (RCTPromiseResolveBlock) resolve
            rejecter:
            (RCTPromiseRejectBlock) reject) {

    OPPCardPaymentParams *params = [OPPCardPaymentParams cardPaymentParamsWithCheckoutID:self.checkoutID
                                                                        paymentBrand:@"VISA"
                                                                              holder:[options valueForKey:@"holderName"]
                                                                              number:[options valueForKey:@"cardNumber"]
                                                                         expiryMonth:[options valueForKey:@"month"]
                                                                          expiryYear:[options valueForKey:@"year"]
                                                                                 CVV:[options valueForKey:@"cvv"]
                                                                               error:&error];

    if (error) {
      reject(@"oppwa/card-init", error.localizedDescription, error.code);
    } else {
      OPPTransaction *transaction = [OPPTransaction transactionWithPaymentParams:params];

      [self.provider submitTransaction:transaction completionHandler:^(OPPTransaction * _Nonnull transaction, NSError * _Nullable error) {
        if (transaction.type == OPPTransactionTypeAsynchronous) {
          // Open transaction.redirectURL in Safari browser to complete the transaction
        }  else if (transaction.type == OPPTransactionTypeSynchronous) {
         resolve(transaction);
        } else {
          reject(@"oppwa/transaction", error.localizedDescription, error.code);
          // Handle the error
        }
      }];
      if (error) {
        reject(@"oppwa/card-init", error.localizedDescription, error.code);
      } else {
        resolve([NSNull null]);
      }
    }
}
/**
 * validate number
 * @return
 */
RCT_EXPORT_METHOD(isValidNumber:
            options:
            (NSDictionary *) options
            resolver:
            (RCTPromiseResolveBlock) resolve
            rejecter:
            (RCTPromiseRejectBlock) reject) {

        
        if (![OPPCardPaymentParams isNumberValid:[options valueForKey:@"cardNumber"] forPaymentBrand:@"VISA"]) {
            resolve([NSNull null]);
        }
        else {
           reject(@"oppwa/card-invalid", @"The card number is invalid.", nil);
        }
}

+ (BOOL)requiresMainQueueSetup
{
    return YES;
}

@end