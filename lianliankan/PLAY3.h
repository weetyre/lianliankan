#pragma once


// PLAY3 对话框

class PLAY3 : public CDialogEx
{
	DECLARE_DYNAMIC(PLAY3)

public:
	PLAY3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PLAY3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAY3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
