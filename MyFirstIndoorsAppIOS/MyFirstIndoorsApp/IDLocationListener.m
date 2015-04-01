//
//  IDLocationListener.m
//  MyFirstIndoorsApp
//
//  Created by Dominik Hofer on 22/01/15.
//  Copyright (c) 2015 Indoors GmbH. All rights reserved.
//

#import "IDLocationListener.h"

@implementation IDLocationListener

- (void)positionUpdated:(IDSCoordinate *)userPosition
{
    NSString *positionText = [NSString stringWithFormat:@"\nLISTENER:\nx=%ld\ny = %ld\nz = %ld\nacc = %ld", (long)userPosition.x, (long)userPosition.y, (long)userPosition.z, (long)userPosition.accuracy];
    NSLog(positionText);
}

@end
