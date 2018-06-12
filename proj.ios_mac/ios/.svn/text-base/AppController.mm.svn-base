/****************************************************************************
 Copyright (c) 2010 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#import "AppController.h"

#import "cocos2d.h"
#import "AppDelegate.h"
#import "RootViewController.h"
#import "ConstantsIOS.h"

#import "ChanceAd.h"

#define IS_OS_7_OR_LATER    ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)

@implementation AppController

@synthesize window;
@synthesize viewController;

#pragma mark -
#pragma mark Application lifecycle

// cocos2d application instance
static AppDelegate s_sharedApplication;
static AppController* instance;

+ (id)shareViewController
{
    //NSLog(@"shareViewController111111");
    return instance;
}

- (void)showAd{
    //NSLog(@"showAd22222");
    _dmAdView.hidden = NO;
    bannerView.hidden = NO;
    //_bannerView.hidden=NO;
    [eaglView addSubview:_bannerView];

}

- (void)hideAd{
    NSLog(@"hideAd");
    _dmAdView.hidden = YES;
    bannerView.hidden = YES;
    //_bannerView.hidden=YES;
    [_bannerView removeFromSuperview];
    
}

- (int)getURLflag
{
    //从网络获取显示哪个广告
    int result=ADFlag1;//默认多盟广告

    
    //第一步，创建URL
    NSURL *url = [NSURL URLWithString:@"http://www.paopaobox.com/ibf/fc01.htm"];
    //NSURL *url = [NSURL URLWithString:@"http://www.paopaobox.com/ibf/fc91.htm"];
    

    //NSURLRequest初始化方法第一个参数：请求访问路径，第二个参数：缓存协议，第三个参数：网络请求超时时间（秒）
    /*
    其中缓存协议是个枚举类型包含：
    NSURLRequestUseProtocolCachePolicy（基础策略）
    NSURLRequestReloadIgnoringLocalCacheData（忽略本地缓存）
    NSURLRequestReturnCacheDataElseLoad（首先使用缓存，如果没有本地缓存，才从原地址下载）
    NSURLRequestReturnCacheDataDontLoad（使用本地缓存，从不下载，如果本地没有缓存，则请求失败，此策略多用于离线操作）
    NSURLRequestReloadIgnoringLocalAndRemoteCacheData（无视任何缓存策略，无论是本地的还是远程的，总是从原地址重新下载）
    NSURLRequestReloadRevalidatingCacheData（如果本地缓存是有效的则不下载，其他任何情况都从原地址重新下载）
    */
    
    
    //第二步，通过URL创建网络请求
    NSURLRequest *request = [[NSURLRequest alloc]initWithURL:url cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:10];
    //NSURLRequest *request = [[NSURLRequest alloc]initWithURL:url cachePolicy:NSURLRequestReloadIgnoringLocalAndRemoteCacheData timeoutInterval:10];
    //第三步，连接服务器
    NSData *received = [NSURLConnection sendSynchronousRequest:request returningResponse:nil error:nil];
    
    ////
    
    

    ////
    
    NSString *str = [[NSString alloc]initWithData:received encoding:NSUTF8StringEncoding];
    
    NSLog(@"webcon =  %@",str);
    
    //////////
    if ([str isEqualToString:@"0"])
    {//显示苹果广告
        NSLog(@"yes================0");
        result= ADFlag0;
    }
    else if([str isEqualToString:@"1"])
    {//显示多盟广告
        NSLog(@"yes================1");
        result= ADFlag1;
    }
    else if ([str isEqualToString:@"2"])
    {//显示广点通广告
        NSLog(@"yes================2");
        result= ADFlag2;

    }
    else if ([str isEqualToString:@"3"])
    {//显示cocos广告
        NSLog(@"yes================3");
        result= ADFlag3;
    }
    
    NSLog(@"result =  %d",result);
    
    return result;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    instance = self;
    // Override point for customization after application launch.
    
    // Add the view controller's view to the window and display.
    window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    
    // Init the CCEAGLView
    eaglView = [CCEAGLView viewWithFrame: [window bounds]
                                         pixelFormat: kEAGLColorFormatRGBA8
                                         depthFormat: GL_DEPTH24_STENCIL8_OES
                                  preserveBackbuffer: NO
                                          sharegroup: nil
                                       multiSampling: NO
                                     numberOfSamples: 0];
    
    // Use RootViewController manage CCEAGLView
    viewController = [[RootViewController alloc] initWithNibName:nil bundle:nil];
    viewController.wantsFullScreenLayout = YES;
    viewController.view = eaglView;
    
    // Set RootViewController to window
    if ( [[UIDevice currentDevice].systemVersion floatValue] < 6.0)
    {
        // warning: addSubView doesn't work on iOS6
        [window addSubview: viewController.view];
    }
    else
    {
        // use this method on ios6
        [window setRootViewController:viewController];
    }
    
    [window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden:true];
    
    //////////////
    //int ADflag=[self getURLflag];
    int ADflag=ADFlag2;
    /////////调试使用temp，强制改成多盟广告，正式版要去掉
    //ADflag=1;
    NSLog(@"ADflag =  %d",ADflag);
    ////////////
    if (ADflag==ADFlag1)
    {//显示多盟广告
        NSLog(@"多盟AD");
        //多盟广告begin
        
         CGRect screenBounds = [[UIScreen mainScreen] bounds];
         
         _dmAdView = [[DMAdView alloc] initWithPublisherId:dmADPublisherId
         placementId:dmADPlacementId];
         _dmAdView.delegate = self;
         _dmAdView.rootViewController = viewController;
         
         //普通banner
         int originHeight = 0;
         if ([[[UIDevice currentDevice] systemVersion] floatValue] < 7.0 ) {
         originHeight = 0;
         }else{
         originHeight = 20;
         }
         //_dmAdView.frame = CGRectMake(0, originHeight, FLEXIBLE_SIZE.width, FLEXIBLE_SIZE.height);
         if ([[[UIDevice currentDevice] model] rangeOfString:@"Pad"].location == NSNotFound)
         {
         _dmAdView.frame = CGRectMake((screenBounds.size.width - 320) / 2, screenBounds.size.height - 50, FLEXIBLE_SIZE.width, FLEXIBLE_SIZE.height);
         }
         else
         {
         _dmAdView.frame = CGRectMake((screenBounds.size.width - 768) / 2, screenBounds.size.height - 90, FLEXIBLE_SIZE.width, FLEXIBLE_SIZE.height);
         }
         
         
         [_dmAdView loadAd];
         _dmAdView.hidden = YES;
         
         [eaglView addSubview:_dmAdView];
        
        //多盟广告end
        /////////////
    }
    else if (ADflag==ADFlag3)
    {
        NSLog(@"cocos畅思AD");
        //cocos畅思广告begin
        
        CGRect screenBounds = [[UIScreen mainScreen] bounds];
        
        NSLog(@"changsiAD SDK版本号：%@", [ChanceAd sdkVersion]);
        //[ChanceAd startSession:@"100032-4CE817-ABA2-5B48-14D009296720"];//测试值
        [ChanceAd startSession:@"842351113-88004A-037E-8136-C0D44A631"];
        ////
        
        //CGRect frameBanner = CGRectMake(0.0f, 0.0f, 320.0f, 50.0f);
        CGRect frameBanner;
        if ([[[UIDevice currentDevice] model] rangeOfString:@"Pad"].location == NSNotFound)
        {
            frameBanner = CGRectMake((screenBounds.size.width - 320) / 2, screenBounds.size.height - 50, FLEXIBLE_SIZE.width, FLEXIBLE_SIZE.height);
        }
        else
        {
            frameBanner = CGRectMake((screenBounds.size.width - 768) / 2, screenBounds.size.height - 90, FLEXIBLE_SIZE.width, FLEXIBLE_SIZE.height);
        }
        
        
        bannerView=[[CSBannerView alloc] initWithFrame:frameBanner];
        
        //bannerView.rootViewController = viewController;
        
        bannerView.delegate=self;
        [bannerView loadRequest:[CSADRequest request]];
        
        [eaglView addSubview:bannerView];
        
        
        [self hideAd];
        
        NSLog(@"bannerView.isHidden 广告是否隐藏 value: %@" ,bannerView.isHidden?@"YES":@"NO");
        
        [bannerView release];
        
        //畅思广告end
    }
    else if (ADflag==ADFlag2)
    {
        NSLog(@"GDT广点通AD");
        //腾讯广点通Banner广告begin
        
        /*
         * 创建Banner广告View
         * "appkey" 指在 http://e.qq.com/dev/ 能看到的app唯一字符串
         * "placementId" 指在 http://e.qq.com/dev/ 生成的数字串，广告位id
         *
         * banner条广告，广点通提供如下3中尺寸供开发者使用
         * 320*50 适用于iPhone
         * 468*60、728*90适用于iPad
         * banner条的宽度开发者可以进行手动设置，用以满足开发场景需求或是适配最新版本的iphone
         * banner条的高度广点通侧强烈建议开发者采用推荐的高度，否则显示效果会有影响
         *
         * 这里以320*50为例
         */
        
        CGRect screenBounds = [[UIScreen mainScreen] bounds];
        CGRect frameBanner;
        if ([[[UIDevice currentDevice] model] rangeOfString:@"Pad"].location == NSNotFound)
        {
            NSLog(@"不是ipad广告20160504");
            frameBanner=CGRectMake(0, screenBounds.size.height - 50,
                                   GDTMOB_AD_SUGGEST_SIZE_320x50.width,
                                   GDTMOB_AD_SUGGEST_SIZE_320x50.height);
        }
        else
        {
            NSLog(@"ipad广告20160504");
            frameBanner=CGRectMake(0, screenBounds.size.height - 90,
                                   GDTMOB_AD_SUGGEST_SIZE_728x90.width,
                                   GDTMOB_AD_SUGGEST_SIZE_728x90.height);
            
            //frameBanner=CGRectMake(0, screenBounds.size.height - 60,
            //GDTMOB_AD_SUGGEST_SIZE_468x60.width,
            //GDTMOB_AD_SUGGEST_SIZE_468x60.height);
            
            //frameBanner=CGRectMake(0, screenBounds.size.height - 90,
            //GDTMOB_AD_SUGGEST_SIZE_768x90.width,
            //GDTMOB_AD_SUGGEST_SIZE_768x90.height);
            
        }
        
        
        _bannerView = [[GDTMobBannerView alloc] initWithFrame:frameBanner
                                                       appkey:@"1105091125"
                                                  placementId:@"1080404837018108"];
        ////
        //[super viewDidLoad];
        /*
         * 如果是IOS7的系统，设置视图不延伸至导航栏所在区域。
         */
        if (IS_OS_7_OR_LATER) {
            //self.extendedLayoutIncludesOpaqueBars = NO;
            //self.edgesForExtendedLayout = UIRectEdgeBottom | UIRectEdgeLeft | UIRectEdgeRight;
        }
        
        
        _bannerView.delegate = self; // 设置Delegate
        _bannerView.currentViewController = viewController; //设置当前的ViewController
        _bannerView.interval = 30; //【可选】设置刷新频率;默认30秒
        _bannerView.isGpsOn = NO; //【可选】开启GPS定位;默认关闭
        _bannerView.showCloseBtn = NO; //【可选】展示关闭按钮;默认显示
        _bannerView.isAnimationOn = YES; //【可选】开启banner轮播和展现时的动画效果;默认开启
        
        //[eaglView addSubview:_bannerView];//刚启动的时候先不加广告，以后需要的时候再加
        
        [_bannerView loadAdAndShow]; //加载广告并展示
        [_bannerView retain];//从上级view中remove前先retain,防止被清理出内存导致异常，不知道有没有必要，还没测试
        //[self hideAd];
        
        
        //腾讯广点通Banner广告end
        
        //腾讯广点通开屏广告begin
        //开屏广告初始化
        //_splash = [[GDTSplashAd alloc] initWithAppkey:@"1101508191" placementId:@"9060000655187666"];
        _splash = [[GDTSplashAd alloc] initWithAppkey:@"1105091125" placementId:@"7040814049773932"];//我的广告id
        _splash.delegate = self;//设置代理
        //针对不同设备尺寸设置不同的默认图片，拉取广告等待时间会展示该默认图片。
        if ([[UIScreen mainScreen] bounds].size.height >= 568.0f)
        {
            NSLog(@"大开屏图片");
            _splash.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"LaunchImage-568h"]];
        }
        else
        {   NSLog(@"小开屏");
            _splash.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"LaunchImage"]];
        }
        
        UIWindow *fK = [[UIApplication sharedApplication] keyWindow];
        //设置开屏拉取时长限制，若超时则不再展示广告
        _splash.fetchDelay = 3;
        //拉取并展示
        [_splash loadAdAndShowInWindow:fK];
        //腾讯广点通开屏广告end
        
        /////////////
        
    }
    

    
    
    
    
    

    ///////////////
    
    // IMPORTANT: Setting the GLView should be done after creating the RootViewController
    cocos2d::GLView *glview = cocos2d::GLView::createWithEAGLView(eaglView);
    cocos2d::Director::getInstance()->setOpenGLView(glview);
    
    cocos2d::Application::getInstance()->run();
    
    return YES;
}


