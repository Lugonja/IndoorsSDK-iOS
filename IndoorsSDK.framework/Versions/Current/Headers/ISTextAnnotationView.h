#import <Foundation/Foundation.h>
#import "ISAnnotationView.h"

@interface ISTextAnnotationView : ISAnnotationView

- (instancetype)initWithCoordinate:(IDSCoordinate *)coordinate text:(NSString *)text;

@end
