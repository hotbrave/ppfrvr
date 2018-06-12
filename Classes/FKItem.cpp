//
//  FKItem.cpp
//  ppfrvr
//
//  Created by 赵勇 on 15/10/31.
//
//

#include "FKItem.h"
#include "VisibleRect.h"
bool FKItem::init(){
    return true;
}

void FKItem::initItem(int xval,int yval,int zval,float truex,float truey,int typeval,float scaleWidthval,int color,int pCount)
{//方块整体类型 1是一点,21是横两点，22是竖两点,31是横三点，32是竖3点，33是左下三角，
    type=typeval;
    chessX=xval;
    chessY=yval;
    chessZ=zval;
    
    screenX=truex;//实际的x
    screenY=truey;//实际的y
    
    scaleWidth=scaleWidthval;
    //CCLOG("scaleWidth=====%f",scaleWidth);
    itemColor=color;
    
    defaultX=4;
    defaultY=4;
    defaultZ=4;
    
    postionCount=pCount;
    
    auto bg1 = Sprite::create("tile.png");
    auto bg2 = Sprite::create("tile.png");
    auto bg3 = Sprite::create("tile.png");
    auto bg4 = Sprite::create("tile.png");
    
    bg1->setScale(scaleWidthval/bg1->getContentSize().width);
    bg2->setScale(scaleWidthval/bg1->getContentSize().width);
    bg3->setScale(scaleWidthval/bg1->getContentSize().width);
    bg4->setScale(scaleWidthval/bg1->getContentSize().width);
    
    shadow1 = Sprite::create("shadow.png");
    shadow2 = Sprite::create("shadow.png");
    shadow3 = Sprite::create("shadow.png");
    shadow4 = Sprite::create("shadow.png");
    
    float shadowScale=1.35;//阴影放大倍数
    shadow1->setScale(scaleWidthval*shadowScale/shadow1->getContentSize().width);
    shadow2->setScale(scaleWidthval*shadowScale/shadow2->getContentSize().width);
    shadow3->setScale(scaleWidthval*shadowScale/shadow3->getContentSize().width);
    shadow4->setScale(scaleWidthval*shadowScale/shadow4->getContentSize().width);
    
    trueColor=Color3B(205, 179, 128);
    
    trueColor=Color3B(205, 179, 128);
    switch (type)
    {
        case 1:
            //口
            beginX=0;
            beginY=0;
            
            trueColor=getColor(color1);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            addChild(bg1,2);
            addChild(shadow1,1);
            break;
            
        case 21:
            CCLOG("type===21");
            //口
            // 口
            //  口
            //   口
           // beginX=-1.5;
            //beginY=0;
            trueColor=getColor(color2);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-2,defaultY,defaultZ+2));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            /*
             shadow1->
             shadow2->
             shadow3->
             shadow4->
             */
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-2,defaultY,defaultZ+2));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 22:
            //   口
            //  口
            // 口
            //口
            trueColor=getColor(color2);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+2,defaultZ+2));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+2,defaultZ+2));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            break;
            
        case 23:
            //口口口口
            
            trueColor=getColor(color2);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-2,defaultY-2,defaultZ));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-2,defaultY-2,defaultZ));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 31:
            //口口
            // 口
            //   口
            
            trueColor=getColor(color3);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 32:
            // 口
            //口口口
            
            trueColor=getColor(color3);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 33:
            //    口
            //口 口
            // 口
            
            trueColor=getColor(color3);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 34:
            // 口
            //  口
            //口 口
            
            trueColor=getColor(color3);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
           
        case 35:
            //口 口 口
            //    口
            
            trueColor=getColor(color3);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 36:
            //   口
            // 口  口
            //口
            
            trueColor=getColor(color3);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
            
        case 41:
            //口 口
            // 口
            //口
            
            trueColor=getColor(color4);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 42:
            // 口
            //口 口
            //    口
            
            trueColor=getColor(color4);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 43:
            //口口口
            // 口
            
            trueColor=getColor(color4);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 44:
            //  口
            // 口
            //口口
            
            trueColor=getColor(color4);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;

        case 45:
            //口
            // 口 口
            //  口
            
            trueColor=getColor(color4);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 46:
            //    口
            // 口口 口
            
            trueColor=getColor(color4);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;

            
        case 51:
            // 口口
            //口口
            
            trueColor=getColor(color7);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 52:
            //口口
            //  口口
            
            trueColor=getColor(color7);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 53:
            // 口
            //口口
            // 口
            
            trueColor=getColor(color7);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;

            
        case 61:
            // 口
            //   口
            //口口
            
            trueColor=getColor(color6);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
        case 62:
            //口   口
            //  口口
            
            trueColor=getColor(color6);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg2->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 63:
            // 口
            //口
            // 口口
            
            trueColor=getColor(color6);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
        case 64:
            // 口口
            //口
            // 口
            
            trueColor=getColor(color6);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX,defaultY-1,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
        case 65:
            // 口口
            //口   口
            
            trueColor=getColor(color6);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY-1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
            
        case 66:
            //口口
            //   口
            //  口
            
            trueColor=getColor(color6);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            bg2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            bg3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            bg4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            shadow1->setPosition(getRelativePositionByXYZ(defaultX-1,defaultY,defaultZ+1));
            shadow2->setPosition(getRelativePositionByXYZ(defaultX,defaultY+1,defaultZ+1));
            shadow3->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY+1,defaultZ));
            shadow4->setPosition(getRelativePositionByXYZ(defaultX+1,defaultY,defaultZ-1));
            
            addChild(bg1,2);
            addChild(bg2,2);
            addChild(bg3,2);
            addChild(bg4,2);
            
            addChild(shadow1,1);
            addChild(shadow2,1);
            addChild(shadow3,1);
            addChild(shadow4,1);
            
            break;
    
        default:
            //口
            beginX=0;
            beginY=0;
            
            trueColor=getColor(color1);
            
            bg1->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            shadow1->setPosition(getRelativePositionByXYZ(defaultX,defaultY,defaultZ));
            addChild(bg1,2);
            addChild(shadow1,1);
            break;
            
            
    }
    
    bg1->setColor(trueColor);
    bg2->setColor(trueColor);
    bg3->setColor(trueColor);
    bg4->setColor(trueColor);
    
    
    
    
    
    
}



