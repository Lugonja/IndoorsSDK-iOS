//
//  IVAnnotationDetailsView.h
//  iViewer
//
//  Created by Mina Haleem on 24.03.13.
//  Copyright (c) 2013 Mina Haleem. All rights reserved.
//

#import <UIKit/UIKit.h>

#define RGB(hex) [UIColor colorWithRed:(hex >> 16)/255.0 green:((hex >> 8) & 0xFF)/255.0 blue:(hex & 0xFF)/255.0 alpha:1]


@interface ISAnnotationDetailsView : UIView
@property (nonatomic, strong, readonly) UILabel *textLabel;
@property (nonatomic, strong, readonly) UILabel *detailTextLabel;
@property (nonatomic, copy) dispatch_block_t callButtonTappedBlock;
@property (nonatomic, assign) BOOL callButtonEnabled;
@end
