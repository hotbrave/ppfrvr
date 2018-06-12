//
//  IOSTools.cpp
//  bcbk
//
//  Created by 赵勇 on 14-4-28.
//
//

#include "IOSTools.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#import "GameTools.h"
#import "GameKitHelper.h"
#endif
#include "AppController.h"

void IOSTools::showAd() {
    [[AppController shareViewController] showAd];
}

void IOSTools::hideAd(){
    [[AppController shareViewController] hideAd];
}

void IOSTools::pinglun()
{
    [GameTools pinglun];
}

void IOSTools::open2048max()
{
    [GameTools open2048max];
}

void IOSTools::openxpg()
{
    [GameTools openxpg];
}

void IOSTools::open2048up()
{
    [GameTools open2048up];
}

void IOSTools::openbcbk()
{
    [GameTools openbcbk];
}

void IOSTools::openfkcc()
{
    [GameTools openfkcc];
}

void IOSTools::openwzm()
{
    [GameTools openwzm];
}


void IOSTools::sendMsg(const int timeValue)
{
    [GameTools sendMsg:timeValue];
}

void IOSTools::canelMsg()
{
    [GameTools canelMsg];
}


void IOSTools::GameCenterLogin(){
    //GameCenter登陆
    [[GameKitHelper sharedGameKitHelper] authenticateLocalUser];
}

void IOSTools::GameCenterShow(){
    //显示排行榜
    [[GameKitHelper sharedGameKitHelper] showLeaderboard];
}

void  IOSTools::pinglunFun()
{
    [GameTools pinglun];
}

void IOSTools::GameCenterSendScore10(int intScore)
{//提交分数
    [[GameKitHelper sharedGameKitHelper] reportScore:@"dcfkxc_bestScore" hiScore:intScore];
}

void IOSTools::GameCenterSendScore11(int intScore)
{//提交分数
    NSLog(@"提交分数1111111111");
    [[GameKitHelper sharedGameKitHelper] reportScore:@"dcfkxc_11bestScore" hiScore:intScore];
}

void IOSTools::GameCenterSendAchievement(const char* cjID,float intScore)
{//上传成就
    NSString *nscjID = [[NSString alloc] initWithUTF8String:cjID ];
    [[GameKitHelper sharedGameKitHelper] reportAchievementIdentifier:nscjID percentComplete:intScore];
}


const char* IOSTools::getDeviceVersion()
{
    NSString *nsresult=[GameTools getDeviceVersion];
    const char * strresult = [nsresult UTF8String];
    return strresult;
}


const char* IOSTools::getLocal(const char *strLocalKey)
{
    NSString *nsLocalKey = [[NSString alloc] initWithUTF8String:strLocalKey ];
    NSString *nsresult=[GameTools getLocal:nsLocalKey];
    const char * strresult = [nsresult UTF8String];
    return strresult;
}

void IOSTools::showInsertDMAD()
{//显示多盟插屏广告
    [[AppController shareViewController] DMInterst_show];
}

void IOSTools::showMoreApps()
{//显示更多应用
    [[AppController shareViewController] MoreApps_show];
}