Vect FKItem::getRelativePositionByXYZ(int x,int y,int z)
{//根据x,y,z获取在屏幕上的相对位置,不需要x的值
    /*
    float boardCenterX=VisibleRect::center().x;
    float boardCenterY=VisibleRect::center().y;
    //itemWidth     +((x-4)*itemWidth/2)
    Vect truePosition = Vect(boardCenterX-((z-4)*itemWidth/2)+(y-4)*itemWidth, boardCenterY+(z-4)*itemWidth);
    return truePosition;
    */
    
    //float boardCenterX=VisibleRect::center().x;
    //float boardCenterY=VisibleRect::center().y;
    
    /////////
    //(1,4,7)
    //(2,4,6)
    //(3,4,5)
    //(4,4,4)

    Vect truePosition = Vect(-((z-4)*scaleWidth*1.1/2)+(y-4)*scaleWidth*1.1, (z-4)*scaleWidth);
    return truePosition;
    
    
    
}

Color3B FKItem::getColor(int vcolor)
{//根据颜色值获取实际颜色
    auto tempColor=Color3B(151, 206, 45);//浅绿色
    switch (vcolor)
    {
        case color0:
            tempColor=Color3B(151, 206, 45);//浅绿色
            break;
        case color1:
            tempColor=Color3B(125, 110, 229);//紫色
            break;
        case color2:
            tempColor=Color3B(0, 193, 95);//绿色
            break;
        case color3:
            tempColor=Color3B(255, 198, 46);//黄色
            break;
        case color4:
            tempColor=Color3B(253, 102, 52);//橙色
            break;
        case color5:
            tempColor=Color3B(95, 96, 116);//深灰色
            break;
        case color6:
            tempColor=Color3B(59, 203, 253);//浅蓝色
            break;
        case color7:
            tempColor=Color3B(255, 153, 153);//淡粉色
            break;
        case color8:
            tempColor=Color3B(151, 206, 45);//浅绿色
            break;
        case color9:
            tempColor=Color3B(151, 206, 45);//浅绿色
            break;
            
        default:
            tempColor=Color3B(151, 206, 45);//浅绿色
            break;
    }
    return tempColor;
}

void FKItem::setShadow(bool shadowStatus)
{//设置阴影状态
    if (shadowStatus) {
        shadow1->setVisible(shadowStatus);
        shadow2->setVisible(shadowStatus);
        shadow3->setVisible(shadowStatus);
        shadow4->setVisible(shadowStatus);
    }

}

void FKItem::setPostionCount(int pCount)
{//设置位置值
    postionCount=pCount;
}

int FKItem::getPostioncount()
{//获取位置值
    return postionCount;
}

void FKItem::setPosType(int valPosType)
{//设置方块位置类型
    posType=valPosType;
}
int FKItem::getPosType()
{//获取方块位置类型
    return posType;
}




