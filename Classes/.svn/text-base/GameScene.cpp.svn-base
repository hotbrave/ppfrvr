//
//  GameScene.cpp
//  ppfrvr
//
//  Created by 赵勇 on 15/10/16.
//
//

#include "GameScene.h"


USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    auto layer = GameScene::create();
    scene->addChild(layer,1);
    
    //isNightMode=true;//开启夜间模式
    //bool isNightMode=false;//关闭夜间模式
    
    auto colorlayer = LayerColor::create(Color4B(32, 32, 30,255));
    
    bool isNightMode=UserDefault::getInstance()->getBoolForKey("UDisNightMode",0);
    
    if (isNightMode)
    {
        colorlayer = LayerColor::create(Color4B(32, 32, 30,255));
    }
    else
    {
        colorlayer = LayerColor::create(Color4B(255, 255, 255,255));
    }
    
    scene->addChild(colorlayer,0);
    
    // return the scene
    return scene;
}

void GameScene::onEnter()
{
    Layer::onEnter();
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
}

bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    return true;
}


void GameScene::onEnterTransitionDidFinish()
{
    initmyGame();
}

void GameScene::initmyGame()
{//初始化游戏

    //isNightMode=true;//开启夜间模式
    //isNightMode=false;//关闭夜间模式
    isNightMode=UserDefault::getInstance()->getBoolForKey("UDisNightMode",0);
    
    isPause=true;//刚进入游戏不能点击方块
    isgameOver=false;
    addScore=0;
    score=0;
    topScore=UserDefault::getInstance()->getIntegerForKey("topScore",0);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    CCLOG("topScore10====%d",topScore);
    //每次启动游戏的时候再提交一次最高分，防止网络不好的时候提交最高分失败
    IOSTools::GameCenterSendScore10(topScore);
#endif
    
    CCLOG("screenWidth====%f screenHeight===%f",VisibleRect::right().x,VisibleRect::top().y);
    
    for (int x=0; x<Grid5Size9; x++)
    {//初始化数组，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        for (int y=0; y<Grid5Size9; y++)
        {
            for (int z=0; z<Grid5Size9; z++)
            {
                intcells9[x][y][z]=cellStatus2;
            }
            
        }
    }
    
    
    
    ///////////填充空格begin////
    //int mycount2=0;
    for (int z=0; z<Grid5Size9; z++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        for (int x=0; x<Grid5Size9; x++)
        {
            //
            int y=z-4+x;
            if (y>=0&&y<Grid5Size9)
            {
                //CCLOG("mycount2==%d x=====%d y====%d z====%d",mycount2,x,y,z);
                //mycount2++;
                
                intcells9[x][y][z]=cellStatus0;
                
            }
            
        }
    }
    ///////////填充空格end////
    
    arrayFK = __Array::create();
    CC_SAFE_RETAIN(arrayFK);
    
    arrayRemoveFK = __Array::create();
    CC_SAFE_RETAIN(arrayRemoveFK);
    
    //确定方块宽度
    itemWidth=VisibleRect::right().x/12;
    if (VisibleRect::right().x==640||VisibleRect::right().x==750||VisibleRect::right().x==1080)
    {//iphone4,iphone5,iphone6,iphon6plus
        itemWidth=VisibleRect::right().x/12;
    }
    else if(VisibleRect::right().x==768||VisibleRect::right().x==1536)
    {//ipad
        itemWidth=VisibleRect::right().x*1/15;
    }
    else if (VisibleRect::right().x==480)
    {//android常用分辨率1
        itemWidth=VisibleRect::right().x/12;
    }
    else if (VisibleRect::right().x==720)
    {//android常用分辨率1
        itemWidth=VisibleRect::right().x/12;
    }
    
    //确定分数高度
    float labelHeight=VisibleRect::top().y-VisibleRect::right().x/8*8/8;
    if (VisibleRect::top().y==960||VisibleRect::top().y==1024||VisibleRect::top().y==2048)
    {//iphone4,iphone4s,ipad2,ipad air
        labelHeight=VisibleRect::top().y-VisibleRect::right().x/8*8/8;
        CCLOG("iphone4,iphone4s,ipad2,ipad air");
    }
    else
    {
        labelHeight=VisibleRect::top().y-VisibleRect::right().x/8*10/8;
        CCLOG("no iphone4");
    }
    CCLOG("itemWidth===%f",itemWidth);

    ///////////绘制棋盘begin////
    //int mycount3=0;
    for (int z=0; z<Grid5Size9; z++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        for (int x=0; x<Grid5Size9; x++)
        {
            //
            int y=z-4+x;
            if (y>=0&&y<Grid5Size9)
            {
                //CCLOG("mycount2==%d x=====%d y====%d z====%d",mycount3,x,y,z);
                //mycount3++;
                
                //intcells9[x][y][z]=0;
                auto itembg=Sprite::create("tile2.png");
                
                itembg->setScaleX(itemWidth/itembg->getContentSize().width);
                itembg->setScaleY(itemWidth/itembg->getContentSize().width);
                if (isNightMode)
                {
                    itemBG=Color3B(90,90,90);
                }
                else
                {
                    itemBG=Color3B(210,210,210);
                }
                
                itembg->setColor(itemBG);
                itembg->setPosition(getTruePositionByXYZ(x,y,z));
                addChild(itembg,layerNum1);
                arrayQiPanbg[x][y][z]=itembg;
            }
            
        }
    }
    ///////////绘制棋盘end////
    
    /////////20160602恢复上一局游戏begin/////////////
    
    /*
    char * data=gatGrid();
    const char *d = " ,*";
    char *ppp;
    ppp = strtok(data,d);//分解字符串
    
    
    bool isHuiFu=false;//是否有可以恢复的值
    for (int x = 0; x < GridSize10; x++)
    {
        for (int y = 0; y <GridSize10; y++)
        {
            //removeChild(((Item*)array2Item[x][y]));
            //array2Item[x][y]=NULL;
            
            int tempvalue=0;
            if (ppp!=NULL)
            {
                tempvalue=atoi(ppp);//char * 转 int
            }
            //CCLOG("x====%d y====%d ppp====%s  tempvalue===%d",x,y,ppp,tempvalue);
            
            //grid->updateintcells(x, y, tempvalue);
            bgItemColorArray[x][y]=tempvalue;
            intcells10[x][y]=bgItemColorArray[x][y];
            
            if (bgItemColorArray[x][y]!=0)
            {
                //CCLOG("x====%d y====%disHuiFu111111111111111111111",x,y);
                //CCLOG("bgItemColorArray[%d][%d]=======%d",x,y,bgItemColorArray[x][y]);
                isHuiFu=true;
                
                
                 //Item* item=Item::create();
                 //item->initItem(x, y, grid->getintcells(x, y),51.5*bgScale,4);
                 
                 //array2Item[x][y]=item;
                 //showRandomTile(item);
                
            }
            ppp=strtok(NULL,d);
            
        }
    }
    
    */
    /////////20160602恢复上一局游戏end/////////////
    
    
    ////////////绘制分数板begin
    ltopScore=LTitle::create();
    ltopScore->initItem(VisibleRect::right().x/4, VisibleRect::right().x/8, Color3B(206,232,238), Color3B(52,147,202), topScore);//月白  	 靛青
    ltopScore->setPosition(VisibleRect::center().x*3/8, labelHeight);
    addChild(ltopScore,2);
    
    lscore=LTitle::create();
    lscore->initItem(VisibleRect::right().x/4, VisibleRect::right().x/8, Color3B(206,232,238), Color3B(77,205,146), score);//月白  	竹青
    lscore->setPosition(VisibleRect::center().x, ltopScore->getPosition().y);
    addChild(lscore,2);
    ////////////绘制分数板end
    
    buttonPause = MenuItemImage::create("pause@2x.png", "pause@2x.png", CC_CALLBACK_1(GameScene::menuCallback4Pause, this) );
    buttonPause->setScale(VisibleRect::right().x/500);
    buttonPause->setPosition(VisibleRect::center().x*14/8,ltopScore->getPosition().y);
    auto menu = Menu::create( buttonPause,  NULL);
    menu->setPosition(0,0);
    addChild(menu,1);

    if (score>0)
    {
        CCLOG("恢复游戏");
        huifuNFKitem(itemWidth);
    }
    else
    {
        CCLOG("新游戏创建3个方块");
        create3FKitem(itemWidth);
    }
    
    
    //////////////////gameOver界面begin
    layerColorGameOver=LayerColor::create(Color4B(0xff, 0xff, 0xff, 0xc8));//Color4B
    layerColorGameOver->setVisible(false);
    addChild(layerColorGameOver,5);
    
    auto jiangbei=Sprite::create("jiangbei.png");
    jiangbei->setScale(itemWidth*2/jiangbei->getContentSize().height);//
    jiangbei->setColor(Color3B(77,205,146));
    jiangbei->setPosition(VisibleRect::center().x,VisibleRect::top().y*6/8);
    layerColorGameOver->addChild(jiangbei);
    
    gameOverlscore=LTitle::create();
    gameOverlscore->initItem(VisibleRect::right().x/4*4/3, VisibleRect::right().x/8*4/3, Color3B(206,232,238), Color3B(77,205,146), score);//月白  	竹青
    gameOverlscore->setPosition(VisibleRect::center().x, VisibleRect::top().y*5/8);
    layerColorGameOver->addChild(gameOverlscore);
    
    auto gameOverButtonReStart = MenuItemImage::create("pauseRestart@2x.png", "pauseRestart@2x.png", CC_CALLBACK_1(GameScene::menuCallback1ReStart, this) );
    gameOverButtonReStart->setScale(VisibleRect::right().x/1080*3/2);
    gameOverButtonReStart->setPosition(VisibleRect::center().x,VisibleRect::top().y*3/8);
    auto gameOverMenu = Menu::create( gameOverButtonReStart,  NULL);
    gameOverMenu->setPosition(0,0);
    layerColorGameOver->addChild(gameOverMenu);
    //////////////////gameOver界面end
    
    
    
    /////////////暂停界面begin/////
    //layerColorGamePause=LayerColor::create(Color4B(0xff, 0xff, 0xff, 0xc8));//Color4B
    layerColorGamePause=LayerColor::create(Color4B(0, 0, 0, 0xc8));
    layerColorGamePause->setVisible(false);
    addChild(layerColorGamePause,5);
    
    gamePauseButtonHome = MenuItemImage::create("home@2x.png", "home@2x.png", CC_CALLBACK_1(GameScene::menuCallback2ToMain, this) );
    gamePauseButtonHome->setScale(VisibleRect::right().x/1080*3/2);
    //gamePauseButtonHome->setPosition(VisibleRect::right().x*1/4,VisibleRect::top().y*3/8);
    gamePauseButtonHome->setPosition(-gamePauseButtonHome->getContentSize().width,VisibleRect::top().y*3/8-gamePauseButtonHome->getContentSize().height);
    
    gamePauseButtonReStart = MenuItemImage::create("pauseRestart@2x.png", "pauseRestart@2x.png", CC_CALLBACK_1(GameScene::menuCallback1ReStart, this) );
    gamePauseButtonReStart->setScale(VisibleRect::right().x/1080*3/2);
    //gamePauseButtonReStart->setPosition(VisibleRect::right().x/2,VisibleRect::top().y*3/8);
    gamePauseButtonReStart->setPosition(VisibleRect::right().x/2+gamePauseButtonReStart->getContentSize().width,-gamePauseButtonReStart->getContentSize().height);
    
    gamePauseButtonGoOn = MenuItemImage::create("pausePlay@2x.png", "pausePlay@2x.png", CC_CALLBACK_1(GameScene::menuCallback3GoOn, this) );
    gamePauseButtonGoOn->setScale(VisibleRect::right().x/1080*3/2);
    //gamePauseButtonGoOn->setPosition(VisibleRect::right().x*3/4,VisibleRect::top().y*3/8);
    gamePauseButtonGoOn->setPosition(VisibleRect::right().x+gamePauseButtonGoOn->getContentSize().width,VisibleRect::top().y*3/8+gamePauseButtonGoOn->getContentSize().height);
    
    
    auto gamePauseMenu = Menu::create( gamePauseButtonHome,gamePauseButtonReStart,gamePauseButtonGoOn,  NULL);
    gamePauseMenu->setPosition(0,0);
    layerColorGamePause->addChild(gamePauseMenu);
    /////////////暂停界面end/////
    
}

