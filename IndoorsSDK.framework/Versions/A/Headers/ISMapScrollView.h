#import <UIKit/UIKit.h>
#import "IDSCoordinate.h"
#import "IDSDefaultMap.h"
#import "ISAnnotationView.h"
#import "IndoorsSurfaceEnums.h"
#import "ISMapOverlay.h"
#import "ISRouteMapOverlay.h"

@class ISMapScrollView;

@protocol ISMapScrollViewDelegate <NSObject>
@optional
- (void)mapScrollView:(ISMapScrollView *)mapScrollView userDidSelectLocation:(IDSCoordinate *)location;
- (void)mapScrollView:(ISMapScrollView *)mapScrollView userDidTapLocation:(IDSCoordinate *)location;
@end

@interface ISMapScrollView : UIScrollView <UIScrollViewDelegate>

@property (nonatomic) IDSDefaultMap *map;
@property (nonatomic) id<ISMapScrollViewDelegate> mapScrollViewDelegate;
@property (nonatomic) CGRect visibleMapRect;
@property (nonatomic) NSArray *currentRoutingPath;
@property (nonatomic) IDSCoordinate *userCurrentLocation;
@property (nonatomic) NSInteger userCurrentFloorLevel;

@property (nonatomic) BOOL userPositionIconIndicatesUserOrientation;
@property (nonatomic) UIImage *userPositionIcon;
@property (nonatomic) UIColor *defaultUserPositionIconColor;
@property (nonatomic) UIImage *noOrientationUserPositionIcon;
@property (nonatomic) UIColor *defaultNoOrientationUserPositionIconColor;
@property (nonatomic) UIColor *userPositionAccuracyCircleColor;
@property (nonatomic, getter=isUserLocationHidden) BOOL userLocationHidden;

- (void)letUserSelectLocationWithCalloutTitle:(NSString *)title;
- (void)requireUserToSelectLocationWithCalloutTitle:(NSString *)title;
- (void)cancelSelectLocation;

- (void)setRoutingPath:(NSArray *)path;
- (void)setRoutingPath:(NSArray *)path withColor:(UIColor *)color lineWidth:(CGFloat)lineWidth;
- (void)setRoutingPath:(NSArray *)path withColor:(UIColor *)color lineWidth:(CGFloat)lineWidth lineCap:(ISRouteMapOverlayLineCap)lineCap;
- (void)clearRouting;

- (void)setUserPosition:(IDSCoordinate *)coordinate;
- (void)setUserOrientation:(float)orientation;
- (void)setMapCenterWithCoordinate:(IDSCoordinate *)coordinate;

/**
 @deprecated Deprecated in version 3.7.0
 */
- (void)zoomToMapRect:(CGRect)rect animated:(BOOL)animated DEPRECATED_MSG_ATTRIBUTE("Please use setVisibleMapRect:animated instead.");

- (void)setVisibleMapRect:(CGRect)mapRect animated:(BOOL)animated;

- (void)addOverlay:(ISMapOverlay *)overlay toFloorLevel:(NSInteger)floorLevel;
- (void)removeOverlay:(ISMapOverlay *)overlay;
- (void)addAnnotation:(ISAnnotationView *)annotationView;
- (void)removeAnnotation:(ISAnnotationView *)annotationView;
- (void)setZoneDisplayMode:(IndoorsSurfaceZoneDisplayModes)zoneDisplayMode;

/**
 @deprecated Deprecated in version 3.7.0
 */
- (void)setUserPositionDisplayMode:(IndoorsSurfaceUserPositionDisplayModes)userPositionDisplayMode DEPRECATED_MSG_ATTRIBUTE("Please use the showsUserPosition property of ISIndoorsSurface.h instead.");

- (void)didReceiveWeakSignal;

- (IDSCoordinate *)coordinateForPoint:(CGPoint)point;
- (CGPoint)pointForCoordinate:(IDSCoordinate *)coordinate;

@end
