//
//  GameKitHelper.h
//  fkcc
//
//  Created by 赵勇 on 14-3-29.
//
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>
@interface GameKitHelper :NSObject <GKLeaderboardViewControllerDelegate,GKAchievementViewControllerDelegate,GKMatchmakerViewControllerDelegate,GKMatchDelegate>
{
    BOOL gameCenterAvailable;
    BOOL userAuthenticated;
}
@property (assign, readonly) BOOL gameCenterAvailable;
+ (GameKitHelper *)sharedGameKitHelper;
- (void) authenticateLocalUser;
- (void) showLeaderboard; //显示排行榜
- (void)leaderboardViewControllerDidFinish:(GKLeaderboardViewController*)viewController; //关闭排行榜回调


/**
 上传积分
 */
- (void)reportScore : (NSString*)identifier hiScore:(int64_t)score;
/**
 上传成就
 */
- (void)reportAchievementIdentifier : (NSString*)identifier percentComplete:(float)percent;

@end