void GameScene::createandMoveFKitem(float itemWidth,int pCountvv)
{//创造1个方块,并移动(拼完一个方块后调用)
    
    M3AudioManager::shareInstance()->playSound(4);
    
    int randomChengCount3=(arc4random() %randomCount);    //产生0-18的随机数  //测试随机正确2014-11-18
    //CCLOG("randomChengCount1======%d",randomChengCount3);
    
    
    Ref* obj = nullptr;
    CCARRAY_FOREACH(arrayFK,obj)
    {
        auto tempItem = static_cast<FKItem*>(obj);//将obj强制转换成FKItem
       
        //CCLOG(" tempItem->getPostioncount()===%d", tempItem->getPostioncount());
        if (tempItem->getPostioncount()==postionCount2&&pCountvv==postionCount1)
        {
            Vect impulse1 = Vect(VisibleRect::right().x/4, VisibleRect::top().y*3/16);
            auto moveto1=MoveTo::create(0.7/3, impulse1);
            tempItem->runAction(moveto1);
            tempItem->setPostionCount(postionCount1);
        }
        
        if (tempItem->getPostioncount()==postionCount3&&(pCountvv==postionCount1||pCountvv==postionCount2))
        {
            Vect impulse2 = Vect(VisibleRect::right().x/2, VisibleRect::top().y*3/16);
            auto moveto2=MoveTo::create(0.7/3, impulse2);
            tempItem->runAction(moveto2);
            tempItem->setPostionCount(postionCount2);
        }
        /*
        switch (tempItem->getPostioncount())
        {
            case postionCount2:
                Vect impulse1 = Vect(VisibleRect::right().x/4, VisibleRect::top().y*3/16);
                auto moveto1=MoveTo::create(0.7, impulse1);
                tempItem->runAction(moveto1);
                break;

                
            case postionCount3:
                Vect impulse2 = Vect(VisibleRect::right().x/2, VisibleRect::top().y*3/16);
                auto moveto2=MoveTo::create(0.7, impulse2);
                tempItem->runAction(moveto2);
                break;
                
            default:
                break;
        }
        */
    }
    
    /*
    auto tempFK1=createFKitem(itemWidth,randomValue[randomChengCount1],VisibleRect::right().x*5/4, VisibleRect::top().y*3/16);
    Vect impulse1 = Vect(VisibleRect::right().x/4, VisibleRect::top().y*3/16);
    auto moveto1=MoveTo::create(0.7, impulse1);
    auto seq = Sequence::create(moveto1,CallFuncN::create( CC_CALLBACK_1(GameScene::setPause, this, false)),nullptr);
    tempFK1->runAction(seq);
    tempFK1->screenX=VisibleRect::right().x/4;
    */
    auto tempFK3=createFKitem(itemWidth,randomValue[randomChengCount3],VisibleRect::right().x*5/4, VisibleRect::top().y*3/16,postionCount3);
    Vect impulse3 = Vect(VisibleRect::right().x*3/4, VisibleRect::top().y*3/16);
    auto moveto3=MoveTo::create(0.7/3, impulse3);
    tempFK3->runAction(moveto3);
    tempFK3->screenX=VisibleRect::right().x*3/4;

    
    

    
    
}


