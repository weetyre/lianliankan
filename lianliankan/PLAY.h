#pragma once
#include "Game.h"
#include "MusicPlayer.h"

// PLAY 对话框
class PLAY : public CDialogEx
{
	DECLARE_DYNAMIC(PLAY)

public:
	PLAY(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PLAY();
	afx_msg void OnPaint();
	HICON m_hIcon;

private:
	Game *game = new Game();  //
	MusicPlayer musicor;  //


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton5();
};
