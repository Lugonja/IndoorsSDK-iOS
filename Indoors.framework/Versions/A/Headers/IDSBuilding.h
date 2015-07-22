//
//  Building.h
//  Indoors
//
//  Created by Gerhard Zeissl on 02.12.12.
//  Copyright (c) 2012 Indoors. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDSMap.h"
#import "IDSFloor.h"
#import "IDSZone.h"

typedef NS_OPTIONS(NSUInteger, IDSBuildingSource) {
    IDSBuildingSourceCache = 1 << 0,
    IDSBuildingSourceBundle = 1 << 1,
    IDSBUildingSourceOnline = 1 << 2
};

/**
 Model class representing a building.
 
 Note: Buildings retrieved with getOnlineBuildings will not be fully
 initialized with all their properties. Floor or tile properties will not be set as
 they are intended to show all available buildings.

 Buildings retrieved from getBuilding will have all
 their members set.
 */
@interface IDSBuilding : NSObject

@property (nonatomic) IDSBuildingSource source;
@property (nonatomic) NSMutableDictionary *floors;
@property (nonatomic) NSString *name;
@property (nonatomic) NSString *buildingDescription;
@property (nonatomic) NSInteger latOrigin, lonOrigin;
@property (nonatomic) float rotation;
@property (nonatomic) NSUInteger buildingID;
@property (nonatomic) NSString *databasePath;

- (int)getInitialFloorLevel;
- (IDSFloor *)floorAtLevel:(NSInteger)floorLevel;
- (IDSFloor *)getFloorById:(long)floorId;
- (IDSZone *)getZoneById:(long)zoneId;

@end