void GameScene::huifuNFKitem(float itemWidth)
{//保存游戏时恢复方块的方法
    
    /*
    
    int temp_moveFK_1=UserDefault::getInstance()->getIntegerForKey(save_moveFK_1,-1);//获取10棋盘的第1个可以移动的方块
    
    int temp_moveFK_2=UserDefault::getInstance()->getIntegerForKey(save_moveFK_2,-1);//获取10棋盘的第2个可以移动的方块
    
    int temp_moveFK_3=UserDefault::getInstance()->getIntegerForKey(save_moveFK_3,-1);//获取10棋盘的第3个可以移动的方块
    
    
    
    if (temp_moveFK_1>0)
    {
        auto tempFK1=createFKitem(itemWidth,temp_moveFK_1,VisibleRect::right().x*5/4, VisibleRect::top().y*3/16);
        tempFK1->setPosType(itemPosType1);
        Vect impulse1 = Vect(VisibleRect::right().x/4, VisibleRect::top().y*3/16);
        auto moveto1=MoveTo::create(0.7, impulse1);
        auto seq1 = Sequence::create(moveto1,CallFuncN::create( CC_CALLBACK_1(GameScene::setPause, this, false)),nullptr);
        tempFK1->runAction(seq1);
        tempFK1->screenX=VisibleRect::right().x/4;
    }
    
    if (temp_moveFK_2>0)
    {
        auto tempFK2=createFKitem(itemWidth,temp_moveFK_2,VisibleRect::right().x*3/2, VisibleRect::top().y*3/16);
        tempFK2->setPosType(itemPosType2);
        Vect impulse2 = Vect(VisibleRect::right().x/2, VisibleRect::top().y*3/16);
        auto moveto2=MoveTo::create(0.7, impulse2);
        auto seq2 = Sequence::create(moveto2,CallFuncN::create( CC_CALLBACK_1(GameScene::setPause, this, false)),nullptr);
        tempFK2->runAction(seq2);
        tempFK2->screenX=VisibleRect::right().x/2;
    }
    
    
    if (temp_moveFK_3>0)
    {
        auto tempFK3=createFKitem(itemWidth,temp_moveFK_3,VisibleRect::right().x*7/4, VisibleRect::top().y*3/16);
        tempFK3->setPosType(itemPosType3);
        Vect impulse3 = Vect(VisibleRect::right().x*3/4, VisibleRect::top().y*3/16);
        auto moveto3=MoveTo::create(0.7, impulse3);
        auto seq3 = Sequence::create(moveto3,CallFuncN::create( CC_CALLBACK_1(GameScene::setPause, this, false)),nullptr);
        tempFK3->runAction(seq3);
        tempFK3->screenX=VisibleRect::right().x*3/4;
    }
    
    */
    
}

void GameScene::create3FKitem(float itemWidth)
{//创造3个方块
    
    M3AudioManager::shareInstance()->playSound(4);
    /*
    const int randomCount=58;//随机数数组里面的元素个数
    int randomValue[randomCount] = {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        21,21,21,
        22,22,22,
        23,23,23,
        31,
        32,
        33,
        34,
        35,
        36,
        41,
        42,
        43,
        44,
        45,
        46,
        51,51,51,
        52,52,52,
        53,53,53,
        61,
        62,
        63,
        64,
        65,
        66
    };
    */
    int randomChengCount1=(arc4random() %randomCount);  //产生0-18的随机数  //测试随机正确2014-11-18
    int randomChengCount2=(arc4random() %randomCount);  //产生0-18的随机数
    int randomChengCount3=(arc4random() %randomCount);  //产生0-18的随机数
    
    //CCLOG("randomChengCount1======%d",randomChengCount1);
    //CCLOG("randomChengCount2======%d",randomChengCount2);
    //CCLOG("randomChengCount3======%d",randomChengCount3);
    
    
    auto tempFK1=createFKitem(itemWidth,randomValue[randomChengCount1],VisibleRect::right().x*5/4, VisibleRect::top().y*3/16,postionCount1);
    Vect impulse1 = Vect(VisibleRect::right().x/4, VisibleRect::top().y*3/16);
    auto moveto1=MoveTo::create(0.7, impulse1);
    auto seq = Sequence::create(moveto1,CallFuncN::create( CC_CALLBACK_1(GameScene::setPause, this, false)),nullptr);
    tempFK1->runAction(seq);
    tempFK1->screenX=VisibleRect::right().x/4;
    
    auto tempFK2=createFKitem(itemWidth,randomValue[randomChengCount2],VisibleRect::right().x*3/2, VisibleRect::top().y*3/16,postionCount2);
    Vect impulse2 = Vect(VisibleRect::right().x/2, VisibleRect::top().y*3/16);
    auto moveto2=MoveTo::create(0.7, impulse2);
    tempFK2->runAction(moveto2);
    tempFK2->screenX=VisibleRect::right().x/2;
    
    auto tempFK3=createFKitem(itemWidth,randomValue[randomChengCount3],VisibleRect::right().x*7/4, VisibleRect::top().y*3/16,postionCount3);
    Vect impulse3 = Vect(VisibleRect::right().x*3/4, VisibleRect::top().y*3/16);
    auto moveto3=MoveTo::create(0.7, impulse3);
    tempFK3->runAction(moveto3);
    tempFK3->screenX=VisibleRect::right().x*3/4;
}

