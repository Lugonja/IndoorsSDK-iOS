#import "ISAnnotationView.h"

@interface ISImageAnnotationView : ISAnnotationView

@property (nonatomic) UIImage *image;

- (instancetype)initWithCoordinate:(IDSCoordinate *)coordinate image:(UIImage *)image position:(ISAnnotationViewPosition)position;

@end
