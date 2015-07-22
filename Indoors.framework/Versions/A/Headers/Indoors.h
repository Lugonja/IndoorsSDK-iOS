#import <Foundation/Foundation.h>

#import "IndoorsBuilder.h"
#import "IndoorsError.h"
#import "IndoorsErrorCode.h"
#import "IndoorsDelegate.h"
#import "IDSBuilding.h"
#import "IDSCoordinate.h"
#import "IDSContext.h"
#import "IDSFloor.h"
#import "IDSMap.h"
#import "IDSTile.h"
#import "IDSDefaultMap.h"
#import "IDSZone.h"
#import "IDSZonePoint.h"
#import "IndoorsBuilder.h"
#import "IDSNetwork.h"
#import "IDSServiceAuthentication.h"
#import "IndoorsParameters.h"
#import "IndoorsLocationListener.h"
#import "IDSLogLevels.h"
#import "IDSBuildingManager.h"

@class IDSCoordinate;

@interface Indoors : NSObject

+ (Indoors *)instance;

/**
 @brief Initializes indoo.rs-SDK
 @discussion
 Initialize indoo.rs instance.
 Use given licenseKey to authenticate to indoo.rs service.
 OnSuccess call delegate IndoorsServiceDelegate(connected)
 OnFail call delegate IndoorsServiceDelegate(onError:)
 
 @param licenseKey Your indoo.rs API key
 @param serviceDelegate Service delegate to be called on success or failure
 
 @result indoo.rs instance - You should not use it to call any API, instead use the shared instance
 */
- (Indoors *)initWithLicenseKey:(NSString *)licenseKey andServiceDelegate:(id<IndoorsServiceDelegate>)serviceDelegate;

- (void)setLogLevel:(IDSLogLevel)level;

/*!
 validates licenseKey passed to initWithLicenseKey:andServiceDelegate
 */
- (void)validateLicenseKeyWithDelegate:(id<IDSServiceAuthenticationDelegate>)delegate;

/*!
 @discussion
 Register location listener to recieve any location updates.
 
 @param listner 
 IndoorsLocationAdapter instance to be added as listener
 */
- (void)registerLocationListener:(id<IndoorsLocationListener>)listener;

/*!
 @discussion
 Remove location listener, you should remove your listener before releasing it.
 
 @param listner 
 IndoorsLocationAdapter instance to be removed from list of existing listeners if exists.
 */
- (void)removeLocationListener:(id<IndoorsLocationListener>)listener;

- (void)setParameter:(IndoorsParameterValue)value forKey:(IndoorsParameterKey)key;
- (void)setParameterObject:(id)value forKey:(IndoorsParameterKey)key;

- (void)initializeLocalizationWithBuilding:(IDSBuilding*)building success:(void (^)())success;
- (void)stopLocalization;
- (void)startLocalization;

- (void)getBuilding:(IDSBuilding *)building forRequestDelegate:(id<LoadingBuildingDelegate>)delegate;

- (void)getOnlineBuildings:(id<OnlineBuildingDelegate>)onlineBuildingDelegate;

- (void)routeFromLocation:(IDSCoordinate *)from toLocation:(IDSCoordinate *)to delegate:(id<RoutingDelegate>)routingDelegate;

- (IDSCoordinate *)snapPosition:(IDSCoordinate *)position toRoute:(NSArray *)path;

- (void)enableEvaluationMode:(BOOL)isEvaluationModeEnabled;

- (void)passLocationToLocator:(IDSCoordinate *)location;

@end