FKItem* GameScene::createFKitem(float itemWidth,int type,float truex,float truey,int pCountv)
{//创造各种方块
    auto tempFK=FKItem::create();
    tempFK->initItem(-1,-1,-1,truex,truey, type, itemWidth, color0,pCountv);
    tempFK->setScale(0.6);
    tempFK->setPosition(truex, truey);
    addChild(tempFK,layerNum3);
    arrayFK->addObject(tempFK);
    return tempFK;
}

void GameScene::setPause(Node* sender,bool flag)
{
    //CCLOG("setPause====%d",flag);
    isPause=flag;
}

bool GameScene::onTouchBegan(Touch *touch, Event *event)
{
    

    if (!isgameOver&&!isPause)
    {
        Point touchLocation = this->convertTouchToNodeSpace(touch);
        selectSpriteForTouch(touchLocation);
    }
 
    return true;
}

void GameScene::onTouchMoved(Touch *touch, Event *event)
{
    
    if (!isgameOver&&!isPause)
    {
        if (moveFKItem!=NULL)
        {
            Point touchLocation = this->convertTouchToNodeSpace(touch);
            touchLocation.add(Vec2(0,itemWidth*3));
            moveFKItem->setPosition(touchLocation);
        }
    }
    
}

void GameScene::onTouchEnded(Touch *touch, Event *event)
{
    if (!isgameOver&&!isPause)
    {
        
        if (moveFKItem!=NULL)
        {
            Point touchLocation = this->convertTouchToNodeSpace(touch);
            touchLocation.add(Vec2(0,itemWidth*3));//向上移动后再计算方块的实际位置
            
            //Ref* obj = nullptr;
            float tempDistance=0;
            float resultDistance=10000;
            int resultX;
            int resultY;
            int resultZ;
            
            bool hebingFlag=false;//方块是否可以合并到棋盘上
            bool isMoveFlag=true;//是否将方块移动回初始位置
            
            /*
            for (int x=0; x<GridSize10; x++)
            {
                for (int y=0; y<GridSize10; y++)
                {
                    auto tempItem = (Item*)arraybg2Item[x][y];//将obj强制转换成FKItem
                    tempDistance=touchLocation.distance(Vect(tempItem->screenX-moveFKItem->beginX*itemWidth, tempItem->screenY-moveFKItem->beginY*itemWidth));
                    if (tempDistance<resultDistance)
                    {
                        resultDistance=tempDistance;
                        if (resultDistance<itemWidth*3/4)
                        {
                            hebingFlag=true;
                            resultX=x;
                            resultY=y;
                        }
                        else
                        {
                            //CCLOG("离棋盘太远不能合并");
                        }
                        
                    }
                }
                //
            }
            */
            
            
            ////////判断落点在棋盘哪个格子上begin
            //int mycount4=0;
            for (int z=0; z<Grid5Size9; z++)
            {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
                for (int x=0; x<Grid5Size9; x++)
                {
                    //
                    int y=z-4+x;
                    if (y>=0&&y<Grid5Size9)
                    {
                        //CCLOG("mycount4==%d x=====%d y====%d z====%d",mycount4,x,y,z);
                        //mycount4++;
                        tempDistance=touchLocation.distance(getTruePositionByXYZ(x,y,z));
                        //tempDistance=touchLocation.distance(Vect(getTruePositionByXYZ(x,y,z).x,getTruePositionByXYZ(x,y,z).y-itemWidth*3));
                        if (tempDistance<resultDistance)
                        {
                            resultDistance=tempDistance;
                            if (resultDistance<itemWidth*3/4)
                            {
                                
                                hebingFlag=true;
                                resultX=x;
                                resultY=y;
                                resultZ=z;
                                CCLOG("resultX===%d resultY===%d resultZ==%d",resultX,resultY,resultZ);
                                
                                ////todo,落点有时会出来2个
                            }
                            else
                            {
                                //CCLOG("离棋盘太远不能合并");
                            }
                            
                        }

                    }
                    
                }
            }
            ////////判断落点在棋盘哪个格子上end
            
            
            
            if (hebingFlag)
            {
                CCLOG("可以开始判断合并");
                moveFKItem->chessX=resultX;
                moveFKItem->chessY=resultY;
                moveFKItem->chessZ=resultZ;
                
                float moveTime=0.14;
                float scaleTime=0.07;
                if (resultX>=0&&resultX<Grid5Size9&&resultY>=0&&resultY<Grid5Size9&&resultZ>=0&&resultZ<Grid5Size9)
                {
                    //
                    switch (moveFKItem->type)
                    {//针对不同的方块判断是否可以合并到棋盘上
                        case 1:
                            //口
                            if (intcells9[resultX][resultY][resultZ]==cellStatus0)
                            {
                                //可以合并
                                isMoveFlag=false;
                                addScore=addScore+1;
                                auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                
                                auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                moveFKItem->runAction(seq);
                                intcells9[resultX][resultY][resultZ]=cellStatus1;
                                
                                arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                            }
                            break;
                            
                        case 21:
                            //CCLOG("type===21");
                            //口
                            // 口
                            //  口
                            //   口
                            if (resultX-2>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+2<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-2][resultY][resultZ+2]==cellStatus0&&
                                    intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-2][resultY][resultZ+2]=cellStatus1;
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                        
                            
                            break;
                            
                        case 22:
                            //   口
                            //  口
                            // 口
                            //口
                            if (resultX>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+2<Grid5Size9&&resultZ-1>=0&&resultZ+2<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX][resultY+2][resultZ+2]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX][resultY+2][resultZ+2]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            break;
                            
                        case 23:
                            //口口口口
                            
                            if (resultX-2>=0&&resultX+1<Grid5Size9&&resultY-2>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-2][resultY-2][resultZ]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-2][resultY-2][resultZ]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            
                            break;
                            
                        case 31:
                            //口口
                            // 口
                            //   口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 32:
                            // 口
                            //口口口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 33:
                            //    口
                            //口 口
                            // 口
                            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 34:
                            // 口
                            //  口
                            //口 口
                            
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            
                            break;
                            
                        case 35:
                            //口 口 口
                            //    口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 36:
                            //   口
                            // 口  口
                            //口
                            if (resultX>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                            
                        case 41:
                            //口 口
                            // 口
                            //口
                            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 42:
                            // 口
                            //口 口
                            //    口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 43:
                            //口口口
                            // 口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 44:
                            //  口
                            // 口
                            //口口
                            if (resultX>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 45:
                            //口
                            // 口 口
                            //  口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 46:
                            //    口
                            // 口口 口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                            
                        case 51:
                            // 口口
                            //口口
                            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 52:
                            //口口
                            //  口口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 53:
                            // 口
                            //口口
                            // 口
                            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                            
                        case 61:
                            // 口
                            //   口
                            //口口
                            if (resultX>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                        case 62:
                            //口   口
                            //  口口
                            
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            
                            break;
                            
                        case 63:
                            // 口
                            //口
                            // 口口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                        case 64:
                            // 口口
                            //口
                            // 口
                            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX][resultY-1][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                        case 65:
                            // 口口
                            //口   口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX-1][resultY-1][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        case 66:
                            //口口
                            //   口
                            //  口
                            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
                            {//不能合并到棋盘外
                                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0)
                                {
                                    //
                                    //可以合并
                                    isMoveFlag=false;//不移回原点
                                    addScore=addScore+4;
                                    auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                    auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                    
                                    auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                    moveFKItem->runAction(seq);
                                    intcells9[resultX-1][resultY][resultZ+1]=cellStatus1;
                                    intcells9[resultX][resultY+1][resultZ+1]=cellStatus1;
                                    intcells9[resultX+1][resultY+1][resultZ]=cellStatus1;
                                    intcells9[resultX+1][resultY][resultZ-1]=cellStatus1;
                                    
                                    arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                    arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                                }
                            }
                            
                            
                            break;
                            
                        default:
                            //口
                            if (intcells9[resultX][resultY][resultZ]==cellStatus0)
                            {
                                //可以合并
                                isMoveFlag=false;
                                addScore=addScore+1;
                                auto moveto=MoveTo::create(moveTime, getTruePositionByXYZ(resultX,resultY,resultZ));
                                auto scaleYuan=ScaleTo::create(scaleTime, 1);
                                
                                auto seq = Sequence::create(moveto,scaleYuan,CallFuncN::create( CC_CALLBACK_1(GameScene::TouchEndCallFun, this, isMoveFlag)),nullptr);
                                moveFKItem->runAction(seq);
                                intcells9[resultX][resultY][resultZ]=cellStatus1;
                                
                                arrayFK->removeObject(moveFKItem);//移除后就不可以再移动
                                arrayRemoveFK->addObject(moveFKItem);//添加到可以清除的合集里
                            }
                            
                            break;
                            
                            
                    }
                    
                    //
                }
                
            }
            //////////
            if (isMoveFlag)
            {//将方块移回原点
                M3AudioManager::shareInstance()->playSound(5);
                Vect impulse;
                switch (moveFKItem->getPostioncount()) {
                    case postionCount1:
                        impulse = Vect(VisibleRect::right().x/4, VisibleRect::top().y*3/16);
                        break;
                    case postionCount2:
                        impulse = Vect(VisibleRect::right().x/2, VisibleRect::top().y*3/16);
                        break;
                    case postionCount3:
                        impulse = Vect(VisibleRect::right().x*3/4, VisibleRect::top().y*3/16);
                        break;
                        
                    default:
                        break;
                }
                
                auto moveto=MoveTo::create(0.2, impulse);
                moveFKItem->runAction(moveto);
                moveFKItem->setScale(0.6);
            }
            else
            {//已经合并了，检查是否需要消除，是否需要生成新的方块
                
                
                //xiaochuFun();
                /** 20151119去掉改成用完一个生成一个
                if (arrayFK->count()==0)
                {
                    //生成3个新方块
                    create3FKitem(itemWidth);
                }
                */
                
                createandMoveFKitem(itemWidth,moveFKItem->getPostioncount());
                
            }
            
            /////////打印当前数组
            /*
             for (int x=0; x<GridSize10; x++)
             {
             for (int y=0; y<GridSize10; y++)
             {
             CCLOG("intcells10[%d][%d]======%d",x,y,intcells10[x][y]);
             }
             }
             */
            ////////////
            moveFKItem=NULL;
            
            
        }
        
    }


}


