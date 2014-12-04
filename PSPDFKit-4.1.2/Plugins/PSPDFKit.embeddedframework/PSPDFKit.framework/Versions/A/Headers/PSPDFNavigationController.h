//
//  PSPDFNavigationController.h
//  PSPDFKit
//
//  Copyright (c) 2013-2014 PSPDFKit GmbH. All rights reserved.
//
//  THIS SOURCE CODE AND ANY ACCOMPANYING DOCUMENTATION ARE PROTECTED BY INTERNATIONAL COPYRIGHT LAW
//  AND MAY NOT BE RESOLD OR REDISTRIBUTED. USAGE IS BOUND TO THE PSPDFKIT LICENSE AGREEMENT.
//  UNAUTHORIZED REPRODUCTION OR DISTRIBUTION IS SUBJECT TO CIVIL AND CRIMINAL PENALTIES.
//  This notice may not be removed from this file.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, PSPDFPersistentCloseButtonMode) {
    PSPDFPersistentCloseButtonModeNone, /// No persistent close button.
    PSPDFPersistentCloseButtonModeLeft, /// Persistent close button on the left.
    PSPDFPersistentCloseButtonModeRight /// Persistent close button on the right.
};

/// Simple subclass that forwards following iOS 6+ rotation methods to the top view controller:
/// `shouldAutorotate`, `supportedInterfaceOrientations`, `preferredInterfaceOrientationForPresentation:`.
@interface PSPDFNavigationController : UINavigationController <UINavigationControllerDelegate>

// Forward the iOS 6+ rotation method to the visible view controller. Defaults to YES.
@property (nonatomic, assign, getter=isRotationForwardingEnabled) BOOL rotationForwardingEnabled;

// Allows showing a persistent close button. Defaults to `PSPDFPersistentCloseButtonModeNone`.
@property (nonatomic, assign) PSPDFPersistentCloseButtonMode persistentCloseButtonMode;

// The close button if `persistentCloseButtonMode` is set.
// If none is set, a default system close button will be created.
// Set the button before a VC is pushed to ensure it will be used instead of the auto-generated one.
@property (nonatomic, strong) UIBarButtonItem *persistentCloseButton;

@end