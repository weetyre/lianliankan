#pragma once


// PLAY2 对话框

class PLAY2 : public CDialogEx
{
	DECLARE_DYNAMIC(PLAY2)

public:
	PLAY2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PLAY2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLAY2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
