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
#import <UIKit/UIKit.h>

/**
 An enumeration of the in-App payment pages styles.
 There are two ready to use styles and custom style without any pre-defined values.
 */
typedef NS_ENUM(NSInteger, OPPCheckoutThemeStyle) {
    /// Ready to use light style for the payment pages.
    OPPCheckoutThemeStyleLight,
    /// Ready to use dark style for the payment pages.
    OPPCheckoutThemeStyleDark
};

/**
 Class which used to visually style in-App payment pages by customizing colors and fonts.
 There are two ready to use styles. You can leave it as is or override some properties.
 */

NS_ASSUME_NONNULL_BEGIN
@interface OPPCheckoutTheme : NSObject

/// @name Designated initializer

/** 
 Creates and returns theme initialized with the OPPCheckoutThemeStyle.
 @param style Style for checkout screens.
 */
- (instancetype)initWithThemeStyle:(OPPCheckoutThemeStyle)style NS_DESIGNATED_INITIALIZER;

/// @name Properties
/**
 * Predefined style for checkout screens (default is light theme).
 
 @see OPPCheckoutThemeStyle
 */
@property (nonatomic) OPPCheckoutThemeStyle style;

/// @name General colors of the payment pages UI

/**
 * Background color for any views in this theme.
 */
@property (nonatomic) UIColor *primaryBackgroundColor;

/**
 * Text color for any important labels in a view.
 */
@property (nonatomic) UIColor *primaryForegroundColor;

/**
 * Background color for any supplemental views inside a view.
 * @deprecated The property is no longer used
 */
@property (nonatomic) UIColor *secondaryBackgroundColor DEPRECATED_ATTRIBUTE;

/**
 * Text color for any supplementary labels in a view.
 * @deprecated The property is no longer used
 */
@property (nonatomic) UIColor *secondaryForegroundColor DEPRECATED_ATTRIBUTE;

/**
 * The color of the confirmation buttons.
 */
@property (nonatomic) UIColor *confirmationButtonColor;

/**
 * Text color for confirmation buttons.
 */
@property (nonatomic) UIColor *confirmationButtonTextColor;

/**
 * Background color of text fields.
 */
@property (nonatomic) UIColor *textFieldBackroundColor;

/**
 * Input field text color.
 */
@property (nonatomic) UIColor *textFieldTextColor;

/**
 * Placeholder color for text fields.
 */
@property (nonatomic) UIColor *textFieldPlaceholderColor;

/**
 * Color for rendering any error messages or views.
 */
@property (nonatomic) UIColor *errorColor;

/// @name Activity indicator views

/**
 * Indicator view processing style that is shown over primary background color.
 */
@property (nonatomic) UIActivityIndicatorViewStyle activityIndicatorPrimaryStyle;

/**
 * Indicator view processing style that is shown over secondary background color.
 */
@property (nonatomic) UIActivityIndicatorViewStyle activityIndicatorSecondaryStyle;


/// @name Navigation bar customization

/**
 * Navigation bar tint color.
 */
@property (nonatomic) UIColor *navigationBarTintColor;

/**
 * Navigation bar background color.
 */
@property (nonatomic) UIColor *navigationBarBackgroundColor;

/**
 * Text attributes for navigation bar title.
 */
@property (nonatomic, copy) NSDictionary *navigationBarTextAttributes;

/**
 * Text attributes for navigation bar item titles.
 */
@property (nonatomic, copy, nullable) NSDictionary *navigationItemTextAttributes;

/**
 * Custom text for the right bar button in the navigation bar.
 * Localized text is expected. SDK is NOT localizing this text.
 * Default value is "Cancel".
 */
@property (nonatomic, copy, nullable) NSString *cancelBarButtonText;

/**
 * Custom image for the right bar button in the navigation bar.
 * If image is not set text button is shown.
 * @see cancelBarButtonText
 */
@property (nonatomic, nullable) UIImage *cancelBarButtonImage;


/// @name Payment method list customization

/*
 * Tint color for cell on the table view.
 */
@property (nonatomic) UIColor *cellTintColor;

/**
 * Highlighted background color for cell on the table view.
 */
@property (nonatomic) UIColor *cellHighlightedBackgroundColor;

/**
 * Text label highlighted color.
 */
@property (nonatomic) UIColor *cellHighlightedTextColor;

/**
 * Text font for cell on the table view.
 */
@property (nonatomic) UIFont *cellTextFont;


/**
 * Background color of section.
 */
@property (nonatomic) UIColor *sectionBackgroundColor;

/**
 * Text color of section title.
 */
@property (nonatomic) UIColor *sectionTextColor;

/**
 * Font of section title.
 */
@property (nonatomic) UIFont *sectionFont;

/**
 * Color for separator lines.
 */
@property (nonatomic) UIColor *separatorColor;

/*
 * Background color for payment method icons.
 * @deprecated Use paymentBrandIconBackgroundColor instead
 * @see paymentBrandIconBackgroundColor
 */
@property (nonatomic) UIColor *paymentMethodIconBackgroundColor DEPRECATED_ATTRIBUTE;

/*
 * Background color for payment brand icons.
 */
@property (nonatomic) UIColor *paymentBrandIconBackgroundColor;

/*
 * Border color for payment brand icons.
 */
@property (nonatomic) UIColor *paymentBrandIconBorderColor;

/*
 * Background color for stored payment method icons.
 */
@property (nonatomic) UIColor *storedPaymentMethodIconBackgroundColor;

/*
 * Border color for stored payment method icons.
 */
@property (nonatomic) UIColor *storedPaymentMethodIconBorderColor;


/// @name Fonts customization

/**
 * Text font for any important labels in a view.
 */
@property (nonatomic) UIFont *primaryFont;

/**
 * Text font for any other labels in a view.
 */
@property (nonatomic) UIFont *secondaryFont;

/**
 * Text font for amount label.
 * @deprecated The property is no longer used
 */
@property (nonatomic) UIFont *amountLabelFont DEPRECATED_ATTRIBUTE;

/**
 * Text font for confirmation button.
 */
@property (nonatomic) UIFont *confirmationButtonFont;

/**
 * Text font for rendering any error messages.
 */
@property (nonatomic) UIFont *errorFont;

@end
NS_ASSUME_NONNULL_END
