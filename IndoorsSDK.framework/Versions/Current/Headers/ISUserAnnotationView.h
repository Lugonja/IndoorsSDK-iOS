#import "ISAnnotationView.h"

@interface ISDotIconView : UIView

@property (nonatomic) UIColor *dotColor;

@end

@interface ISArrowIconView : UIView

@property (nonatomic) UIColor *arrowColor;

@end

@interface ISUserAnnotationView : ISAnnotationView

@property (nonatomic) CGFloat orientation;

/**
 @brief Defines whether the user position icon should indicate the user's orientation.
 
 @discussion Setting this property to YES causes the SDK to use userPositionIcon, if the user's orientation is known.
 If the user's orientation is not known noOrientationUserPositionIcon will be used instead.
 Setting this property to NO causes the SDK to always use noOrientationUserPositionIcon.
 The default for this property is YES.
 */
@property (nonatomic) BOOL indicatesUserOrientation;

/**
 @brief The view that is used for the user position with indication of the user's orientation.
 
 @discussion If the orientation is unknown, noOrientationUserPositionIcon will be used instead. Be sure to set the buildings orientation correctly in the MMT!
 The view is automatically rotated by applying an affine transformation to it. In 0-degree position the orientation-indicating part of the icon should point upwards.
 If set to nil, an arrow icon will be used with the color specified by the defaultUserPositionIconColor property.
 */
@property (nonatomic) UIView *userPositionIcon;

/**
 @brief The view that is used for the user position without indication of the user's orientation.
 
 @discussion If set to nil, a dot icon will be used with the color specified by the defaultNoOrientationUserIconColor property.
 */
@property (nonatomic) UIView *noOrientationUserPositionIcon;

/**
 @brief The color for the default user icon if userPositionIcon is set to nil.
 */
@property (nonatomic) UIColor *defaultUserPositionIconColor;

/**
 @brief The color for the default user icon generated if noOrientationUserPositionIcon is set to nil.
 */
@property (nonatomic) UIColor *defaultNoOrientationUserPositionIconColor;

/**
 @brief The color used for the accuracy circle around the user position icon.
 */
@property (nonatomic) UIColor *accuracyCircleColor;

- (instancetype)initWithCoordinate:(IDSCoordinate *)coordinate NS_DESIGNATED_INITIALIZER;

@end
