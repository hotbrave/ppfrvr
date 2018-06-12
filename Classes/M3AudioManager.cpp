/*
 * M3AudioManager.cpp
 *
 *  Created on: 2013-1-24
 *      Author: alex
 */

#include "M3AudioManager.h"
#include "SimpleAudioEngine.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "../../cocos2dx/platform/android/jni/JniHelper.h"
#include "jni.h"
#endif

USING_NS_CC;

static M3AudioManager* instance = NULL;

M3AudioManager* M3AudioManager::shareInstance(){
	if(!instance){
		instance = new M3AudioManager();
		instance->init();
	}
	return instance;
}

bool M3AudioManager::init(){
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("xpg_djt.mp3");
    //CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("xpg_djt.mp3");
//	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("glassbroken.mp3");
	return true;
}

void M3AudioManager::playBackground(){
    int musicType = arc4random() % 2; //获取0到x-1之间的整数
    CCLOG("musicType===%d",musicType);
    if (musicType%2==1) {
        CCLOG("xpg_gq.mp3");
        //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("xpg_gq.mp3", false);
        
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("xpg_gq.mp3",true);
    }
    else
    {
        CCLOG("xpg_djt.mp3");
        //CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("xpg_djt.mp3", false);
        CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("xpg_djt.mp3",true);
        
    }
    

}

void M3AudioManager::stopBackground(){
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

void M3AudioManager::pauseBackground(){
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}


void M3AudioManager::resumeBackground(){
	if(UserDefault::getInstance()->getBoolForKey("soundSwitch")){
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	}
}


bool M3AudioManager::isPlayBackground()
{//是否正在播放
    return CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying();
    //return CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying();
    
}

void M3AudioManager::rePlayBackground()
{//如果背景音乐结束，播放一个新的背景音乐
    //CCLOG("rePlayBackground====222");
    bool isMusic=UserDefault::getInstance()->getBoolForKey("music",true);//音乐是否打开
    
    
    CCLOG("isMusic===%d",isMusic);
    CCLOG("isPlayBackground()===%d",isPlayBackground());
    if (isMusic&&!isPlayBackground()) {
        playBackground();
    }
}


void M3AudioManager::playSound(int num){
	std::string path;
	
    switch (num) {
        case 0:
            path = "popin.wav";//方块落下
            break;
        case 1:
            path = "delete1.mp4";//方块消除
            break;
        case 2:
            //path = "Click_All.caf";//点击按钮
            path = "button_click.mp3";
            break;
        case 3:
            path = "lose_game.mp3";//游戏结束
            break;
        case 4:
            //path = "woosh.mp3";//方块出场
            break;
        case 5:
            path = "down.mp3";//方块放置位置不正确，返回初始位置
            break;
        case 6:
            path = "win_game.mp3";//超过历史最高纪录
            break;

            
        default:
            break;
    }
 
	if(UserDefault::getInstance()->getBoolForKey("isSound",true)){
        
		//CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(path.c_str());
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(path.c_str());
	}
}

M3AudioManager::~M3AudioManager(){
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->end();
    CocosDenshion::SimpleAudioEngine::getInstance()->end();
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C"{
//	void Java_com_m3java_braveheart_BraveHeart_nativePauseBackground(){
//		M3AudioManager::pauseBackground();
//	}
}
#endif
