#pragma once


//#include "Constants.h"

typedef enum {
	kGameObjectNone,
	kGameObjectPlayer,
	kGameObjectPlatform
} GameObjectType;

const int Grid5Size5=5;//5边六角形棋盘每个边的格子数
const int Grid5Size9=9;//5边六角形棋盘最长的一条直线的格子数(数组最大值)


const int layerNum0=0;//界面的层次结构 addchild用
const int layerNum1=1;//棋盘层
const int layerNum2=2;//方块层
const int layerNum3=3;//可以移动的方块层
const int layerNum4=4;//分数层
const int layerNum5=5;


//下面这些暂时不知道有没有用
const int color0=0;//灰色
const int color1=1;//
const int color2=2;//
const int color3=3;//
const int color4=4;//
const int color5=5;//
const int color6=6;//
const int color7=7;//
const int color8=8;//
const int color9=9;//

//格子状态  ,空格是0，填充的空格子是2，有方块的格子是1
const int cellStatus0=0;//空格是0
const int cellStatus1=1;//有方块的格子是1
const int cellStatus2=2;//填充的空格子是2

const int postionCount1=1;//方块位置值，1为左边的方块，2为中间的方块，3为右边的方块
const int postionCount2=2;
const int postionCount3=3;


const int randomCount=54;//随机数数组里面的元素个数
const int randomValue[randomCount] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
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

const int itemPosType1=1;//代表方块在下方3个的左边
const int itemPosType2=2;//代表方块在下方3个的中间
const int itemPosType3=3;//代表方块在下方3个的右边

const char saveqipan[] = "saveqipan";//存储棋盘的状态
const char save_score[] = "save_score";//存储棋盘的当前得分

static const char save_moveFK_1[] = "save_moveFK_1";//存储棋盘的第1个可以移动的方块
static const char save_moveFK_2[] = "save_moveFK_2";//存储棋盘的第2个可以移动的方块
static const char save_moveFK_3[] = "save_moveFK_3";//存储棋盘的第3个可以移动的方块



