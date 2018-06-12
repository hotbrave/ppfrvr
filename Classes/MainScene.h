//
//  MainScene.h
//  ppfrvr
//
//  Created by 赵勇 on 15/10/16.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "VisibleRect.h"
#include "SceneControl.h"
#include "M3AudioManager.h"

class MainScene : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual void onEnter();
    virtual bool init();
    
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    
    void menuCallback3GoOn(Ref* sender);//继续游戏10*10
    void menuCallback3GoOn2(Ref* sender);//继续游戏11*11
    void menuCallback3GoOn3(Ref* sender);//继续游戏下落消除
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
    void onEnterTransitionDidFinish();
    
    void showLeaderboard(Ref* sender);//打开排行榜界面
    void pinglunFun(Ref* sender);//打开评论界面
    void switchSound(Ref* sender);//切换音乐开关
    bool isSound;//音乐是否打开
    MenuItemImage* yinYueOnButton;
    MenuItemImage* yinYueOffButton;
    
    float itemWidth;//节点宽度
    
};

#endif /* MainScene_h */
