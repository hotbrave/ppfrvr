//
//  GameTools.m
//  bcbk
//
//  Created by 赵勇 on 14-4-28.
//
//

#import "GameTools.h"
//#include "Reachability.h"   //20141128调试临时取消
#import "ConstantsIOS.h"

@implementation GameTools

+ (void)pinglun
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:appURL]];
    NSLog (@"this is a pinglun");

    ///////////////////
}

+ (void)sendMsg:(int)timeValue
{
    //NSLog (@"sendMsg11111111");
    //NSLog (@"timeValue===%d",timeValue);
    UILocalNotification *notification=[[UILocalNotification alloc] init];
    if (notification!=nil)
    {
        //////////
        //存入的字典，用于传入数据，区分多个通知
        /*
         NSMutableDictionary *dicUserInfo = [[NSMutableDictionary alloc] init];
         [dicUserInfo setValue:@"" forKey:@"clockID"];
         notification.userInfo = [NSDictionary dictionaryWithObject:dicUserInfo forKey:@"dictionary"];
         [dicUserInfo release];
         */
        ///////////
        //设置userinfo 方便在之后需要撤销的时候使用
        NSMutableDictionary *dicUserInfo = [[NSMutableDictionary alloc] init];
        [dicUserInfo setValue:TongZhiValue1 forKey:TongZhiKey1];
        notification.userInfo = dicUserInfo;
        ////////////
        
        notification.applicationIconBadgeNumber = 1;        //应用右上角红色图标数字
        NSDate *now=[NSDate new];
        notification.fireDate=[now addTimeInterval:timeValue];
        //notification.fireDate=[now addTimeInterval:timeValue];
        //notification.fireDate=[now addTimeInterval:timeValue/60/30];//调试用，要改
        notification.timeZone=[NSTimeZone defaultTimeZone];
        notification.soundName = UILocalNotificationDefaultSoundName;//推送声音
        notification.alertBody=NSLocalizedString(@"ComeBack", nil);
        //notification.alertBody=@"金币已经补充完毕！";
        ////////////


        ////////////
        [[UIApplication sharedApplication]   scheduleLocalNotification:notification];
    }
}

+ (void)canelMsg
{
    //NSLog (@"canelMsg22222222");
    //[UIApplication sharedApplication].applicationIconBadgeNumber=0;
    
    NSArray *myArray=[[UIApplication sharedApplication] scheduledLocalNotifications];
    for (int i=0; i<[myArray count]; i++)
    {
        UILocalNotification    *myUILocalNotification=[myArray objectAtIndex:i];

        if ([[[myUILocalNotification userInfo] objectForKey:TongZhiKey1] intValue]==[TongZhiValue1 intValue])
        {
            //NSLog(@"取消通知时值相等");
            [[UIApplication sharedApplication] cancelLocalNotification:myUILocalNotification];
        }
    }
}

+ (NSString*)getDeviceVersion
{
    /*
    size_t size;
    sysctlbyname("hw.machine", NULL, &size, NULL, 0);
    char *machine = (char*)malloc(size);
    sysctlbyname("hw.machine", machine, &size, NULL, 0);
    NSString *platform = [NSString stringWithCString:machine encoding:NSUTF8StringEncoding];
    free(machine);
    return platform;
    */
    return @"testaaaaa";
}


+ (NSString *)getLocal:(NSString *)nsLocalKey
{
    //获取本地化的值
    NSString * result = NSLocalizedString(nsLocalKey, nil);
    
    return result;
}

+ (void)open2048max
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:open2048maxURL]];
}

+ (void)openxpg
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:openxpgURL]];
}

+ (void)open2048up
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:open2048upURL]];
}

+ (void)openbcbk
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:openbcbkURL]];
}

+ (void)openfkcc
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:openfkccURL]];
}

+ (void)openwzm
{
    [[UIApplication sharedApplication] openURL:[NSURL URLWithString:openwzmURL]];
}


@end
