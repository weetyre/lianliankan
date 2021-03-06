#pragma once
#include "MusicPlayer.h"
#include "PLAY.h"
#include "Game.h"
#include "set.h"
//网络套接字
#include <WinSock2.h>  
#include <WS2tcpip.h>  
//多线程
#pragma comment(lib,"ws2_32.lib")  

#define SERVERIP "127.0.0.1"//IP地址  
#define SERVERPORT 8025//端口号  
// Net_fighting 对话框

class Net_fighting : public CDialogEx
{
	DECLARE_DYNAMIC(Net_fighting)

public:
	Net_fighting(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Net_fighting();
	CMenu menu;
	virtual BOOL OnInitDialog();
	
	static Game *game_; //
	static Game *game_NET; //
	static MusicPlayer * music;
	static MusicPlayer * music_b;
	static PLAY * play_;
	int sum;
	int cur;
	bool firstPause = false;//第一次按暂停按钮
	CFont font;//字体
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif
private:
	set m_btnGroup;//Button 数组 ，存放按钮
	set m_btnGroup_net;//Button 数组 ，存放按钮
	int m_typeNum = 16;
	int m_time;//剩余时间，单位为秒

	void InitMap();
	void InitMap_net();
	void ShowMap();
	void ShowMap_net();
	void launch_CLIENT();
	bool IsFinished_();
	void launch_server();
	void launch_paint();
	//线程
	void t1();
	void t2();
	static void *t1_(void*);
	static void *t2_(void*);
	static void *paint_(void*);
	//线程函数
	//画路经时保存首尾连接点
	CPoint pt1;
	CPoint pt2;
	CPoint pt3;
	CPoint pt4;

	afx_msg void OnTimer(UINT_PTR nIDEvent);

	

	CStatic count;//倒计时

				  //倒计时

	CString count_time;
	CStatic Time;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	bool IsFinished();//判断是否通关
	afx_msg void B_MUSIC_O();
	afx_msg void B_MUSIC_OFF();
	afx_msg void Q_MUSIC_ON();
	afx_msg void Q_MUSIC_OFF();
	afx_msg void OnPaint();
	afx_msg void HELP_();
	afx_msg void BEGIN();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void shuffle();
	afx_msg void HINT();
	afx_msg void OnBnClickedButton1();
	CStatic user_idd_loc;
	int id_loc;
	CButton hint_switch;
	//网络处理
	//服务器
	char szhost[256];
	char clhost[256];
	WORD version = MAKEWORD(2, 2);
	WSADATA Ipdata;
	SOCKET listenSock;
	sockaddr_in hostAddr;
	sockaddr_in clientAddr;
	//客户端
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA initData;
	SOCKET mysocket;
	sockaddr_in hostAddr_c;
	in_addr addr_;

	CFile memFile;//准备序列化
	SOCKET clientSock;


	CButton h__shuffle;
};
