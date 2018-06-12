//
//  MainScene.cpp
//  ppfrvr
//
//  Created by 赵勇 on 15/10/16.
//
//

#include "MainScene.h"
//#include "MainButton.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "IOSTools.h"
#endif

USING_NS_CC;

Scene* MainScene::createScene()
{
    //CCLOG("createScene");
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    auto layer = MainScene::create();
    scene->addChild(layer,1);
    
    auto colorlayer = LayerColor::create(Color4B(255, 255, 255,255));
    scene->addChild(colorlayer,0);
    
    // return the scene
    return scene;
}

void MainScene::onEnter()
{
    //CCLOG("onEnter");
    Layer::onEnter();
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}


bool MainScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    
    return true;
}

void MainScene::onEnterTransitionDidFinish()
{
    //CCLOG("MainScene_onEnterTransitionDidFinish");
    
    isSound=UserDefault::getInstance()->getBoolForKey("isSound", true);
    
    float buttonAutoScale;
    if (VisibleRect::right().x==640)
    {//iphone4,4s,5,5s
        buttonAutoScale=1;
    }
    else if(VisibleRect::right().x==768)
    {//ipad2
        buttonAutoScale=1;
    }
    else if(VisibleRect::right().x==1536)
    {//ipad3,ipad4,ipad air,
        buttonAutoScale=2;
    }
    else if(VisibleRect::right().x==750||VisibleRect::right().x==1080)
    {//iphone6
        buttonAutoScale=1;
    }
    else
    {//andorid
        buttonAutoScale=VisibleRect::right().x/640;
    }
    
    //确定方块宽度
    itemWidth=VisibleRect::right().x/12;
    if (VisibleRect::right().x==640||VisibleRect::right().x==750||VisibleRect::right().x==1080)
    {//iphone4,iphone5,iphone6,iphon6plus
        itemWidth=VisibleRect::right().x/12;
    }
    else if(VisibleRect::right().x==768)
    {//ipad
        itemWidth=VisibleRect::right().x*1/15;
    }
    else if(VisibleRect::right().x==1536)/////这是mainScene.cpp特殊处理，别的地方不是这样
    {//ipad air
        itemWidth=VisibleRect::right().x*1/30;
    }
    else if (VisibleRect::right().x==480)
    {//android常用分辨率1
        itemWidth=VisibleRect::right().x/12;
    }
    else if (VisibleRect::right().x==720)
    {//android常用分辨率1
        itemWidth=VisibleRect::right().x/12;
    }
    CCLOG("itemWidth===%f",itemWidth);
    
    auto label = LabelTTF::create("蜂巢方块消除", "Verdana-Bold", 90);
    label->setColor(Color3B(33,108,181));
    label->setScale(buttonAutoScale);
    label->setPosition(VisibleRect::center().x,VisibleRect::top().y*14/16);
    this->addChild(label, 1);
    
    ///////button1
    auto buttonbg=Sprite::create("touming512_128.png");
    //buttonbg->setColor(Color3B(32,32,30));
    buttonbg->setColor(Color3B(52,52,50));
    

    
    auto gamePauseButtonGoOn = MenuItemSprite::create(buttonbg, buttonbg, CC_CALLBACK_1(MainScene::menuCallback3GoOn, this) );
    gamePauseButtonGoOn->setScale(buttonAutoScale);
    gamePauseButtonGoOn->setPosition(VisibleRect::center().x,VisibleRect::top().y*11/16);
    //gamePauseButtonGoOn->setPosition(VisibleRect::center().x,VisibleRect::top().y*4/8);
    
    //auto lb = LabelTTF::create(("10 * 10"), "Verdana-Bold", 50);
    auto lb = LabelTTF::create(("进入游戏"), "Verdana-Bold", 50);
    lb->setColor(Color3B(255,255,255));
    lb->setPosition(buttonbg->getContentSize().width/2,buttonbg->getContentSize().height/2);
    gamePauseButtonGoOn->addChild(lb,2);
    
    auto t_item1=Sprite::create("tile.png");
    t_item1->setScaleX(itemWidth/t_item1->getContentSize().width);
    t_item1->setScaleY(itemWidth/t_item1->getContentSize().width);
    t_item1->setColor(Color3B(59, 203, 253));
    t_item1->setPosition(buttonbg->getContentSize().width/8,buttonbg->getContentSize().height/2);
    gamePauseButtonGoOn->addChild(t_item1,2);
    ////////////////
    
    ///////button2
    auto buttonbg2=Sprite::create("touming512_128.png");
    buttonbg2->setColor(Color3B(52,52,50));
    
    auto gamePauseButtonGoOn2 = MenuItemSprite::create(buttonbg2, buttonbg2, CC_CALLBACK_1(MainScene::menuCallback3GoOn2, this) );
    gamePauseButtonGoOn2->setPosition(VisibleRect::center().x,VisibleRect::top().y*4/8);
    gamePauseButtonGoOn2->setScale(buttonAutoScale);
    
    //auto lb2 = LabelTTF::create(("11 * 11"), "Verdana-Bold", 50);
    auto lb2 = LabelTTF::create(("夜间模式"), "Verdana-Bold", 50);
    lb2->setColor(Color3B(255,255,255));
    lb2->setPosition(buttonbg2->getContentSize().width/2,buttonbg2->getContentSize().height/2);
    gamePauseButtonGoOn2->addChild(lb2,2);
    
    
    auto t_item2=Sprite::create("tile.png");
    t_item2->setScaleX(itemWidth/t_item2->getContentSize().width);
    t_item2->setScaleY(itemWidth/t_item2->getContentSize().width);
    t_item2->setColor(Color3B(125, 110, 229));
    t_item2->setPosition(buttonbg->getContentSize().width/8,buttonbg->getContentSize().height/2);
    gamePauseButtonGoOn2->addChild(t_item2,2);
    ////////////////
    

    
    
    yinYueOnButton=MenuItemImage::create("sound@2x.png","sound@2x.png",CC_CALLBACK_1(MainScene::switchSound, this));
    yinYueOnButton->setPosition(VisibleRect::right().x*1/8, VisibleRect::top().y*1/8);
    yinYueOnButton->setScale(VisibleRect::right().x/1080*3/2);
    
    yinYueOffButton=MenuItemImage::create("soundOff@2x.png","soundOff@2x.png",CC_CALLBACK_1(MainScene::switchSound, this));
    yinYueOffButton->setPosition(VisibleRect::right().x*1/8, VisibleRect::top().y*1/8);
    yinYueOffButton->setScale(VisibleRect::right().x/1080*3/2);
    
    if (isSound)
    {
        yinYueOnButton->setVisible(true);
        yinYueOffButton->setVisible(false);
    }
    else
    {
        yinYueOnButton->setVisible(false);
        yinYueOffButton->setVisible(true);
    }
    
    
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
    auto paihangbangButton=MenuItemImage::create("score@2x.png","score@2x.png",CC_CALLBACK_1(MainScene::showLeaderboard, this));
    paihangbangButton->setPosition(VisibleRect::right().x*7/8, VisibleRect::top().y*1/8);
    paihangbangButton->setScale(VisibleRect::right().x/1080*3/2);
    
    auto pinglunButton = MenuItemImage::create("texturePackMenu@2x.png","texturePackMenu@2x.png",CC_CALLBACK_1(MainScene::pinglunFun, this));
    pinglunButton->setPosition(VisibleRect::right().x*4/8, paihangbangButton->getPosition().y-paihangbangButton->getContentSize().height/2+pinglunButton->getContentSize().height/2);
    pinglunButton->setScale(VisibleRect::right().x/1080*3/2);
    
    auto menu = Menu::create( gamePauseButtonGoOn,gamePauseButtonGoOn2,yinYueOnButton,yinYueOffButton,paihangbangButton,  NULL);
    menu->setPosition(0,0);
    addChild(menu,1);
#endif
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    auto menu = Menu::create( gamePauseButtonGoOn,gamePauseButtonGoOn2,gamePauseButtonGoOn2,yinYueOnButton,yinYueOffButton,  NULL);
    menu->setPosition(0,0);
    addChild(menu,1);
#endif
    
    
    
    
}