//////tempbegin
void GameScene::saveGrid(int vvv)
{//持久化棋盘的值
    /*
    //CCLOG("持久化棋盘的值 GameScene::saveGrid(%d)",vvv);
    std::string strGridValue="";
    for (int x = 0; x < GridSize10; x++) {
        
        for (int y = 0; y < GridSize10; y++) {
            //strGridValue=strGridValue+(String::createWithFormat("%d%s",intcells10[x][y],","))->getCString();//字符串连接
            
            strGridValue=strGridValue+(StringUtils::format("%d%s",intcells10[x][y],","));
        }
    }
    
    UserDefault::getInstance()->setStringForKey(saveqipan, strGridValue);//存储10棋盘的状态
    UserDefault::getInstance()->setIntegerForKey(save_score, score);//存储10棋盘的当前得分
    
    */
}

char * GameScene::gatGrid()
{//获取持久化棋盘的值
    /*
    std::string jingdianGrid=UserDefault::getInstance()->getStringForKey(saveqipan10);
    
    char *data;
    int len = jingdianGrid.length();
    data = (char *)malloc((len+1)*sizeof(char));
    jingdianGrid.copy(data,len,0);
    
    return data;//string字符串转成char *
    */
    
    char *data;
    return data;
}
/////tempend

void GameScene::selectSpriteForTouch(Point touchLocation)
{//onTouchBegan的具体处理方法
    
    Ref* obj = nullptr;
    CCARRAY_FOREACH(arrayFK,obj)
    {
        auto tempItem = static_cast<FKItem*>(obj);//将obj强制转换成FKItem
        
        if (Rect(tempItem->getPosition().x-itemWidth*3/2, tempItem->getPosition().y-itemWidth*3/2, itemWidth*3, itemWidth*3).containsPoint(touchLocation))
        {
            moveFKItem=tempItem;
            moveFKItem->setScale(0.9);
            /*
             Vect impulse = Vect(0, itemWidth*3);
             auto moveby=MoveBy::create(0.01, impulse);
             moveFKItem->runAction(moveby);
             */
            //moveFKItem->setPosition(moveFKItem->getPosition().x,moveFKItem->getPosition().y+itemWidth*3);
            touchLocation.add(Vec2(0,itemWidth*3));//按下方块后向上移动3个格子
            moveFKItem->setPosition(touchLocation);
        }
        
        
    }
    
}

