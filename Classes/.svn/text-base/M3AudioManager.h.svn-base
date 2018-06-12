/*
 * M3aAudioManager.h
 *
 *  Created on: 2013-1-24
 *      Author: alex
 */

#ifndef M3AAUDIOMANAGER_H_
#define M3AAUDIOMANAGER_H_

#include "cocos2d.h"

class M3AudioManager : public cocos2d::CCObject{
public:
	~M3AudioManager();
	bool init();
	static M3AudioManager* shareInstance();
	static void playBackground();
	static void stopBackground();
	static void pauseBackground();
	static void resumeBackground();
	void playSound(int num);
    static bool isPlayBackground();//是否正在播放
    static void rePlayBackground();//如果背景音乐结束，播放一个新的背景音乐
};


#endif /* M3AAUDIOMANAGER_H_ */
