//
//  OPPSecurityPolicy.h
//  OPPWAMobile
//
//  Created by Teploukhova, Alisa on 10/02/17.
//  Copyright © 2017 ACI Worldwide. All rights reserved.
//

#import <Foundation/Foundation.h>

/// An enumeration for the possible modes of security policy.
typedef NS_ENUM(NSInteger, OPPSecurityPolicyMode) {
    /// Device authentication is required to complete payment. Payment method won't be displayed in the list if neither Touch ID nor passcode are set.
    OPPSecurityPolicyModeDeviceAuthRequired,
    /// Require device authentication only if Touch ID or passcode are set.
    OPPSecurityPolicyModeDeviceAuthRequiredIfAvailable,
    /// Shopper don't have to provide Touch ID or passcode to complete payment.
    OPPSecurityPolicyModeDeviceAuthNotRequired
};

/**
 Class which is used to apply security policy mode for the set of payment methods.
 */
NS_ASSUME_NONNULL_BEGIN
@interface OPPSecurityPolicy : NSObject

/// @name Initialization methods

/**
 Creates security policy for the list of payment methods with specified mode.
 @param paymentBrands List of payment brands. Note that Apple Pay will be ignored, because device authentication is mandatory for this payment method.
 @param mode Mode of security policy which will be applied to the paymentBrands.
 @see OPPSecurityPolicyMode.
 */
+ (instancetype)securityPolicyWithPaymentBrands:(NSArray<NSString *> *)paymentBrands mode:(OPPSecurityPolicyMode)mode;

/**
 Creates security policy for tokens with specified mode.
 @param mode Mode of security policy which will be applied for all tokens.
 */
+ (instancetype)securityPolicyForTokensWithMode:(OPPSecurityPolicyMode)mode;

- (instancetype)init NS_UNAVAILABLE;


/// @name Properties

/**
 The mode of security policy.
 @see OPPSecurityPolicyMode
 */
@property (nonatomic, readonly) OPPSecurityPolicyMode mode;

/**
 The list of payment brands.
 */
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *paymentBrands;

/**
 The list of payment methods.
 @deprecated Use paymentBrands instead
 @see paymentBrands
 */
@property (nonatomic, copy, readonly, nullable) NSArray<NSString *> *paymentMethods DEPRECATED_ATTRIBUTE;

/**
 The flag that defines whether mode is applied to paymentMethods or to all tokens.
 */
@property (nonatomic, readonly, getter=isTokenPolicy) BOOL tokenPolicy;

@end

@interface OPPSecurityPolicy (Deprecated)
/**
 Creates security policy for the list of payment methods with specified mode.
 @param paymentMethods List of payment methods. Note that Apple Pay will be ignored, because device authentication is mandatory for this payment method.
 @param mode Mode of security policy which will be applied to the paymentMethods.
 @deprecated Use +securityPolicyWithPaymentBrands:mode: instead
 @see +securityPolicyWithPaymentBrands:mode:
 @see OPPSecurityPolicyMode.
 */
+ (instancetype)securityPolicyWithPaymentMethods:(NSArray<NSNumber *> *)paymentMethods mode:(OPPSecurityPolicyMode)mode DEPRECATED_MSG_ATTRIBUTE("- Use +securityPolicyWithPaymentBrands:mode: instead.");
@end
NS_ASSUME_NONNULL_END