void GameScene::ranSe()
{//将已经移动到棋盘上的方块下面的棋盘染色，并remove掉方块
    Ref* obj = nullptr;
    CCARRAY_FOREACH(arrayRemoveFK,obj)
    {
        // CCLOG("13333311111111");
        auto tempItem = static_cast<FKItem*>(obj);//将obj强制转换成FKItem
        
        //CCLOG("tempItem->chessX===%d tempItem->chessY===%d",tempItem->chessX,tempItem->chessY);

        
        switch (tempItem->type)
        {//针对不同的方块给对应的棋盘染色
            case 1:
                //口
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                
                break;
                
            case 21:
                //CCLOG("type===21");
                //口
                // 口
                //  口
                //   口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-2][tempItem->chessY][tempItem->chessZ+2])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

        
                
                break;
                
            case 22:
                //   口
                //  口
                // 口
                //口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+2][tempItem->chessZ+2])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                


                break;
                
            case 23:
                //口口口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-2][tempItem->chessY-2][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                

                
                
                
                break;
                
            case 31:
                //口口
                // 口
                //   口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 32:
                // 口
                //口口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 33:
                //    口
                //口 口
                // 口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                


                
                break;
                
            case 34:
                // 口
                //  口
                //口 口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                


                
                break;
                
            case 35:
                //口 口 口
                //    口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                


                
                break;
                
            case 36:
                //   口
                // 口  口
                //口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                


                
                break;
                
                
            case 41:
                //口 口
                // 口
                //口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 42:
                // 口
                //口 口
                //    口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 43:
                //口口口
                // 口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                


                
                break;
                
            case 44:
                //  口
                // 口
                //口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 45:
                //口
                // 口 口
                //  口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                


                
                break;
                
            case 46:
                //    口
                // 口口 口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                


                
                break;
                
                
            case 51:
                // 口口
                //口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 52:
                //口口
                //  口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 53:
                // 口
                //口口
                // 口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

                
                break;
                
                
            case 61:
                // 口
                //   口
                //口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

                
                break;
            case 62:
                //口   口
                //  口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                

                
                break;
                
            case 63:
                // 口
                //口
                // 口口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);

                
                break;
            case 64:
                // 口口
                //口
                // 口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY-1][tempItem->chessZ-1])->setColor(tempItem->trueColor);

                
                break;
            case 65:
                // 口口
                //口   口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY-1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);

                
                break;
                
            case 66:
                //口口
                //   口
                //  口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX-1][tempItem->chessY][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY+1][tempItem->chessZ+1])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY+1][tempItem->chessZ])->setColor(tempItem->trueColor);
                ((Sprite*)arrayQiPanbg[tempItem->chessX+1][tempItem->chessY][tempItem->chessZ-1])->setColor(tempItem->trueColor);

                
                break;
                
            default:
                //口
                
                ((Sprite*)arrayQiPanbg[tempItem->chessX][tempItem->chessY][tempItem->chessZ])->setColor(tempItem->trueColor);
                
                break;
                
                
        }
        
        removeChild(tempItem);
    }
    arrayRemoveFK->removeAllObjects();
}

void GameScene::xiaochuFun()
{//棋盘上消除的方法
    CCLOG("xiaochuFun======");
    int xiaochuCount=0;//一次消除了多少行
    bool xcFlagX[Grid5Size9];//该列是否可以消除，true为可以消除
    bool xcFlagY[Grid5Size9];
    bool xcFlagZ[Grid5Size9];
    for (int i=0; i<Grid5Size9; i++)
    {
        xcFlagX[i]=false;
    }
    for (int i=0; i<Grid5Size9; i++)
    {
        xcFlagY[i]=false;
    }
    for (int i=0; i<Grid5Size9; i++)
    {
        xcFlagZ[i]=false;
    }
    
    
    
    //填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z

    
    /////////////循环判断z列是否需要消除begin
    int zcount=0;
    for (int z=0; z<Grid5Size9; z++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        bool tempxflag=true;//先假设这一列需要清除，再检查是否有空格子，如果有空格子，则不需要清除
        
        for (int x=0; x<Grid5Size9; x++)
        {
            int y=z-4+x;
            if (y>=0&&y<Grid5Size9)
            {
                //CCLOG("zcount===%d intcells9[%d][%d][%d]",zcount,x,y,z);
                zcount++;
                if (intcells9[x][y][z]==cellStatus0)
                {//如果有空格则不能消除
                    //CCLOG("intcells9[%d][%d][%d]",x,y,z);
                    tempxflag=false;
                    break;
                }
                
            }
            

            
        }
        ///////
        if (tempxflag)
        {
            xiaochuCount++;
            CCLOG("ZZZZ===xiaochuCount==%d",xiaochuCount);
            xcFlagZ[z]=true;
        }
    }
    //////////////循环判断z列是否需要消除end
    
    /////////////循环判断x列是否需要消除begin
    //int xcount=0;
    for (int x=0; x<Grid5Size9; x++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        bool tempxflag=true;//先假设这一列需要清除，再检查是否有空格子，如果有空格子，则不需要清除
        
        for (int z=0; z<Grid5Size9; z++)
        {
            int y=z-4+x;
            if (y>=0&&y<Grid5Size9)
            {
                //CCLOG("xcount===%d intcells9[%d][%d][%d]",xcount,x,y,z);
                //xcount++;
                if (intcells9[x][y][z]==cellStatus0)
                {//如果有空格则不能消除
                    //CCLOG("xcount===%d intcells9[%d][%d][%d]",xcount,x,y,z);
                    //xcount++;
                    tempxflag=false;
                    break;
                }
                
            }
            

            
        }
        //////
        if (tempxflag)
        {
            xiaochuCount++;
            CCLOG("XXXX====xiaochuCount====%d",xiaochuCount);
            xcFlagX[x]=true;
        }
        
        
    }
    
    //////////////循环判断x列是否需要消除end
    
    /////////////循环判断y列是否需要消除begin
    int ycount=0;
    for (int y=0; y<Grid5Size9; y++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        bool tempxflag=true;//先假设这一列需要清除，再检查是否有空格子，如果有空格子，则不需要清除
        
        for (int x=0; x<Grid5Size9; x++)
        {
            //int y=z-4+x;
            int z=y-x+4;
            if (z>=0&&z<Grid5Size9)
            {
                //CCLOG("ycount===%d intcells9[%d][%d][%d]",ycount,x,y,z);
                //ycount++;
                if (intcells9[x][y][z]==cellStatus0)
                {//如果有空格则不能消除
                    //CCLOG("ycount===%d intcells9[%d][%d][%d]",ycount,x,y,z);
                    //ycount++;
                    tempxflag=false;
                    break;
                }
                
            }
            

            
        }
        //////
        if (tempxflag)
        {
            xiaochuCount++;
            CCLOG("YYYY====xiaochuCount====%d",xiaochuCount);
            xcFlagY[y]=true;
        }
        
    }
    //////////////循环判断y列是否需要消除end
    if (xiaochuCount>0)
    {
        M3AudioManager::shareInstance()->playSound(1);
    }
    
    ///////////////////显示消除动画begin
    
    /////////显示Z列消除动画begin
    for (int z=0; z<Grid5Size9; z++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        if (xcFlagZ[z])
        {//如果该列可以消除
            addScore=addScore+10;
            
            for (int x=0; x<Grid5Size9; x++)
            {
                int y=z-4+x;
                if (y>=0&&y<Grid5Size9)
                {
                    intcells9[x][y][z]=cellStatus0;
                    XiaoChuAnimation(((Sprite*)arrayQiPanbg[x][y][z]));
                    
                }
  
            }
            
            
        }
        
    }
    /////////显示Z列消除动画end
    
    
    /////////显示X列消除动画begin
    
    for (int x=0; x<Grid5Size9; x++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        if (xcFlagX[x])
        {//如果该列可以消除
            
            addScore=addScore+10;
            
            for (int z=0; z<Grid5Size9; z++)
            {
                int y=z-4+x;
                if (y>=0&&y<Grid5Size9)
                {
                    intcells9[x][y][z]=cellStatus0;
                    XiaoChuAnimation(((Sprite*)arrayQiPanbg[x][y][z]));
                }
 
            }
  
        }
        
    }
    
    /////////显示X列消除动画end
    
    /////////显示Y列消除动画begin
    
    for (int y=0; y<Grid5Size9; y++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        if (xcFlagY[y])
        {//如果该列可以消除
            
            addScore=addScore+10;
            
            for (int x=0; x<Grid5Size9; x++)
            {
                //int y=z-4+x;
                int z=y-x+4;
                if (z>=0&&z<Grid5Size9)
                {
                    
                    intcells9[x][y][z]=cellStatus0;
                    XiaoChuAnimation(((Sprite*)arrayQiPanbg[x][y][z]));
                }
 
            }
            
            
            
        }
        
        
    }
    
    /////////显示Y列消除动画end
    
    ///////////////////显示消除动画end
    
    //计算积分
    score=score+addScore;
    lscore->updateValue(addScore, score);
    
    
    if (score>topScore)
    {
        //M3AudioManager::shareInstance()->playSound(6);
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        IOSTools::GameCenterSendScore10(score);
#endif
        ltopScore->updateValue(addScore, score);
        UserDefault::getInstance()->setIntegerForKey("topScore", score);
        topScore=UserDefault::getInstance()->getIntegerForKey("topScore",0);
    }
    
    addScore=0;
    
    
    
    ///////
    
}

