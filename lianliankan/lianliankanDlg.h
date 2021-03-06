
// lianliankanDlg.h: 头文件
//

#pragma once
#include "User.h"
extern User * user;
// ClianliankanDlg 对话框
class ClianliankanDlg : public CDialogEx
{
// 构造
public:
	
	ClianliankanDlg(CWnd* pParent = nullptr);	// 标准构造函数
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIANLIANKAN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	virtual void hideWindow();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
	afx_msg void OnBnClickedButton2();
	// Delete a uer chosen form uer list
	CButton deleteUser;
	CButton exitAtLogin;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnBnClickedButton3();
};
