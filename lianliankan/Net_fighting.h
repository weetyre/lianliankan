#pragma once


// Net_fighting 对话框

class Net_fighting : public CDialogEx
{
	DECLARE_DYNAMIC(Net_fighting)

public:
	Net_fighting(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Net_fighting();
	CMenu menu;
	virtual BOOL OnInitDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void B_MUSIC_O();
	afx_msg void B_MUSIC_OFF();
	afx_msg void Q_MUSIC_ON();
	afx_msg void Q_MUSIC_OFF();
	afx_msg void OnPaint();
	afx_msg void HELP();
};
