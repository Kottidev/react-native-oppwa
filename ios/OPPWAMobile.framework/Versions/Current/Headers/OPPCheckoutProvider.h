//
// Copyright (c) 2017 by ACI Worldwide, Inc.
// All rights reserved.
//
// This software is the confidential and proprietary information
// of ACI Worldwide Inc ("Confidential Information"). You shall
// not disclose such Confidential Information and shall use it
// only in accordance with the terms of the license agreement
// you entered with ACI Worldwide Inc.
//

#import <Foundation/Foundation.h>
@class OPPPaymentProvider;
@class OPPTransaction;
@class OPPCheckoutSettings;
#import "OPPCheckoutPaymentMethod.h"

/**
 Abstract class for displaying an in-App payment page.
 */
NS_ASSUME_NONNULL_BEGIN
@interface OPPCheckoutProvider : NSObject

/** @name Initialization */

/**
 Factory method to generate an OPPCheckoutProvider used for displaying an in-App payment pages.
 @param provider The OPPPaymentProvider which is used for performing the transaction once all the data from the user is collected.
 @param checkoutID The checkout Id of the transaction. Must be not nil or empty.
 @param settings The OPPCheckoutSettings used for these payment pages. These settings are provided to customize the appearance and functionality of the payment pages. If nil, default settings will be created.

 @return Returns an OPPCheckoutProvider for displaying in-App payment pages. Returns nil if provider or checkoutID are not set.
 */
+ (nullable instancetype)checkoutProviderWithPaymentProvider:(OPPPaymentProvider *)provider checkoutID:(NSString *)checkoutID settings:(nullable OPPCheckoutSettings *)settings;

/**
 Designated initializer method to generate an OPPCheckoutProvider used for displaying an in-App payment pages.
 @param provider The OPPPaymentProvider which is used for performing the transaction once all the data from the user is collected.
 @param checkoutID The checkout Id of the transaction. Must be not nil or empty.
 @param settings The OPPCheckoutSettings used for these payment pages. These settings are provided to customize the appearance and functionality of the payment pages. If nil, default settings will be created.
 @return Returns an OPPCheckoutProvider for displaying in-App payment pages. Returns nil if provider or checkoutID are not set.
 */
- (nullable instancetype)initWithPaymentProvider:(OPPPaymentProvider *)provider checkoutID:(NSString *)checkoutID settings:(nullable OPPCheckoutSettings *)settings;

/** @name Presenting checkout */

/**
 Opens an in-App payment page for collecting user input and submitting a transaction. First the list of payment methods from the checkout settings will be displayed.
 @param completionHandler A block executed when the transaction is completed. You need to send the request to your server to get the transaction status.
 @param paymentBrandSelectedHandler A block executed when the shopper selected payment brand. You need to obtain a new checkout Id if the selected payment brand requires another payment type and return the value to SDK or nil in case of error using completion block.
 @param cancelHandler A block executed if the user closes the payment page prematurely.
 */
- (void)presentCheckoutForSubmittingTransactionCompletionHandler:(void (^)(OPPTransaction * _Nullable transaction, NSError * _Nullable error))completionHandler
                                     paymentBrandSelectedHandler:(void (^ _Nullable )(NSString * _Nonnull paymentBrand, void (^completion)(NSString * _Nullable checkoutID)))paymentBrandSelectedHandler
                                                   cancelHandler:(void (^ _Nullable )())cancelHandler;

/**
 Opens an in-App payment page for collecting user input and submitting a transaction.
 Payment form for the choosen payment method will be opened. If no user input is required in app (e.g. PayPal), shopper will be redirected directly to the issuer web page.
 @param paymentBrand The payment brand for transaction.
 @param loadingHandler A block executed whenever SDK sends request to the server or receives the response. You can start or stop loading animation based on inProgress parameter.
 @param completionHandler A block executed when the transaction is completed. You need to send the request to your server to get the transaction status.
 @param cancelHandler A block executed if the user closes the payment page prematurely.
 */
- (void)presentCheckoutWithPaymentBrand:(NSString *)paymentBrand
                         loadingHandler:(void (^ _Nullable )(BOOL inProgress))loadingHandler
                      completionHandler:(void (^)(OPPTransaction * _Nullable transaction, NSError * _Nullable error))completionHandler
                          cancelHandler:(void (^ _Nullable )())cancelHandler;