void GameScene::XiaoChuAnimation(Node* sender)
{//消除动画
    auto tempTime=0.06;
    auto fadeOut1=FadeOut::create(tempTime);
    auto fadeIn1=FadeIn::create(tempTime);
    
    auto fadeOut2=FadeOut::create(tempTime);
    auto fadeIn2=FadeIn::create(tempTime);
    
    auto tint=TintTo::create(0.01, 90, 90, 90);
    
    if (isNightMode)
    {
        tint=TintTo::create(0.01, 90, 90, 90);
    }
    else
    {
        tint=TintTo::create(0.01, 210, 210, 210);
    }
    
    auto seq=Sequence::create(fadeOut1,fadeIn1,fadeOut2,fadeIn2,tint,NULL);
    
    ((Sprite*)sender)->runAction(seq);
    
}

void GameScene::TouchEndCallFun(Node* sender, bool isMoveFlag)
{//方块合并到棋盘的动画显示完成后调用的方法，棋盘染色，remove方块对象,判断消除,判断游戏是否结束
    //CCLOG("isMoveFlag=======%d",isMoveFlag);
    
    M3AudioManager::shareInstance()->playSound(0);
    ranSe();
    
    xiaochuFun();
    
    if (checkisGameOver())
    {
        CCLOG("=====游戏结束======");
        M3AudioManager::shareInstance()->playSound(3);
        isPause=true;
        isgameOver=true;
        
        layerColorGameOver->setVisible(true);
        gameOverlscore->updateValue(score, score);
    }
    else
    {
        //CCLOG("游戏继续");
    }
    
    
}

bool GameScene::checkisGameOver()
{//检查游戏是否结束
    bool result=true;
    Ref* obj = nullptr;
    
    //CCLOG("arrayFK->count()===%zd",arrayFK->count());
    CCARRAY_FOREACH(arrayFK,obj)
    {
        //CCLOG("test1111");
        auto tempItem = static_cast<FKItem*>(obj);//将obj强制转换成FKItem
        if (checkisFKHeBing(tempItem->type))
        {
            result=false;
            return result;
        }
    }
    return result;
}

bool GameScene::checkisFKHeBing(int type)
{//检查方块是否能合并到棋盘上，true是能合并
    bool result=false;
    
    CCLOG("checkisFKHeBing type====%d",type);
    /////////
    for (int z=0; z<Grid5Size9; z++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        for (int x=0; x<Grid5Size9; x++)
        {
            //
            int y=z-4+x;
            if (y>=0&&y<Grid5Size9)
            {

                if (intcells9[x][y][z]==cellStatus0)
                {//如果有一个空格
                    if (checkisFKHeBingByOne(x,y,z,type))
                    {//如果能合并
                        result=true;
                        return result;
                    }
                }
                

            }
            
        }
    }
    
    
    return result;
}

