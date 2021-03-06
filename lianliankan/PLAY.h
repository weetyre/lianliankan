#pragma once
#include "Game.h"
#define Max_x 10//地图的行数
#define Max_y 10//地图的列数
#define IDC_BLOCK 103//按钮ID
#include "CSETTINS.h"
#include "MusicPlayer.h"
// PLAY 对话框
#include "lianliankanDlg.h"
extern int score_ ;
class PLAY : public CDialogEx
{
	DECLARE_DYNAMIC(PLAY)

public:
	PLAY(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PLAY();
	static Game *game; //
	static MusicPlayer * music;
	static MusicPlayer * music_b;
	//对话框数据
	//enum {IDD=IDD_DIALOG1};

private:
    #define IDC_BLOCK___ 300

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CPtrArray m_btnGroup;//Button 数组 ，存放按钮
public:
	CFont font;//字体
	int m_typeNum = 16;
	int m_time;//剩余时间，单位为秒

	void InitMap();
	void ShowMap();
	void PLAY::OnCancel();//关闭窗口

	///画图函数
	afx_msg void OnPaint();

	HICON m_hIcon;
	//画路经时保存首尾连接点
	CPoint pt1;
	CPoint pt2;
	CPoint pt3;
	CPoint pt4;

	bool isRelax = false;//暂停

	//计时器响应函数，用于擦除画的线
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	bool IsFinished();//判断是否通关

	CStatic count;//倒计时

	//倒计时

	CString count_time;
	CStatic Time;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	bool firstPause = false;//第一次按暂停按钮

	bool hintEnable = false;//提示按钮是否可用
	bool shuffleEnable = false;//重拍按钮是否可用



public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
	ULONG_PTR m_gdiplusToken;
	afx_msg void On32774();
	afx_msg void On32772();
	afx_msg void Music_off();
	CButton m_begin;
	CButton m_pause;
	CButton m_hint;
	CButton m_shuffle;
	afx_msg void OnBnClickedBegin();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedHint();
	afx_msg void OnBnClickedPause();
	afx_msg void OnBnClickedShuffle();
	CProgressCtrl m_progress;
	int sum;
	int cur;
	int id;
	afx_msg void Q1_MUSIC_ON();
	afx_msg void Q1_MUSIC_OFF();
	CStatic user_ID;
	CStatic USER_RE_ID;
	CStatic score;
	
};
