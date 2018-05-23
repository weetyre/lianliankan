#include "stdafx.h"
#include "MusicPlayer.h"
#include <mciapi.h>


MusicPlayer::MusicPlayer()
{
}


MusicPlayer::~MusicPlayer()
{
}

void MusicPlayer::playBGM()
{
	//mciSendString(L"close at", NULL, 0, NULL);
	mciSendString(L"open ..\\music\\BGSound6.mp3 alias at", NULL, 0, NULL);
	mciSendString(L"play at", NULL, 0, NULL);
	mciSendString(L"play music repeat", NULL, 0, NULL);

}

void MusicPlayer::stopBGM()
{
	mciSendString(L"stop music", NULL, 0, NULL);
}

void MusicPlayer::playSystemSound()
{
	mciSendString(L"open ..\\music\\15.mp3 alias at", NULL, 0, NULL);
	mciSendString(L"play at", NULL, 0, NULL);
}
