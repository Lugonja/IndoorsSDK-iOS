//
//  IDSBuildingManager.h
//  Indoors
//
//  Created by Dominik Hofer on 06/07/15.
//  Copyright (c) 2015 Indoors. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDSBuilding;

@interface IDSBuildingManager : NSObject

@property (readonly, copy) NSSet *loadedBuildings;

- (void)loadBuildingWithId:(NSUInteger)buildingId
                  progress:(void (^)(double progress, NSUInteger currentStep, NSUInteger totalSteps, NSString *phase))progress
                completion:(void (^)(IDSBuilding *building, NSError *error))completion;

- (void)unloadBuilding:(IDSBuilding *)building;
- (void)unloadAllBuildings;
- (void)cancelLoadBuilding;

@end
