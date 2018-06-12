#pragma once
#include "PLAY.h"
#include "MusicPlayer.h"
// CSETTINS 对话框

class CSETTINS : public CDialogEx
{
	DECLARE_DYNAMIC(CSETTINS)

public:
	
	CSETTINS(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSETTINS();
	afx_msg void OnPaint();
	HICON m_hIcon;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTINGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	static bool music_switch;
	static bool music_switch_q;
   
};
