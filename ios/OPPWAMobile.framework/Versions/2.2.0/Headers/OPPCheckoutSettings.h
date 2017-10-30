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
#import "OPPCheckoutPaymentMethod.h"
#import <PassKit/PassKit.h>
@class OPPCheckoutTheme;
@class OPPSecurityPolicy;

/// An enumeration for the possible store payment details modes.
typedef NS_ENUM(NSInteger, OPPCheckoutStorePaymentDetailsMode) {
    /// Always store payment details for future use.
    OPPCheckoutStorePaymentDetailsModeAlways,
    /// Display the option to prompt the user permissions to store payment details for future use.
    OPPCheckoutStorePaymentDetailsModePrompt,
    /// Never store payment details.
    OPPCheckoutStorePaymentDetailsModeNever
};

/// An enumeration for the possible modes to skip CVV check.
typedef NS_ENUM(NSInteger, OPPCheckoutSkipCVVMode) {
    /// Always request CVV for card payments.
    OPPCheckoutSkipCVVModeNever,
    /// Skip CVV check only for payments by stored cards.
    OPPCheckoutSkipCVVModeForStoredCards,
    /// Always skip CVV check. CVV field won't be displayed in card payment forms.
    OPPCheckoutSkipCVVModeAlways
};

/**
 Class which encapsulates settings for the built-in in-App payment page. Use this to customize both the visual elements of the payment pages as well as functionality. This includes changing colors and texts, defining payment methods.
 */
NS_ASSUME_NONNULL_BEGIN
@interface OPPCheckoutSettings : NSObject

/// @name Properties

/**
 The custom theme for the payment forms. Default is OPPCheckoutThemeStyleLight.
 @see OPPCheckoutThemeStyle
 */
@property (nonatomic, readonly) OPPCheckoutTheme *theme;

/**
 The description to show on the payment page above the total amount.
 @deprecated The property is no longer used
 */
@property (nonatomic, copy, nullable) NSString *paymentTitle DEPRECATED_ATTRIBUTE;

/**
 The custom URL scheme for your app. This must be configured if your app integrates a payment option that may switch to either Mobile Safari or to another app to finish the payment authorization workflow.
 */
@property (nonatomic, copy) NSString *schemeURL;

/**
 The list of payment brands to be shown.
 */
@property (nonatomic, copy) NSArray<NSString *> *paymentBrands;

/**
 The payment methods to be shown. Expected an NSArray of NSNumbers representing different OPPCheckoutPaymentMethod enums.
 @deprecated Use paymentBrands instead
 @see paymentBrands
 */
@property (nonatomic, copy) NSArray<NSNumber *> *paymentMethods DEPRECATED_ATTRIBUTE;

/** 
 A constant that specifies the store payment details mode. Default is OPPCheckoutStorePaymentDetailsModeNever.
 @see OPPCheckoutStorePaymentDetailsMode
 */
@property (nonatomic) OPPCheckoutStorePaymentDetailsMode storePaymentDetails;

/**
 A constant that specifies whether request CVV or not. Default is OPPCheckoutSkipCVVModeNever.
 @see OPPCheckoutSkipCVVMode
 */
@property (nonatomic) OPPCheckoutSkipCVVMode skipCVV;

/**
 Set of security policies to confirm payment. 
 Increase security for tokens or specific payment methods with Touch ID or passcode.
 @see OPPSecurityPolicy
 */
@property (nonatomic, copy, nullable) NSArray<OPPSecurityPolicy *> *securityPolicies;

/**
 The language used for language specific labels in ISO 639-1 language identifier.
 Currently English (en), German (de), Russian (ru), Thai (th) and Japanese (ja) are available.
 If the language is not supported English will be used.
 If language is nil, app wil use the first supported language from language settings.
 */
@property (nonatomic, copy, nullable) NSString *language;

/** Encapsulates a request for payment, including information about payment processing capabilities and the payment amount. */
@property (nonatomic, nullable) PKPaymentRequest *applePayPaymentRequest;

/** Sets the country to be used for Klarna checkout in ISO 3166-1 alpha-2 country identifier. By default, uses countryCode from device locale if supported. Otherwise, use DE. */
@property (nonatomic, copy, nullable) NSString *klarnaCountry;

/** Sets the fee to be used for the "Billing agreement" link during a Klarna Invoice checkout. */
@property (nonatomic, nullable) NSDecimalNumber *klarnaInvoiceFee;

/** Sets the fee to be used for the "Read more" link during a Klarna Installments checkout. */
@property (nonatomic, nullable) NSDecimalNumber *klarnaInstallmentsFee;

/**
 A flag that specifies whether show IBAN field on the Giropay payment form or not. Default is NO.
 */
@property (nonatomic, getter=isIBANRequired) BOOL IBANRequired;

@end
NS_ASSUME_NONNULL_END
