#pragma once

#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include<string>
#include<Windows.h>  

#pragma comment(lib,"Winmm.lib")//∑≈“Ù¿÷µƒ≥Ã–Ú

typedef  int(__stdcall* w32mci)(const char*, char*, int, int);
typedef int(__stdcall *  w32mcierror)(int, char*, int);

class Mci
{
private:
	HINSTANCE hins;
	w32mci wmci;
	w32mcierror wmcierror;
public:
	Mci();
	~Mci();
	char buf[256];
	bool send(std::string command);//error  return false   
};

/*
 * Actually, we can call it soundPlayer.
 * you can create a instance at first and use musicPlayer.load(filename)
 * to open a audio file and use musicPlayer.player() to play it.
 */
class MusicPlayer
{
private:
	Mci mci;
	std::string filename;
	std::string alias;
	int length_ms;
public:
	MusicPlayer();
	~MusicPlayer();
	bool load(const  std::string& _filename);
	bool play(int start_ms = 0, int end_ms = -1);
	bool stop();
	bool pause();
	bool unpause();
	int milliseconds();
};

#endif
