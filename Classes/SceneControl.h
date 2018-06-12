//
//  SceneControl.h
//  kxty
//
//  Created by 赵勇 on 14-7-12.
//
//

#ifndef __kxty__SceneControl__
#define __kxty__SceneControl__

#include "cocos2d.h"
#include "GameScene.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "IOSTools.h"
#endif

class SceneControl : public cocos2d::Ref{
public:
    virtual bool init();
    void toMain();
    void toGameOver();
    void toWin();
    void toLoading();
    void toLevel();
    void toPassLevel();
    void toHelp();
    void androidBack();
    
    void toGame1();//进入游戏10*10
    void toGame2();//进入游戏11*11
    //void toGame3();//进入游戏下落消除
    //void toGame4();//下落游戏再重玩
    
    CREATE_FUNC(SceneControl);
};

#endif /* defined(__kxty__SceneControl__) */
