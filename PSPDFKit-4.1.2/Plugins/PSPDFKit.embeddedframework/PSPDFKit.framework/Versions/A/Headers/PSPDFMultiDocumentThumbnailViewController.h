//
//  PSPDFMultiDocumentThumbnailViewController.h
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
#import <Foundation/Foundation.h>
#import "PSPDFThumbnailViewController.h"

// Allows displaying thumbnails for multiple `PSPDFDocuments`.
@interface PSPDFMultiDocumentThumbnailViewController : PSPDFThumbnailViewController

// Designated initializer.
- (instancetype)initWithDocuments:(NSArray *)documents NS_DESIGNATED_INITIALIZER;

// Documents that are currently loaded.
@property (nonatomic, copy) NSArray *documents;

// Whether to show only the first page of each document, or all pages. Defaults to NO.
@property (nonatomic, assign) BOOL firstPageOnly;

@end