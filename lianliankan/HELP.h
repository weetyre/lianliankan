#pragma once


// HELP 对话框

class HELP : public CDialogEx
{
	DECLARE_DYNAMIC(HELP)

public:
	HELP(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~HELP();
	afx_msg void OnPaint();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HELP };
#endif

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
