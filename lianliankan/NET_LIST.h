#pragma once
#include "afxdialogex.h"
#include "lianliankan.h"
#include <iostream>
#include <fstream>

using namespace std;

// NET_LIST 对话框

class NET_LIST : public CDialogEx
{
	DECLARE_DYNAMIC(NET_LIST)

public:
	NET_LIST(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NET_LIST();
	afx_msg void OnPaint();
	HICON m_hIcon;
	virtual void setText();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NET_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
};
