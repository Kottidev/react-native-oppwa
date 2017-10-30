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

/// An enumeration for the various payment brands.
typedef NS_ENUM(NSInteger, OPPPaymentParamsBrand) {
    /// VISA card payment brand.
    OPPPaymentParamsBrandVISA,
    /// MasterCard payment brand.
    OPPPaymentParamsBrandMasterCard,
    /// American Express card brand.
    OPPPaymentParamsBrandAMEX,
    /// Diners Club card brand.
    OPPPaymentParamsBrandDinersClub,
    /// Discover card brand.
    OPPPaymentParamsBrandDiscover,
    /// UnionPay (ExpressPay) card brand.
    OPPPaymentParamsBrandUnionPay,
    /// JCB card brand.
    OPPPaymentParamsBrandJCB,
    
    /// SEPA direct debit payment brand.
    OPPPaymentParamsBrandDirectDebitSEPA,
    /// SOFORT banking payment brand.
    OPPPaymentParamsBrandSOFORTBanking,
    /// BOLETO payment brand.
    OPPPaymentParamsBrandBOLETO,
    /// IDEAL payment brand.
    OPPPaymentParamsBrandIDEAL,
    
    /// Apple pay payment brand.
    OPPPaymentParamsBrandApplePay,
    
    /// PayPal payment brand.
    OPPPaymentParamsBrandPayPal,
    /// China UnionPay brand.
    OPPPaymentParamsBrandChinaUnionPay,
    
    /// Alipay payment brand.
    OPPPaymentParamsBrandAlipay,
    
    /// Unsupported payment brand.
    OPPPaymentParamsBrandUnknown
};

/**
 Class to represent a set of parameters needed for performing an e-commerce transaction.
 */

NS_ASSUME_NONNULL_BEGIN
@interface OPPPaymentParams : NSObject

/** @name Initialization */

- (instancetype)init NS_UNAVAILABLE;

/**
 Creates an object representing a payment transaction.
 
 @param checkoutID The checkout ID of the transaction. Must be not nil or empty.
 @param paymentBrand The payment brand of the transaction.
 @param error The error that occurred while validating payment parameters. See code attribute (OPPErrorCode) and NSLocalizedDescription to identify the reason of failure.
 @return Returns an object representing a payment transaction, and nil if parameters are invalid.
 */
+ (nullable instancetype)paymentParamsWithCheckoutID:(NSString *)checkoutID paymentBrand:(NSString *)paymentBrand error:(NSError **)error;

/**
 Creates an object representing a payment transaction.
 
 @param checkoutID The checkout ID of the transaction. Must be not nil or empty.
 @param paymentBrand The payment brand of the transaction.
 @param error The error that occurred while validating payment parameters. See code attribute (OPPErrorCode) and NSLocalizedDescription to identify the reason of failure.
 @return Returns an object representing a payment transaction, and nil if parameters are invalid.
 */
- (nullable instancetype)initWithCheckoutID:(NSString *)checkoutID paymentBrand:(NSString *)paymentBrand error:(NSError **)error NS_DESIGNATED_INITIALIZER;

/** @name Properties */

/** A property that can be set with a value from initial checkout request (mandatory). This value is required in the next steps. */
@property (nonatomic, copy, readonly) NSString *checkoutID;

/**
 The payment brand of the transaction.
 */
@property (nonatomic, copy, readonly) NSString *paymentBrand;

/** 
 Method of payment for the request.
 @deprecated Use paymentBrand instead
 @see paymentBrand
 */
@property (nonatomic, readonly) OPPPaymentParamsBrand brand DEPRECATED_ATTRIBUTE;

/**
 Dictionary of custom parameters that will be sent to the server.
 */
@property (nonatomic, copy, readonly) NSDictionary<NSString *, NSString *> *customParams;

/** @name Custom parameters methods */

/**
 Method to add custom parameter that will be sent to the server.
 @param name Name should be prepended with SHOPPER_*, e.g. SHOPPER_customerId. Expected string that matches regex SHOPPER_[0-9a-zA-Z._]{3,64}.
 @param value Any string no longer than 2048 characters.
 @return Returns YES if name and value are valid and parameter is successfully saved, otherwise NO.
 */
- (BOOL)addCustomParamWithName:(NSString *)name value:(NSString *)value;

/**
 Method to remove record from the dictionary of custom parameters.
 @param name Parameter name.
 */
- (void)removeCustomParamWithName:(NSString *)name;

/** @name Helper methods */

/**
 Helper method to mask sensitive payment details such as card number, CVV and etc.
 */
- (void)mask;

@end
NS_ASSUME_NONNULL_END
