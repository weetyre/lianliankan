#pragma once


// PLAY 对话框
class PLAY : public CDialogEx
{
	DECLARE_DYNAMIC(PLAY)

public:
	PLAY(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PLAY();

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
