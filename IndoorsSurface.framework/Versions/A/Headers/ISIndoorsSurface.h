#import <UIKit/UIKit.h>
#import <Indoors/Indoors.h>
#import "IndoorsSurfaceEnums.h"
#import "ISMapScrollView.h"
#import "ISMapOverlay.h"
#import "ISImageMapOverlay.h"

@class ISIndoorsSurface;

@protocol IndoorsSurfaceViewDelegate <NSObject>

@optional

- (void)indoorsSurface:(ISIndoorsSurface *)surfaceView userDidSelectLocation:(IDSCoordinate *)location;
- (void)indoorsSurface:(ISIndoorsSurface *)surfaceView userDidTapLocation:(IDSCoordinate *)location;

@end

@interface ISIndoorsSurface : UIView

@property (nonatomic) id<IndoorsSurfaceViewDelegate> delegate;
@property (nonatomic, readonly) ISMapScrollView *mapScrollView;
@property (nonatomic) BOOL enableAutomaticFloorSelection;
@property (nonatomic) BOOL routeSnappingEnabled;

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

- (void)letUserSelectLocationWithCalloutTitle:(NSString *)calloutTitle;
- (void)requireUserToSelectLocationWithCalloutTitle:(NSString *)calloutTitle;
- (void)cancelSelectLocation;

- (void)showPathWithPoints:(NSArray *)points color:(UIColor *)color lineWidth:(CGFloat)lineWidth;
- (void)showPathWithPoints:(NSArray *)points;

- (BOOL)hasActiveBuilding;

- (void)setZoneDisplayMode:(IndoorsSurfaceZoneDisplayModes)zoneDisplayMode;

- (void)setUserPositionDisplayMode:(IndoorsSurfaceUserPositionDisplayModes)userPositionDisplayMode;

- (void)hideAccuracy:(BOOL)shouldHideAccuracy;

@end
