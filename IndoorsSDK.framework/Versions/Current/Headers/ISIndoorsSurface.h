#import "Indoors.h"
#import "IndoorsSurfaceEnums.h"
#import "ISMapScrollView.h"
#import "ISMapOverlay.h"
#import "ISImageMapOverlay.h"
#import "ISRouteMapOverlay.h"

@class ISIndoorsSurface;

@protocol IndoorsSurfaceViewDelegate <NSObject>

@optional

- (void)indoorsSurface:(ISIndoorsSurface *)surfaceView userDidSelectLocation:(IDSCoordinate *)location;
- (void)indoorsSurface:(ISIndoorsSurface *)surfaceView userDidTapLocation:(IDSCoordinate *)location;

@end

@interface ISIndoorsSurface : UIView

@property (nonatomic) id<IndoorsSurfaceViewDelegate> delegate;
@property (nonatomic, readonly) ISMapScrollView *mapScrollView;
@property (nonatomic) CGRect visibleMapRect;
@property (nonatomic) BOOL enableAutomaticFloorSelection;

/**
 @brief A Boolean value indicating whether the map should try to display the user’s location.
 @discussion This property does not indicate whether the user’s position is actually visible on the map, only whether the map view should try to display it.
 */
@property (nonatomic) BOOL showsUserPosition;

/**
 @brief A boolean value indicating whether Dot on Rails mode is on or off.
 @discussion If this property is set to YES, and Snapping to predefined routes is off, this will enable predefined route snapping. If this property is set to NO, predefined route snapping will not be affected.
 */
@property (nonatomic) BOOL enableDotOnRails;

/**
 @brief This property sets a maximum jumping distance for Dot on Rails. Value is in millimeters. Recommended values are 1.000-30.000 mm.
 */
@property (nonatomic) double dotOnRailsJumpingDistance;

/**
 @brief Defines whether the user position icon should indicate the user's orientation.
 
 @discussion Setting this property to YES causes the SDK to use userPositionIcon, if the user's orientation is known.
 If the user's orientation is not known noOrientationUserPositionIcon will be used instead.
 Setting this property to NO causes the SDK to always use noOrientationUserPositionIcon.
 The default for this property is YES.
 */
@property (nonatomic) BOOL userPositionIconIndicatesUserOrientation;

/**
 @brief The view that is used for the user position with indication of the user's orientation.
 
 @discussion If the orientation is unknown, noOrientationUserPositionIcon will be used instead. Be sure to set the buildings orientation correctly in the MMT!
 The view is automatically rotated by applying an affine transformation to it. In 0-degree position the orientation-indicating part of the icon should point upwards.
 If set to nil, an arrow icon will be used with the color specified by the defaultUserPositionIconColor property.
 */
@property (nonatomic) UIImage *userPositionIcon;

/**
 @brief The color for the default user icon if userPositionIcon is set to nil.
 */
@property (nonatomic) UIColor *defaultUserPositionIconColor;

/**
 @brief The view that is used for the user position without indication of the user's orientation.
 
 @discussion If set to nil, a dot icon will be used with the color specified by the defaultNoOrientationUserIconColor property.
 */
@property (nonatomic) UIImage *noOrientationUserPositionIcon;

/**
 @brief The color for the default user icon generated if noOrientationUserPositionIcon is set to nil.
 */
@property (nonatomic) UIColor *defaultNoOrientationUserPositionIconColor;

/**
 @brief The color used for the accuracy circle around the user position icon.
 */
@property (nonatomic) UIColor *userPositionAccuracyCircleColor;

- (void)setBuildingForSurface:(IDSBuilding *)surfaceBuilding;
- (void)setFloorLevel:(NSInteger)floorLevel;
- (void)setSize:(CGRect)newFrame;
- (void)setMapCenterWithCoordinate:(IDSCoordinate *)coordinate;

/**
 @brief Changes the currently visible portion of the map and optionally animates the change.
 */
- (void)setVisibleMapRect:(CGRect)mapRect animated:(BOOL)animated;

- (void)letUserSelectLocationWithCalloutTitle:(NSString *)calloutTitle;
- (void)requireUserToSelectLocationWithCalloutTitle:(NSString *)calloutTitle;
- (void)cancelSelectLocation;

- (void)showPathWithPoints:(NSArray *)points color:(UIColor *)color lineWidth:(CGFloat)lineWidth lineCap:(ISRouteMapOverlayLineCap)lineCap;
- (void)showPathWithPoints:(NSArray *)points color:(UIColor *)color lineWidth:(CGFloat)lineWidth;
- (void)showPathWithPoints:(NSArray *)points;

- (BOOL)hasActiveBuilding;

- (void)setZoneDisplayMode:(IndoorsSurfaceZoneDisplayModes)zoneDisplayMode;

/**
 @deprecated Deprecated in version 3.7.0
 */
- (void)setUserPositionDisplayMode:(IndoorsSurfaceUserPositionDisplayModes)userPositionDisplayMode DEPRECATED_MSG_ATTRIBUTE("Please use the showsUserPosition property instead.");

- (void)hideAccuracy:(BOOL)shouldHideAccuracy;

@end