bool MainScene::onTouchBegan(Touch *touch, Event *event)
{
    return true;
}

void MainScene::onTouchMoved(Touch *touch, Event *event)
{
    
}

void MainScene::onTouchEnded(Touch *touch, Event *event)
{
    
}

void MainScene::menuCallback3GoOn(Ref* sender)
{//进入游戏10*10
    //CCLOG("menuCallback3GoOn");
    
    M3AudioManager::shareInstance()->playSound(2);
    auto sc = SceneControl::create();
    sc->toGame1();
}

void MainScene::menuCallback3GoOn2(Ref* sender)
{//进入游戏11*11
    //CCLOG("menuCallback3GoOn2");
    M3AudioManager::shareInstance()->playSound(2);
    auto sc = SceneControl::create();
    sc->toGame2();
}

void MainScene::menuCallback3GoOn3(Ref* sender)
{//进入游戏下落消除
    CCLOG("menuCallback3GoOn3");
    M3AudioManager::shareInstance()->playSound(2);
    //auto sc = SceneControl::create();
    //sc->toGame3();
}

void MainScene::showLeaderboard(Ref* sender)
{//打开排行榜界面
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    M3AudioManager::shareInstance()->playSound(2);
    IOSTools::GameCenterShow();
#endif
    
}

void MainScene::pinglunFun(Ref* sender)
{//打开评论界面
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    M3AudioManager::shareInstance()->playSound(2);
    IOSTools::pinglunFun();
#endif
}

void MainScene::switchSound(Ref* sender)
{//切换音乐开关
    
    
    
    isSound=UserDefault::getInstance()->getBoolForKey("isSound", true);
    CCLOG("switchSound11111111=====%d",isSound);
    if (isSound)
    {
        UserDefault::getInstance()->setBoolForKey("isSound", false);
        
    }
    else
    {
        M3AudioManager::shareInstance()->playSound(2);
        UserDefault::getInstance()->setBoolForKey("isSound", true);
    }
    isSound=UserDefault::getInstance()->getBoolForKey("isSound", true);
    if (isSound)
    {
        yinYueOnButton->setVisible(true);
        yinYueOffButton->setVisible(false);
    }
    else
    {
        yinYueOnButton->setVisible(false);
        yinYueOffButton->setVisible(true);
    }
    CCLOG("switchSound222222222=====%d",isSound);
    
}