///////广点通banner广告回调begin////////////
- (void) viewWillDisappear:(BOOL)animated
{
    //NSLog(@"%s",__FUNCTION__);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
    //NSLog(@"%s",__FUNCTION__);
}

- (void)bannerViewMemoryWarning
{
    //NSLog(@"%s",__FUNCTION__);
}

// 请求广告条数据成功后调用
//
// 详解:当接收服务器返回的广告数据成功后调用该函数
- (void)bannerViewDidReceived
{
    //NSLog(@"%s",__FUNCTION__);
    
}

// 请求广告条数据失败后调用
//
// 详解:当接收服务器返回的广告数据失败后调用该函数
- (void)bannerViewFailToReceived:(NSError *)error
{
    NSLog(@"%s, Error:%@",__FUNCTION__,error);
    _bannerView.hidden=YES;
}

// 应用进入后台时调用
//
// 详解:当点击下载或者地图类型广告时，会调用系统程序打开，
// 应用将被自动切换到后台
- (void)bannerViewWillLeaveApplication
{
    //NSLog(@"%s",__FUNCTION__);
}

// banner条曝光回调
//
// 详解:banner条曝光时回调该方法
- (void)bannerViewWillExposure
{
    //NSLog(@"%s",__FUNCTION__);
    
}

// banner条点击回调
//
// 详解:banner条被点击时回调该方法
- (void)bannerViewClicked
{
    //NSLog(@"%s",__FUNCTION__);
}

