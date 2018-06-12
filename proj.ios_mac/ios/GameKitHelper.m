//
//  GameKitHelper.m
//  fkcc
//
//  Created by 赵勇 on 14-3-29.
//
//

#import "GameKitHelper.h"  
@implementation GameKitHelper
@synthesize gameCenterAvailable;
//静态初始化 对外接口
static GameKitHelper *sharedHelper = nil;
static UIViewController* currentModalViewController = nil;

+ (GameKitHelper *) sharedGameKitHelper
{
    //NSLog(@"sharedGameKitHelper");
    if (!sharedHelper)
    {
     sharedHelper = [[GameKitHelper alloc] init];
    }
return sharedHelper;
}

 //用于验证
 - (BOOL)isGameCenterAvailable
{NSLog(@"isGameCenterAvailable");
     // check for presence of GKLocalPlayer API
     Class gcClass = (NSClassFromString(@"GKLocalPlayer"));
    // check if the device is running iOS 4.1 or later
    NSString *reqSysVer =@"4.1";
     NSString *currSysVer = [[UIDevice currentDevice] systemVersion];

    BOOL osVersionSupported = ([currSysVer compare:reqSysVer  options:NSNumericSearch] != NSOrderedAscending);
    return (gcClass && osVersionSupported);
}

- (id)init
{NSLog(@"init");
    if ((self = [super init]))
    {
        gameCenterAvailable = [self isGameCenterAvailable];
        if (gameCenterAvailable)
        {  NSNotificationCenter *nc =
            [NSNotificationCenter defaultCenter];  [nc addObserver:self
                                                          selector:@selector(authenticationChanged)
                                                              name:GKPlayerAuthenticationDidChangeNotificationName  object:nil];
        }
    }
    return self;
}

 //后台回调登陆验证
 - (void)authenticationChanged
{
    //NSLog(@"authenticationChanged");
     if ([GKLocalPlayer localPlayer].isAuthenticated &&!userAuthenticated)
     {  NSLog(@"Authentication changed: player authenticated.用户已经认证");
         userAuthenticated = TRUE;
     }
    else if (![GKLocalPlayer localPlayer].isAuthenticated &&userAuthenticated)
    {
         NSLog(@"Authentication changed: player not authenticated用户认证不成功");
        userAuthenticated = FALSE;
    }
}

 - (void)authenticateLocalUser
{NSLog(@"authenticateLocalUser");
    if (!gameCenterAvailable)
        return;
    NSLog(@"Authenticating local user...");
    
     if ([GKLocalPlayer localPlayer].authenticated == NO)
     {
         [[GKLocalPlayer localPlayer] authenticateWithCompletionHandler:nil];
     } else
     {
             NSLog(@"Already authenticated!");
     }
}

 //显示排行榜
 - (void) showLeaderboard
{
    NSLog(@"showLeaderboard");
     if (!gameCenterAvailable)
         return;
    GKLeaderboardViewController *leaderboardController =[[GKLeaderboardViewController alloc] init];
     if (leaderboardController != nil)
     {
         leaderboardController.leaderboardDelegate = self;
         UIWindow *window = [[UIApplication sharedApplication] keyWindow];
         currentModalViewController = [[UIViewController alloc] init];
         [window addSubview:currentModalViewController.view];
         [currentModalViewController presentModalViewController:leaderboardController animated:YES];
    }
}

 //关闭排行榜回调
 - (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController*)viewController
{NSLog(@"leaderboardViewControllerDidFinish");
     if(currentModalViewController !=nil)
     {
         [currentModalViewController dismissModalViewControllerAnimated:NO];  [currentModalViewController release];
         [currentModalViewController.view removeFromSuperview];  currentModalViewController = nil;
     }
}

/**
 上传积分
 */
- (void)reportScore : (NSString*)identifier hiScore:(int64_t)score;
{
    //NSLog(@"上传积分");
    if (score < 0 || !userAuthenticated)
    {
        return;
    }
    //NSLog(@"上传积分2222");
    GKScore *scoreBoard = [[GKScore alloc] initWithLeaderboardIdentifier:identifier];
    scoreBoard.value = score;
    [GKScore reportScores:@[scoreBoard] withCompletionHandler:^(NSError *error)
     {
         if (error)
         {
             // handle error
             NSLog(@"上传积分error");
         }
     }];
    //NSLog(@"上传积分结束");
}

/**
 上传成就
 */
- (void)reportAchievementIdentifier : (NSString*)identifier percentComplete:(float)percent
{NSLog(@"上传成就");
    if (percent < 0 || !userAuthenticated)
    {
        return;
    }
    
    GKAchievement *achievement = [[GKAchievement alloc] initWithIdentifier: identifier];
    if (achievement)
    {
        achievement.percentComplete = percent;
        [GKAchievement reportAchievements:@[achievement] withCompletionHandler:^(NSError *error) {
            if (error)
            {
                // handle error
            }
        }];
    }
}

@end
