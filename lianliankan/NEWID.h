#pragma once


// NEWID 对话框

class NEWID : public CDialogEx
{
	DECLARE_DYNAMIC(NEWID)

public:

	NEWID(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~NEWID();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	HICON m_hIcon;
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEWID };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