/**
 *  banner条被用户关闭时调用
 *  详解:当打开showCloseBtn开关时，用户有可能点击关闭按钮从而把广告条关闭
 */
- (void)bannerViewWillClose
{
    //NSLog(@"%s",__FUNCTION__);
}
/////广点通banner广告回调end//////////////


//广点通开屏广告回调begin
-(void)splashAdSuccessPresentScreen:(GDTSplashAd *)splashAd
{
    //NSLog(@"%s",__FUNCTION__);
}

-(void)splashAdFailToPresent:(GDTSplashAd *)splashAd withError:(NSError *)error
{
    NSLog(@"%s%@",__FUNCTION__,error);
}

-(void)splashAdClicked:(GDTSplashAd *)splashAd
{
    //NSLog(@"%s",__FUNCTION__);
}

-(void)splashAdApplicationWillEnterBackground:(GDTSplashAd *)splashAd
{
    NSLog(@"%s",__FUNCTION__);
}

-(void)splashAdClosed:(GDTSplashAd *)splashAd
{
    //NSLog(@"%s",__FUNCTION__);
}
////广点通开屏广告回调end

- (void)applicationWillResignActive:(UIApplication *)application {
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
    //We don't need to call this method any more. It will interupt user defined game pause&resume logic
    /* cocos2d::Director::getInstance()->pause(); */
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    //We don't need to call this method any more. It will interupt user defined game pause&resume logic
    /* cocos2d::Director::getInstance()->resume(); */
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
     If your application supports background execution, called instead of applicationWillTerminate: when the user quits.
     */
    cocos2d::Application::getInstance()->applicationDidEnterBackground();
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    /*
     Called as part of  transition from the background to the inactive state: here you can undo many of the changes made on entering the background.
     */
    cocos2d::Application::getInstance()->applicationWillEnterForeground();
}

