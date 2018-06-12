//
//  LTitle.h
//  pp1010
//
//  Created by 赵勇 on 14-11-18.
//
//

#ifndef __pp1010__LTitle__
#define __pp1010__LTitle__

#include "cocos2d.h"

USING_NS_CC;

class LTitle : public Node{
    
public:

    Sprite* bg;
    LabelTTF* lb;
    int scoreVal;//显示积分
    float screenX;
    float screenY;
    int itemColor;//
    float itemWidth;//节点总宽度
    float itemHeight;//高度
    bool init();
    CREATE_FUNC(LTitle);
    void initItem(float width,float height,Color3B bgColor,Color3B wordColor,int val);
    void updateValue(int addval,int val);
    Color3B lbgColor;
    Color3B lwordColor;
    LabelTTF* addScoreLabel;
    
    
};

#endif /* defined(__pp1010__LTitle__) */
