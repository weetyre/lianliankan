#pragma once
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