- (void)applicationWillTerminate:(UIApplication *)application {
    /*
     Called when the application is about to terminate.
     See also applicationDidEnterBackground:.
     */
}


#pragma mark -
#pragma mark Memory management

- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application {
    /*
     Free up as much memory as possible by purging cached data objects that can be recreated (or reloaded from disk) later.
     */
}


- (void)dealloc {
    _bannerView.delegate=nil;
    _bannerView.currentViewController=nil;
    
    [window release];
    [super dealloc];
}

#pragma mark -
#pragma mark DMAdView delegate

// 成功加载广告后，回调该方法
- (void)dmAdViewSuccessToLoadAd:(DMAdView *)adView
{
    NSLog(@"[Domob Sample] success to load ad.");
}

// 加载广告失败后，回调该方法
- (void)dmAdViewFailToLoadAd:(DMAdView *)adView withError:(NSError *)error
{
    NSLog(@"[Domob Sample] fail to load ad. %@", error);
}

// 当将要呈现出 Modal View 时，回调该方法。如打开内置浏览器。
- (void)dmWillPresentModalViewFromAd:(DMAdView *)adView
{
    NSLog(@"[Domob Sample] will present modal view.");
}

// 当呈现的 Modal View 被关闭后，回调该方法。如内置浏览器被关闭。
- (void)dmDidDismissModalViewFromAd:(DMAdView *)adView
{
    NSLog(@"[Domob Sample] did dismiss modal view.");
}