bool GameScene::checkisFKHeBingByOne(int resultX,int resultY,int resultZ,int type)
{//检查方块是否能合并到棋盘上的具体一个空格上，true是能合并
    bool result=false;

    switch (type)
    {//针对不同的方块给对应的棋盘染色
        case 1:
            //口
            result=true;
            
            break;
            
        case 21:
            //CCLOG("type===21");
            //口
            // 口
            //  口
            //   口
            CCLOG("aaaba resultX====%d resultY===%d resultZ===%d",resultX,resultY,resultZ);
            if (resultX-2>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+2<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-2][resultY][resultZ+2]==cellStatus0&&
                    intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    CCLOG("bbbbbbcaa resultX====%d resultY===%d resultZ===%d",resultX,resultY,resultZ);
                    CCLOG("a11111[%d][%d][%d]=====%d",resultX-2,resultY,resultZ+2,intcells9[resultX-2][resultY][resultZ+2]);
                    CCLOG("a22222[%d][%d][%d]=====%d",resultX-1,resultY,resultZ+1,intcells9[resultX-1][resultY][resultZ+1]);
                    CCLOG("a33333[%d][%d][%d]=====%d",resultX,resultY,resultZ,intcells9[resultX][resultY][resultZ]);
                    CCLOG("a44444[%d][%d][%d]=====%d",resultX+1,resultY,resultZ-1,intcells9[resultX+1][resultY][resultZ-1]);
                    result=true;
                }
            }

            break;
            
        case 22:
            //   口
            //  口
            // 口
            //口
            if (resultX>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+2<Grid5Size9&&resultZ-1>=0&&resultZ+2<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX][resultY+2][resultZ+2]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            break;
            
        case 23:
            //口口口口
            
            if (resultX-2>=0&&resultX+1<Grid5Size9&&resultY-2>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-2][resultY-2][resultZ]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            break;
            
        case 31:
            //口口
            // 口
            //   口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            
            
            
            break;
            
        case 32:
            // 口
            //口口口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0
                    )
                {
                    result=true;
                }
            }

            
            
            
            break;
            
        case 33:
            //    口
            //口 口
            // 口
            
            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            
            
            
            
            break;
            
        case 34:
            // 口
            //  口
            //口 口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            
            
            
            break;
            
        case 35:
            //口 口 口
            //    口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            
            
            
            
            break;
            
        case 36:
            //   口
            // 口  口
            //口
            
            if (resultX>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            
            
            break;
            
            
        case 41:
            //口 口
            // 口
            //口
            
            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            
            break;
            
        case 42:
            // 口
            //口 口
            //    口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            
            
            
            break;
            
        case 43:
            //口口口
            // 口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            
            
            break;
            
        case 44:
            //  口
            // 口
            //口口
            
            if (resultX>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            
            break;
            
        case 45:
            //口
            // 口 口
            //  口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
     
            
            
            
            break;
            
        case 46:
            //    口
            // 口口 口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            
            
            break;
            
            
        case 51:
            // 口口
            //口口
            
            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            

            
            
            break;
            
        case 52:
            //口口
            //  口口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            
            break;
            
        case 53:
            // 口
            //口口
            // 口
            
            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            

            
            
            
            break;
            
            
        case 61:
            // 口
            //   口
            //口口
            
            if (resultX>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            
  
            
            
            
            break;
        case 62:
            //口   口
            //  口口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            

            
            
            
            break;
            
        case 63:
            // 口
            //口
            // 口口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            break;
        case 64:
            // 口口
            //口
            // 口
            
            if (resultX-1>=0&&resultX<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX][resultY-1][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            

            
            
            break;
        case 65:
            // 口口
            //口   口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY-1>=0&&resultY+1<Grid5Size9&&resultZ>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX-1][resultY-1][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
            
            

            
            
            break;
            
        case 66:
            //口口
            //   口
            //  口
            
            if (resultX-1>=0&&resultX+1<Grid5Size9&&resultY>=0&&resultY+1<Grid5Size9&&resultZ-1>=0&&resultZ+1<Grid5Size9)
            {//不能合并到棋盘外
                if (intcells9[resultX-1][resultY][resultZ+1]==cellStatus0&&
                    intcells9[resultX][resultY+1][resultZ+1]==cellStatus0&&
                    intcells9[resultX+1][resultY+1][resultZ]==cellStatus0&&
                    intcells9[resultX+1][resultY][resultZ-1]==cellStatus0
                    )
                {
                    result=true;
                }
            }
            
  
            
            
            break;
            
        default:
            //口
            
            result=true;
            
            break;
            
            
    }
    
    return result;
    
}

void GameScene::menuCallback1ReStart(Ref* sender)
{
    //CCLOG("menuCallback1");
    M3AudioManager::shareInstance()->playSound(2);
    /*
    for (int x=0; x<GridSize10; x++)
    {//初始化棋盘
        for (int y=0; y<GridSize10; y++)
        {
            intcells10[x][y]=0;
            ((Item*)arraybg2Item[x][y])->bg->setColor(Color3B(230, 230, 230));
        }
    }
    */
    for (int z=0; z<Grid5Size9; z++)
    {//填充空格，空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
        for (int x=0; x<Grid5Size9; x++)
        {
            //
            int y=z-4+x;
            if (y>=0&&y<Grid5Size9)
            {

                
                intcells9[x][y][z]=cellStatus0;


                ((Sprite*)arrayQiPanbg[x][y][z])->setColor(itemBG);
            }
            
        }
    }
    
    score=0;
    lscore->updateValue(0, score);
    
    Ref* obj = nullptr;
    
    CCARRAY_FOREACH(arrayFK,obj)
    {
        auto tempItem = static_cast<FKItem*>(obj);//将obj强制转换成FKItem
        removeChild(tempItem);
    }
    
    CCARRAY_FOREACH(arrayRemoveFK,obj)
    {
        auto tempItem = static_cast<FKItem*>(obj);//将obj强制转换成FKItem
        removeChild(tempItem);
    }
    
    arrayFK->removeAllObjects();
    arrayRemoveFK->removeAllObjects();
    create3FKitem(itemWidth);
    
    layerColorGameOver->setVisible(false);
    isPause=false;
    isgameOver=false;
    layerColorGamePause->setVisible(false);
    
    //////
    gamePauseButtonHome->setPosition(-gamePauseButtonHome->getContentSize().width,VisibleRect::top().y*3/8-gamePauseButtonHome->getContentSize().height);
    gamePauseButtonReStart->setPosition(VisibleRect::right().x/2+gamePauseButtonReStart->getContentSize().width,-gamePauseButtonReStart->getContentSize().height);
    gamePauseButtonGoOn->setPosition(VisibleRect::right().x+gamePauseButtonGoOn->getContentSize().width,VisibleRect::top().y*3/8+gamePauseButtonGoOn->getContentSize().height);
    
}

void GameScene::menuCallback2ToMain(Ref* sender)
{//返回主菜单
    CCLOG("menuCallback2ToMain111");
    M3AudioManager::shareInstance()->playSound(2);
    auto sc = SceneControl::create();
    sc->toMain();
}
void GameScene::menuCallback3GoOn(Ref* sender)
{//继续游戏
    CCLOG("goon");
    M3AudioManager::shareInstance()->playSound(2);
    isPause=false;
    layerColorGamePause->setVisible(false);
    
    //////
    gamePauseButtonHome->setPosition(-gamePauseButtonHome->getContentSize().width,VisibleRect::top().y*3/8-gamePauseButtonHome->getContentSize().height);
    gamePauseButtonReStart->setPosition(VisibleRect::right().x/2+gamePauseButtonReStart->getContentSize().width,-gamePauseButtonReStart->getContentSize().height);
    gamePauseButtonGoOn->setPosition(VisibleRect::right().x+gamePauseButtonGoOn->getContentSize().width,VisibleRect::top().y*3/8+gamePauseButtonGoOn->getContentSize().height);
    
}

void GameScene::menuCallback4Pause(Ref* sender)
{//暂停游戏
    CCLOG("pause");
    M3AudioManager::shareInstance()->playSound(2);
    if (!isgameOver)
    {
        isPause=true;
        layerColorGamePause->setVisible(true);
        
        auto moveto1=MoveTo::create(0.3, Vec2(VisibleRect::right().x*1/4,VisibleRect::top().y*3/8));
        gamePauseButtonHome->runAction(moveto1);
        
        auto moveto2=MoveTo::create(0.3, Vec2(VisibleRect::right().x/2,VisibleRect::top().y*3/8));
        gamePauseButtonReStart->runAction(moveto2);
        
        auto moveto3=MoveTo::create(0.3, Vec2(VisibleRect::right().x*3/4,VisibleRect::top().y*3/8));
        gamePauseButtonGoOn->runAction(moveto3);
        
        ////////
    }
    
    
}

Vect GameScene::getTruePositionByXYZ(int x,int y,int z)
{//根据y,z获取在屏幕上的实际位置,不需要x的值
    float boardCenterX=VisibleRect::center().x;
    float boardCenterY=VisibleRect::center().y;
    //itemWidth     +((x-4)*itemWidth/2)
     Vect truePosition = Vect(boardCenterX-((z-4)*itemWidth*1.1/2)+(y-4)*itemWidth*1.1, boardCenterY+(z-4)*itemWidth);
    return truePosition;
}

GameScene::~GameScene()
{
    
    CC_SAFE_RELEASE(arrayFK);
    CC_SAFE_RELEASE(arrayRemoveFK);
    
}
