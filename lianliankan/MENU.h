#pragma once

// MENU 对话框
#include "resource.h"

extern int mode;


class MENU : public CDialogEx
{
	DECLARE_DYNAMIC(MENU)

public:
	MENU(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MENU();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU };
#endif

protected:

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()


public:
	

	afx_msg void OnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnClickedButton6();
	afx_msg void OnClickedButton7();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	
};


