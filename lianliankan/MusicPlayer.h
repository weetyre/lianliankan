#pragma once

#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_

#pragma comment(lib,"Winmm.lib")//�����ֵĳ���

class MusicPlayer
{
public:
	MusicPlayer();
	~MusicPlayer();

	void setBGM(char * filename);

	void playBGM();
	void stopBGM();

	void playSystemSound();
};

#endif