//
//  PSPDFKitPlugin.h
//  PSPDFKit - Implementation
//
//  Created by Shnoudi on 4/12/14.
//  Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//

#import <Cordova/CDVPlugin.h>
#import <PSPDFKit/PSPDFKit.h>

@interface PSPDFKitPlugin : CDVPlugin {
    NSString* callbackId;
}

@property (nonatomic, copy) NSString* callbackId;

- (void) viewPDF:(CDVInvokedUrlCommand*)command;
@end