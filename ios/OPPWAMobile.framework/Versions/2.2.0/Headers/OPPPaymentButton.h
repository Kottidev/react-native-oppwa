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

#import <UIKit/UIKit.h>
#import "OPPCheckoutPaymentMethod.h"

/**
 Class that extends UIButton in order to esily integrate separate payment methods in the app.
 
 By default button contains appropriate logo if a valid payment method is set. Button can be fully customized as common UIButton.
 
 [OPPCheckoutProvider presentCheckoutWithPaymentMethod:loadingHandler:completionHandler:cancelHandler:] is recommended to use in button action method to create and submit a transaction.
 */
NS_ASSUME_NONNULL_BEGIN
@interface OPPPaymentButton : UIButton

/** @name Initialization methods */

/**
 Creates and returns payment button initialized with the payment brand.
 @param paymentBrand Payment brand for the transaction.
 */
+ (instancetype)paymentButtonWithPaymentBrand:(NSString *)paymentBrand;

/**
 Creates and returns payment button initialized with the payment method.
 @param paymentBrand Payment brand for the transaction.
 */
- (instancetype)initWithPaymentBrand:(NSString *)paymentBrand;

/** @name Properties */

/**
 Payment brand for the transaction that is used to display an appropriate logo.
 */
@property (nonatomic, copy) NSString *paymentBrand;

/**
 Payment method for the transaction that is used to display an appropriate logo.
 @deprecated Use paymentBrand instead
 @see paymentBrand
 */
@property (nonatomic) OPPCheckoutPaymentMethod paymentMethod DEPRECATED_ATTRIBUTE;

@end

@interface OPPPaymentButton (Deprecated)
/**
 Creates and returns payment button initialized with the payment brand.
 @param paymentMethod Payment method for the transaction.
 @deprecated Use +paymentButtonWithPaymentBrand: instead
 @see +paymentButtonWithPaymentBrand:
 */
+ (instancetype)paymentButtonWithPaymentMethod:(OPPCheckoutPaymentMethod)paymentMethod DEPRECATED_MSG_ATTRIBUTE("- Use +paymentButtonWithPaymentBrand: instead.");

/**
 Creates and returns payment button initialized with the payment method.
 @param paymentMethod Payment method for the transaction.
 @deprecated Use -initWithPaymentBrand: instead
 @see -initWithPaymentBrand:
 */
- (instancetype)initWithPaymentMethod:(OPPCheckoutPaymentMethod)paymentMethod DEPRECATED_MSG_ATTRIBUTE("- Use -initWithPaymentBrand: instead.");
@end
NS_ASSUME_NONNULL_END
