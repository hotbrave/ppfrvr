#import <UIKit/UIKit.h>
#import "CCEAGLView.h"
#import "DMAdView.h"
#import "CSBannerView.h"
#import "GDTMobBannerView.h" //导入GDTMobBannerView.h腾讯广点通banner广告头文件
#import "GDTSplashAd.h" //导入GDTSplashAd.h腾讯广点通开屏广告头文件


@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate,
UITextFieldDelegate,UIApplicationDelegate,DMAdViewDelegate,CSBannerViewDelegate,GDTMobBannerViewDelegate,GDTSplashAdDelegate> {
    
    CCEAGLView *eaglView;
    
    
    UIWindow *window;
    RootViewController    *viewController;
    DMAdView *_dmAdView;//多盟广告对象
    CSBannerView *bannerView;//cocos广告对象
    GDTMobBannerView *_bannerView;//声明一个GDTMobBannerView的实例
    
}

@property (nonatomic, retain) UIWindow *window;
@property(nonatomic, readonly) RootViewController* viewController;

//腾讯广点通开屏广告begin
@property(strong,nonatomic)GDTSplashAd *splash;
@property(retain,nonatomic)UIView *bottomView;
//腾讯广点通开屏广告end

-(void)hideAd;
-(void)showAd;

- (int)getURLflag;

@end

