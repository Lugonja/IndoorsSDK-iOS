//
//  IVMapRoutingView.h
//  iViewer
//
//  Created by Mina Haleem on 29.04.13.
//  Copyright (c) 2013 Mina Haleem. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "ISMapOverlay.h"

@interface ISRouteMapOverlay : ISMapOverlay

- (instancetype)initWithPath:(NSArray *)path color:(UIColor *)color lineWidth:(CGFloat)lineWidth floorLevel:(NSInteger)floorLevel;

@end
