#pragma once
#include "lianliankan.h"
#include "afxdialogex.h"
#include "lianliankanDlg.h"


// LOCAL_LIST 对话框

class LOCAL_LIST : public CDialogEx
{
	DECLARE_DYNAMIC(LOCAL_LIST)

public:
	LOCAL_LIST(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LOCAL_LIST();
	afx_msg void OnPaint();
	HICON m_hIcon;
	virtual void setText();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOCAL_LIST };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
};
