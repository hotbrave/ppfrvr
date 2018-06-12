//
//  FKItem.h
//  ppfrvr
//
//  Created by 赵勇 on 15/10/31.
//
//

#ifndef FKItem_h
#define FKItem_h

#include "cocos2d.h"
#include "Constants.h"

USING_NS_CC;

class FKItem : public Node{
    
public:
    /*
     
     //type是区分4*4 5*5用的,格子小的文字字体也要小
     void updatePosition(int xval,int yval);
     */
    int type;//方块整体类型 1是一点,21是横两点，22是竖两点,31是横三点，32是竖3点，33是左下三角，
    int widthType;//方块的宽度类型，分为1、2、3、4、5格宽度
    int chessX;//棋盘x
    int chessY;//棋盘y
    int chessZ;//棋盘z
    float screenX;//实际的x
    float screenY;//实际的y
    float beginX;//判断落点的起始X   从左下角开始 长度单位是一个格子，比如是中心点左边的格子就是(-1,0)
    float beginY;//判断落点的起始Y
    int gridx;//棋盘x(以方块整体左下角为准)
    int gridy;//棋盘y(以方块整体左下角为准)
    int itemColor;//
    //float itemWidth;//节点总宽度
    float itemHeight;//节点总高度
    float scaleWidth;//节点缩放系数
    bool init();
    Color3B trueColor;
    CREATE_FUNC(FKItem);
    void initItem(int xval,int yval,int zval,float truex,float truey,int type,float scaleWidthval,int color,int pCount);//xval,yval是棋盘中的坐标，truex, truey是在屏幕中的实际位置,pCount是下面3个方块的位置值，1为左边的方块，2为中间的方块，3为右边的方块
    void updateValue(int xval,int yval);
    
    
    
    Vect getRelativePositionByXYZ(int x,int y,int z);//根据x,y,z获取在屏幕上的相对位置,不需要x的值
    Color3B getColor(int vcolor);//根据颜色值获取实际颜色
    
    
    int defaultX;//方块起始点位置，默认设置成棋盘中心点4,4,4
    int defaultY;
    int defaultZ;
    
    void setShadow(bool shadowStatus);//设置阴影状态
    
    Sprite* shadow1;//方块的阴影图片
    Sprite* shadow2;
    Sprite* shadow3;
    Sprite* shadow4;
    
    int postionCount;//位置值，1为左边的方块，2为中间的方块，3为右边的方块
    void setPostionCount(int pCount);//设置位置值
    int getPostioncount();//获取位置值
    
    int posType;//方块位置类型，下面3个可以移动的方块，1是左边可以移动的方块，2是中间可以移动的方块，3是右边可以移动的方块
    void setPosType(int valPosType);//设置方块位置类型
    int getPosType();//获取方块位置类型
    
};

#endif /* FKItem_h */
