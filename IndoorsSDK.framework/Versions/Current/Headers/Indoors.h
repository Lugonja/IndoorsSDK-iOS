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

/**
 @brief When set to NO, SDK will use cached building instead of trying to downloading newer version from the server. Default value is YES;
 */
@property (nonatomic) BOOL alwaysDownloadNewBuildingVersion;

/**
 @brief Returns the indoo.rs SDK version as a string.
 */
+ (NSString *)versionInfo;

+ (Indoors *)instance;

/**
 @brief Initializes indoo.rs-SDK.
 
 @param licenseKey Your indoo.rs API key.
 @param serviceDelegate Service delegate to be called on success or failure.
 
 @result indoo.rs instance - You should not use it to call any API, instead use the shared instance.
 */
- (Indoors *)initWithLicenseKey:(NSString *)licenseKey andServiceDelegate:(id<IndoorsServiceDelegate>)serviceDelegate;

- (void)setLogLevel:(IDSLogLevel)level;

/**
 @brief Validates licenseKey passed to initWithLicenseKey:andServiceDelegate.
 */
- (void)validateLicenseKeyWithDelegate:(id<IDSServiceAuthenticationDelegate>)delegate;

/**
 @brief Register location listener to recieve location updates.
 */
- (void)registerLocationListener:(id<IndoorsLocationListener>)listener;

/**
 @brief Remove location listener.
 */
- (void)removeLocationListener:(id<IndoorsLocationListener>)listener;

- (void)setParameter:(IndoorsParameterValue)value forKey:(IndoorsParameterKey)key;
- (void)setParameterObject:(id)value forKey:(IndoorsParameterKey)key;

- (void)initializeLocalizationWithBuilding:(IDSBuilding*)building success:(void (^)())success;
- (void)stopLocalization;
- (void)startLocalization;

- (void)getBuilding:(IDSBuilding *)building forRequestDelegate:(id<LoadingBuildingDelegate>)delegate;
- (void)cancelGetBuilding;

- (void)getOnlineBuildings:(id<OnlineBuildingDelegate>)onlineBuildingDelegate;

- (void)routeFromLocation:(IDSCoordinate *)from toLocation:(IDSCoordinate *)to inBuilding:(IDSBuilding *)building delegate:(id<RoutingDelegate>)routingDelegate;
- (void)routeFromLocation:(IDSCoordinate *)from toLocation:(IDSCoordinate *)to delegate:(id<RoutingDelegate>)routingDelegate;

- (void)enableEvaluationMode:(BOOL)isEvaluationModeEnabled;

- (void)enableRouteSnappingWithRoute:(NSArray *)route;
- (void)setRouteSnappingMaxDistance:(double)maxDistance;
- (void)disableRouteSnapping;

- (void)passLocationToLocator:(IDSCoordinate *)location;

- (void)enablePredefinedRouteSnapping;
- (void)setPredefinedRouteSnappingMaxDistance:(double)maxDistance;
- (void)disablePredefinedRouteSnapping;

@end
