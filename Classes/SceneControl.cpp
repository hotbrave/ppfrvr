//
//  SceneControl.cpp
//  kxty
//
//  Created by 赵勇 on 14-7-12.
//
//

#include "SceneControl.h"
#include "GameOverScene.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#include <android/log.h>
#endif

#include "MainScene.h"
#include "GameScene.h"


USING_NS_CC;

bool SceneControl::init(){
    return true;
}

void SceneControl::toMain(){
    auto* scene = MainScene::createScene();
    Director::getInstance()->replaceScene(TransitionFlipX::create(0.5f,scene, TransitionScene::Orientation::LEFT_OVER));
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        IOSTools::hideAd();//多盟广告
    //CCLOG("隐藏广告11111a");
    #endif
}

void SceneControl::toGameOver(){

}


void SceneControl::toGame1(){
    //UserDefault::sharedUserDefault()->getBoolForKey("UDisNightMode",0);
    UserDefault::getInstance()->setBoolForKey("UDisNightMode", false);
    auto* scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFlipX::create(0.5f,scene, TransitionScene::Orientation::RIGHT_OVER));
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    //CCLOG("显示广告11111a");
        IOSTools::showAd();//多盟广告
    #endif
}

void SceneControl::toGame2(){
    UserDefault::getInstance()->setBoolForKey("UDisNightMode", true);
    auto* scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFlipX::create(0.5f,scene, TransitionScene::Orientation::RIGHT_OVER));
    
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCLOG("显示广告11111b");
        IOSTools::showAd();//多盟广告
    #endif
}








