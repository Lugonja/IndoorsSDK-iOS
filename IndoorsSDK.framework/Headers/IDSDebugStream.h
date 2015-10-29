#import <Foundation/Foundation.h>

@protocol IDSDebugStreamListener
@required
- (void)debugStreamReceivedValue:(NSString *)value forKey:(NSString *)key;
@end

@interface IDSDebugStream : NSObject

+ (instancetype)sharedInstance;

- (void)registerDebugStreamListener:(id<IDSDebugStreamListener>)listener;
- (void)removeDebugStreamListener:(id<IDSDebugStreamListener>)listener;

@end
