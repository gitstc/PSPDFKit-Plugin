//
//  PSPDFKitPlugin.m
//  PSPDFKit - Implementation
//
//  Created by Shnoudi on 4/12/14.
//  Copyright (c) 2014 ___FULLUSERNAME___. All rights reserved.
//

#import <Cordova/CDV.h>
#import "PSPDFKitPlugin.h"

@interface PSPDFKitPlugin()

@end

@implementation PSPDFKitPlugin

@synthesize callbackId;

- (void) viewPDF:(CDVInvokedUrlCommand *)command{
    self.callbackId = command.callbackId;
    
    @try{
        NSString* pdfURL = [command argumentAtIndex:0];
        NSLog(@"Opening Document: %@", pdfURL);
        NSURL* documentURL = [self pdfFileURLWithPath:pdfURL];
        PSPDFDocument *document = [PSPDFDocument documentWithURL:documentURL];
        PSPDFViewController *pdfController = [[PSPDFViewController alloc] initWithDocument:document
          configuration:[PSPDFConfiguration configurationWithBuilder:^(PSPDFConfigurationBuilder *builder) {
            builder.thumbnailBarMode = PSPDFThumbnailBarModeScrollable;
            builder.pageLabelEnabled = NO;
        }]];
        UINavigationController *navController = [[UINavigationController alloc] initWithRootViewController:pdfController];
        [self.viewController presentViewController:navController animated:YES completion:NULL];
    }
    @catch(NSException *ex){
        CDVPluginResult* result = [CDVPluginResult resultWithStatus: CDVCommandStatus_ERROR messageAsString:[NSString stringWithFormat:@"Exception: %@",ex]];
        [self.webView stringByEvaluatingJavaScriptFromString:[result toErrorCallbackString: self.callbackId]];
    }
}

- (NSURL *)pdfFileURLWithPath:(NSString *)path
{
    if (path) {
        path = [path stringByExpandingTildeInPath];
        return [NSURL fileURLWithPath:path];
    }
    return nil;
}

@end