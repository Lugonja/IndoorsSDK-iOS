#import <Foundation/Foundation.h>
#import "Indoors.h"
#import "ISMapOverlay.h"
#import "ISRouteMapOverlay.h"

@class ISAnnotationView;

@interface ISMapView : UIView

@property (nonatomic, readonly) IDSDefaultMap *map;
@property (nonatomic, readonly) CGFloat widthRatio;
@property (nonatomic, readonly) CGFloat heightRatio;
@property (nonatomic) CGFloat zoomScale;

- (instancetype)initWithMap:(IDSDefaultMap *)map andTile:(IDSTile *)tile;

- (void)addOverlay:(ISMapOverlay *)overlay;
- (void)removeOverlay:(ISMapOverlay *)overlay;

- (void)addAnnotation:(ISAnnotationView *)annotation;
- (void)removeAnnotation:(ISAnnotationView *)annotation;

- (void)addTopAnnotation:(ISAnnotationView *)annotation;
- (void)removeTopAnnotation:(ISAnnotationView *)annotation;

- (void)setRoutingPath:(NSArray *)path withColor:(UIColor *)color lineWidth:(CGFloat)lineWidth;
- (void)setRoutingPath:(NSArray *)path withColor:(UIColor *)color lineWidth:(CGFloat)lineWidth lineCap:(ISRouteMapOverlayLineCap)lineCap;
- (void)showZones:(NSArray *)zones;
- (void)hideAllZones;

- (void)updateAnnotationsZoomScale;
- (void)updateOverlaysZoomScale;

@end