/**
 Closes the in-App payment page. The delegate is not informed if this method is being called.
 @param animated Specifies whether the payment page should be dismissed using an animation or immediately without an animation.
 @param completion The completion handler, if provided, will be invoked after the checkout screen will be dismissed.
 */
- (void)dismissCheckoutAnimated:(BOOL)animated completion: (void (^ __nullable)(void))completion;

@end

@interface OPPCheckoutProvider (Deprecated)

/**
 Opens an in-App payment page for collecting user input and submitting a transaction. First the list of payment methods from the checkout settings will be displayed.
 @param completionHandler A block executed when the transaction is completed. You need to send the request to your server to get the transaction status.
 @param cancelHandler A block executed if the user closes the payment page prematurely.
 @deprecated Use -presentCheckoutForSubmittingTransactionCompletionHandler:paymentBrandSelectedHandler:cancelHandler: instead
 @see -presentCheckoutForSubmittingTransactionCompletionHandler:paymentBrandSelectedHandler:cancelHandler:
 */
- (void)presentCheckoutForSubmittingTransactionCompletionHandler:(void (^)(OPPTransaction * _Nullable transaction, NSError * _Nullable error))completionHandler
                                                   cancelHandler:(void (^ _Nullable )())cancelHandler DEPRECATED_MSG_ATTRIBUTE("- Use -presentCheckoutForSubmittingTransactionCompletionHandler:paymentBrandSelectedHandler:cancelHandler: instead.");

/**
 Opens an in-App payment page for collecting user input and submitting a transaction. First the list of payment methods from the checkout settings will be displayed.
 @param completionHandler A block executed when the transaction is completed. You need to send the request to your server to get the transaction status.
 @param paymentMethodSelectedHandler A block executed when the shopper selected payment brand. You need to obtain a new checkout Id if the selected payment brand requires another payment type and return the value to SDK or nil in case of error using completion block.
 @param cancelHandler A block executed if the user closes the payment page prematurely.
 @deprecated Use -presentCheckoutForSubmittingTransactionCompletionHandler:paymentBrandSelectedHandler:cancelHandler: instead
 @see -presentCheckoutForSubmittingTransactionCompletionHandler:paymentBrandSelectedHandler:cancelHandler:
 */
- (void)presentCheckoutForSubmittingTransactionCompletionHandler:(void (^)(OPPTransaction * _Nullable transaction, NSError * _Nullable error))completionHandler
                                    paymentMethodSelectedHandler:(void (^ _Nullable )(OPPCheckoutPaymentMethod paymentMethod, void (^completion)(NSString * _Nullable checkoutID)))paymentMethodSelectedHandler
                                                   cancelHandler:(void (^ _Nullable )())cancelHandler DEPRECATED_MSG_ATTRIBUTE("- Use -presentCheckoutForSubmittingTransactionCompletionHandler:paymentBrandSelectedHandler:cancelHandler: instead.");

/**
 Opens an in-App payment page for collecting user input and submitting a transaction.
 Payment form for the choosen payment method will be opened. If no user input is required in app (e.g. PayPal), shopper will be redirected directly to the issuer web page.
 @param paymentMethod The payment method for transaction.
 @param loadingHandler A block executed whenever SDK sends request to the server or receives the response. You can start or stop loading animation based on inProgress parameter.
 @param completionHandler A block executed when the transaction is completed. You need to send the request to your server to get the transaction status.
 @param cancelHandler A block executed if the user closes the payment page prematurely.
 @deprecated Use -presentCheckoutWithPaymentBrand:loadingHandler:completionHandler:cancelHandler: instead
 @see -presentCheckoutWithPaymentBrand:loadingHandler:completionHandler:cancelHandler:
 */
- (void)presentCheckoutWithPaymentMethod:(OPPCheckoutPaymentMethod)paymentMethod
                          loadingHandler:(void (^ _Nullable )(BOOL inProgress))loadingHandler
                       completionHandler:(void (^)(OPPTransaction * _Nullable transaction, NSError * _Nullable error))completionHandler
                           cancelHandler:(void (^ _Nullable )())cancelHandler DEPRECATED_MSG_ATTRIBUTE("- Use -presentCheckoutWithPaymentBrand:loadingHandler:completionHandler:cancelHandler: instead.");
@end
NS_ASSUME_NONNULL_END
