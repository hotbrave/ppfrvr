//
//  GameTools.h
//  bcbk
//
//  Created by 赵勇 on 14-4-28.
//
//

#import <Foundation/Foundation.h>
#import "ConstantsIOS.h"

@interface GameTools : NSObject{}

+ (void)pinglun;//到appstroe评论

+ (void)sendMsg:(int)timeValue;//本地通知
+ (void)canelMsg;//本地通知

+ (NSString*)getDeviceVersion;//获取设备型号，比如iphone5

+ (NSString *)getLocal:(NSString *)nsLocalKey;//获取本地化的值

+ (void)open2048max;//
+ (void)openxpg;//
+ (void)open2048up;//
+ (void)openbcbk;//
+ (void)openfkcc;//
+ (void)openwzm;//


@end
