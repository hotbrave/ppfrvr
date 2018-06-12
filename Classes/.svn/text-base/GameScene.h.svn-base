//
//  GameScene.h
//  ppfrvr
//
//  Created by 赵勇 on 15/10/16.
//
//

#ifndef GameScene_h
#define GameScene_h

#include "cocos2d.h"
#include "Constants.h"
#include "VisibleRect.h"
#include "M3AudioManager.h"
#include "FKItem.h"
#include "LTitle.h"
#include "SceneControl.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
#include "IOSTools.h"
#endif

USING_NS_CC;

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual void onEnter();
    virtual bool init();
    CREATE_FUNC(GameScene);
    
    void onEnterTransitionDidFinish();
    ~GameScene();
    
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    
    void selectSpriteForTouch(Point touchLocation);//处理具体的点击事件
    //static bool isNightMode;//是否开启夜间模式
    
    void saveGrid(int vvv);//持久化棋盘的值
    char * gatGrid();//获取持久化棋盘的值
    
private:
   int intcells9[Grid5Size9][Grid5Size9][Grid5Size9];//初始化一个9*9*9数组,存放棋盘每个格子的状态,空格是0，填充的空格子是2，有方块的格子是1。左上是x，左下是y，下是z
    
    bool isPause;//游戏是否暂停,暂停时不能点击任何方块
    bool isgameOver;//游戏是否结束
    int score;//本局得分
    int addScore;//这次增加分数
    int topScore;//最高分
    
    
    void initmyGame();//初始化游戏
    float itemWidth;//节点宽度
    
    Vect getTruePositionByXYZ(int x,int y,int z);//根据x,y,z获取在屏幕上的实际位置,不需要x的值
    
    void create3FKitem(float itemWidth);//创造3个方块
    void huifuNFKitem(float itemWidth);//保存游戏时恢复方块的方法
    void createandMoveFKitem(float itemWidth,int pCountvv);//创造1个方块,并移动(拼完一个方块后调用),之前玩家移动的方块的位置值1，2，3
    FKItem* createFKitem(float itemWidth,int type,float x,float y,int pCountv);//创造1个方块
    
    __Array* arrayFK;//各种可以移动的方块的合集
    __Array* arrayRemoveFK;//可以被remove删除掉的方块合集
    
    void setPause(Node* sender,bool flag);//
    FKItem* moveFKItem;//正在移动的方块
    
    void TouchEndCallFun(Node* sender, bool cleanup);//方块合并到棋盘的动画显示完成后调用的方法，判断消除或者将方块移动回原位
    void ranSe();//将已经移动到棋盘上的方块下面的棋盘染色，并remove掉方块
    Sprite* arrayQiPanbg[Grid5Size9][Grid5Size9][Grid5Size9];//棋盘背景数组
    
    void xiaochuFun();//棋盘上消除的方法
    void XiaoChuAnimation(Node* sender);//消除动画
    
    //Color4B layerBG;//游戏背景颜色
    Color3B itemBG;//棋盘每个格子的背景颜色
    
    bool checkisGameOver();//检查游戏是否结束,true 游戏结束，
    bool checkisFKHeBing(int type);//检查方块是否能合并到棋盘上，true是能合并
    LayerColor* layerColorGameOver;//
    LTitle* gameOverlscore;
    
    void menuCallback1ReStart(Ref* sender);//重玩游戏按钮
    void menuCallback2ToMain(Ref* sender);//返回主菜单
    void menuCallback3GoOn(Ref* sender);//继续游戏
    void menuCallback4Pause(Ref* sender);//暂停游戏
    
    MenuItemImage* gamePauseButtonHome;
    MenuItemImage* gamePauseButtonReStart;
    MenuItemImage* gamePauseButtonGoOn;
    
    LTitle* lscore;
    LTitle* ltopScore;
    MenuItemImage* buttonPause;
    
    
    LayerColor* layerColorGamePause;//
    
    bool checkisFKHeBingByOne(int resultX,int resultY,int resultZ,int type);//检查方块是否能合并到棋盘上的具体一个空格上，true是能合并
    
     bool isNightMode;//是否开启夜间模式
};
#endif /* GameScene_h */