// 当因用户的操作（如点击下载类广告，需要跳转到Store），需要离开当前应用时，回调该方法
- (void)dmApplicationWillEnterBackgroundFromAd:(DMAdView *)adView
{
    NSLog(@"[Domob Sample] will enter background.");
}



//////////////
#pragma mark - CSBannerViewDelegate

// Banner广告发出请求
- (void)csBannerViewRequestAD:(CSBannerView *)csBannerView
{
    NSLog(@"-----Banner广告发出请求-----%s", __PRETTY_FUNCTION__);
    //self.title = @"RequestAD";
}

// Banner广告展现失败
- (void)csBannerView:(CSBannerView *)csBannerView
         showAdError:(CSRequestError *)requestError
{
    NSLog(@"-----Banner广告展现失败-----%s  %@", __PRETTY_FUNCTION__, requestError.localizedDescription);
    //self.title = @"loadAdFailure";
}

// 将要展示Banner广告
- (void)csBannerViewWillPresentScreen:(CSBannerView *)csBannerView
{
    NSLog(@"-----将要展示Banner广告-----%s", __PRETTY_FUNCTION__);
}

// 移除Banner广告
- (void)csBannerViewDidDismissScreen:(CSBannerView *)csBannerView
{
    NSLog(@"----移除Banner广告------%s", __PRETTY_FUNCTION__);
}
//////////////

@end
