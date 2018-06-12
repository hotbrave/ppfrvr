//
//  LTitle.cpp
//  pp1010
//
//  Created by 赵勇 on 14-11-18.
//
//

#include "LTitle.h"
#include "VisibleRect.h"

bool LTitle::init(){
    return true;
}


void LTitle::initItem(float width,float height,Color3B bgColor,Color3B wordColor,int val)
{
    lbgColor=bgColor;
    lwordColor=wordColor;
    
    bg = Sprite::create("imageItem.png");
    bg->setScaleX(width/bg->getContentSize().width);
    bg->setScaleY(height/bg->getContentSize().height);
    bg->setPosition(0,0);
    bg->setColor(bgColor);
    addChild(bg,1);

    int numSize=50;
    if (val>9999)
    {
        numSize=40;
    }
    else
    {
        numSize=50;
    }
    lb = LabelTTF::create(((String::createWithFormat("%d",val))->getCString()), "Verdana-Bold", numSize);
    lb->setColor(wordColor);
    lb->setPosition(0,0);
    addChild(lb, 2);
    
    addScoreLabel= LabelTTF::create(((String::createWithFormat("%d",0))->getCString()), "Verdana-Bold", 50);
    addScoreLabel->setVisible(false);
    addScoreLabel->setPosition( 0,0);
    addScoreLabel->setColor(lwordColor);
    addChild(addScoreLabel, 3);
}

void LTitle::updateValue(int addval,int val)
{
    if (addval!=0)
    {
        float moveTime=0.5;
        addScoreLabel->setVisible(false);
        addScoreLabel->setPosition( 0,0);
        addScoreLabel->setOpacity(255);//opacity 回复fadeOut修改的透明度
        
        addScoreLabel->setString((CCString::createWithFormat("+%d",addval))->getCString());
        
        auto label_seq=Sequence::create(MoveBy::create(moveTime,Vec2(0, VisibleRect::right().x/15)),CCHide::create(),NULL);
        addScoreLabel->setVisible(true);
        addScoreLabel->runAction(label_seq);
        auto out=FadeOut::create(moveTime);
        addScoreLabel->runAction(out);
    }

    int numSize=50;
    if (val>9999)
    {
        numSize=40;
    }
    else
    {
        numSize=50;
    }
    lb->setString((String::createWithFormat("%d",val))->getCString());
    lb->setFontSize(numSize);
}




