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

/// An enumeration for the possible payment methods.
typedef NS_ENUM(NSInteger, OPPCheckoutPaymentMethod) {
    /// VISA payment system.
    OPPCheckoutPaymentMethodVISA,
    /// MasterCard payment system.
    OPPCheckoutPaymentMethodMasterCard,
    /// AMEX payment system.
    OPPCheckoutPaymentMethodAMEX,
    /// Diners Club payment system.
    OPPCheckoutPaymentMethodDinersClub,
    /// Discover payment system.
    OPPCheckoutPaymentMethodDiscover,
    /// UnionPay payment system.
    OPPCheckoutPaymentMethodUnionPay,
    /// JCB payment system.
    OPPCheckoutPaymentMethodJCB,
    /// SEPA Direct Debit payment system.
    OPPCheckoutPaymentMethodDirectDebitSEPA,
    /// BOLETO payment system.
    OPPCheckoutPaymentMethodBOLETO,
    /// Apple Pay payment system.
    OPPCheckoutPaymentMethodApplePay,
    /// SOFORT Banking payment system.
    OPPCheckoutPaymentMethodSOFORTBanking,
    /// PayPal payment system.
    OPPCheckoutPaymentMethodPayPal,
    /// Alipay payment system.
    OPPCheckoutPaymentMethodAlipay,
    /// China UnionPay (UPOP) payment system.
    OPPCheckoutPaymentMethodChinaUnionPay,
    /// IDEAL payment system.
    OPPCheckoutPaymentMethodIDEAL,
    /// Unsupported payment system.
    OPPCheckoutPaymentMethodUnsupported
};
