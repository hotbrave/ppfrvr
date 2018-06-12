//
//  CSBannerView.h
//  CSADSDK
//
//  Created by cassano on 13-10-14.
//  Copyright (c) 2013年 CocoaChina. All rights reserved.
//

#ifndef CSBannerView_h
#define CSBannerView_h
#import <UIKit/UIKit.h>
#import "CSADRequest.h"
#import "CSRequestError.h"


#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000   // 当前Xcode支持iOS8及以上
#define  ScreenSize ([[UIDevice currentDevice].systemVersion floatValue]<8.0f?[UIScreen mainScreen].bounds.size:CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale))
#else
#define  ScreenSize [UIScreen mainScreen].bounds.size
#endif


#define CSBannerSize_iPhone   CGSizeMake(ScreenSize.width, 50.0f)
#define CSBannerSize_iPad     CGSizeMake(728.0f, 90.0f)

// Banner展现失败
typedef void (^CSBannerShowFailure)(CSRequestError *error);
// Banner将要显示
typedef void (^CSBannerWillPresent)();
// Banner移除完成
typedef void (^CSBannerDidDismiss)();

@protocol CSBannerViewDelegate;

// iPhone 和 iPod Touch Banner广告大小。目前只有一种 屏幕宽度x50.
// iPad Banner广告大小。目前只有一种 728x90.
@interface CSBannerView : UIView

@property (nonatomic, weak) id <CSBannerViewDelegate> delegate;

// Banner展现失败的block
@property (nonatomic, copy) CSBannerShowFailure showFailure;
// Banner将要显示的block
@property (nonatomic, copy) CSBannerWillPresent willPresent;
// Banner移除完成的block
@property (nonatomic, copy) CSBannerDidDismiss didDismiss;

/**
 *	@brief	加载Banner广告
 *
 *	@param 	csRequest 	请求Banner广告时的参数
 */
- (void)loadRequest:(CSADRequest *)csRequest;

@end


@protocol CSBannerViewDelegate <NSObject>

@optional

// Banner广告发出请求
- (void)csBannerViewRequestAD:(CSBannerView *)csBannerView;

// Banner广告展现失败
- (void)csBannerView:(CSBannerView *)csBannerView
         showAdError:(CSRequestError *)requestError;

// 将要展示Banner广告
- (void)csBannerViewWillPresentScreen:(CSBannerView *)csBannerView;

// 移除Banner广告
- (void)csBannerViewDidDismissScreen:(CSBannerView *)csBannerView;

@end
#endif
