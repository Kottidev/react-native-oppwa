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
@class OPPToken;
@class OPPPaymentBrandsConfig;

/** Class to encapsulate the parameters related to the checkout. */

NS_ASSUME_NONNULL_BEGIN
@interface OPPCheckoutInfo : NSObject

/** @name Properties */

/** The amount of the transaction in the specified currency. */
@property (nonatomic) NSDecimalNumber *amount;

/** ISO 4217 currency code. */
@property (nonatomic, copy) NSString *currencyCode;

/** Tokens related to the checkout. */
@property (nonatomic, copy, nullable) NSArray<OPPToken *> *tokens;

/** Brand configuration parameters from the Server. */
@property (nonatomic, nullable) OPPPaymentBrandsConfig *paymentBrandsConfig;

/** The endpoint where the transaction will be sent to. */
@property (nonatomic, copy) NSString *endpoint;

/** Relative path to get status of transaction. */
@property (nonatomic, copy) NSString *resourcePath;

/** The merchant IDs related to Klarna Invoice and Klarna Installments. */
@property (nonatomic, copy, nullable) NSArray<NSString *> *klarnaMerchantIDs;

/** @name Initialization methods */

/**
 Creates checkout info object from the JSON that can be received from the Server by checkout ID.
 @param JSON A dictionary with parameters received from the Server.
 @return Returns an OPPCheckoutInfo object, or nil if JSON is empty.
 */
+ (nullable instancetype)checkoutInfoFromJSON:(NSDictionary *)JSON;

/**
 Creates checkout info object with provided values.
 @param amount The amount of the transaction in the specified currency.
 @param currencyCode ISO 4217 currency code.
 @param tokens Tokens related to the checkout.
 @param paymentBrandsConfig Brand configuration parameters from the Server.
 @param klarnaMerchantIDs Klarna merchant IDs.
 @return An OPPCheckoutInfo object, or nil if parameters are invalid.
 */
+ (nullable instancetype)checkoutInfoWithAmount:(NSDecimalNumber *)amount
                                   currencyCode:(NSString *)currencyCode
                                         tokens:(nullable NSArray<OPPToken *> *)tokens
                            paymentBrandsConfig:(nullable OPPPaymentBrandsConfig *)paymentBrandsConfig
                              klarnaMerchantIDs:(nullable NSArray<NSString *> *)klarnaMerchantIDs;

/**
 Creates checkout info object with provided values.
 @param amount The amount of the transaction in the specified currency.
 @param currencyCode ISO 4217 currency code.
 @param tokens Tokens related to the checkout.
 @param paymentBrandsConfig Brand configuration parameters from the Server.
 @param klarnaMerchantIDs Klarna merchant IDs.
 @return An OPPCheckoutInfo object, or nil if parameters are invalid.
 */
- (nullable instancetype)initWithAmount:(NSDecimalNumber *)amount
                           currencyCode:(NSString *)currencyCode
                                 tokens:(nullable NSArray<OPPToken *> *)tokens
                    paymentBrandsConfig:(nullable OPPPaymentBrandsConfig *)paymentBrandsConfig
                      klarnaMerchantIDs:(nullable NSArray<NSString *> *)klarnaMerchantIDs;

@end

@interface OPPCheckoutInfo (Deprecated)

/**
 Creates checkout info object with provided values.
 @param amount The amount of the transaction in the specified currency.
 @param currencyCode ISO 4217 currency code.
 @param tokens Tokens related to the checkout.
 @param paymentBrandsConfig Brand configuration parameters from the Server.
 @return An OPPCheckoutInfo object, or nil if parameters are invalid.
 @deprecated Use +checkoutInfoWithAmount:currencyCode:tokens:paymentBrandsConfig:klarnaMerchantIDs: instead
 @see +checkoutInfoWithAmount:currencyCode:tokens:paymentBrandsConfig:klarnaMerchantIDs:
 */
+ (nullable instancetype)checkoutInfoWithAmount:(NSDecimalNumber *)amount
                                   currencyCode:(NSString *)currencyCode
                                         tokens:(nullable NSArray<OPPToken *> *)tokens
                            paymentBrandsConfig:(nullable OPPPaymentBrandsConfig *)paymentBrandsConfig DEPRECATED_MSG_ATTRIBUTE("- Use +checkoutInfoWithAmount:currencyCode:tokens:paymentBrandsConfig:klarnaMerchantIDs: instead.");

/**
 Creates checkout info object with provided values.
 @param amount The amount of the transaction in the specified currency.
 @param currencyCode ISO 4217 currency code.
 @param tokens Tokens related to the checkout.
 @param paymentBrandsConfig Brand configuration parameters from the Server.
 @return An OPPCheckoutInfo object, or nil if parameters are invalid.
 @deprecated Use -initWithAmount:currencyCode:tokens:paymentBrandsConfig:klarnaMerchantIDs: instead
 @see -initWithAmount:currencyCode:tokens:paymentBrandsConfig:klarnaMerchantIDs:
 */
- (nullable instancetype)initWithAmount:(NSDecimalNumber *)amount
                           currencyCode:(NSString *)currencyCode
                                 tokens:(nullable NSArray<OPPToken *> *)tokens
                    paymentBrandsConfig:(nullable OPPPaymentBrandsConfig *)paymentBrandsConfig DEPRECATED_MSG_ATTRIBUTE("- Use -initWithAmount:currencyCode:tokens:paymentBrandsConfig:klarnaMerchantIDs: instead.");
@end
NS_ASSUME_NONNULL_END
