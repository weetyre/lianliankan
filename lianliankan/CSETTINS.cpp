// CSETTINS.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "CSETTINS.h"
#include "afxdialogex.h"
#include "mciapi.h"

bool CSETTINS::music_switch = false;
bool CSETTINS::music_switch_q = false;
PLAY* play_medium = new PLAY();
// CSETTINS 对话框

IMPLEMENT_DYNAMIC(CSETTINS, CDialogEx)

CSETTINS::CSETTINS(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTINGS, pParent)
{

}

CSETTINS::~CSETTINS()
{
}

void CSETTINS::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSETTINS, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &CSETTINS::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSETTINS::OnBnClickedButton2)
END_MESSAGE_MAP()


// CSETTINS 消息处理程序
void CSETTINS::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);

		CDC dcBmp;
		dcBmp.CreateCompatibleDC(&dc);
		CBitmap bmpbackground;
		bmpbackground.LoadBitmap(IDB_BITMAP7);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);

		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);




	}
}
//背景音乐函数
void CSETTINS::OnBnClickedButton1()
{

	if (!music_switch)
	{
		play_medium->music_b->load("像风一样.mp3");
		play_medium->music_b->playAndRepeat(1);
		music_switch = true;
	}
	else
	{
		play_medium->music_b->stop();
		music_switch = false;
	}

	// TODO: 在此添加控件通知处理程序代码
}

//棋子音效函数
void CSETTINS::OnBnClickedButton2()
{

	if (!music_switch_q)
	{
		play_medium->music->load("15.mp3");
		music_switch_q = true;
	}
	else
	{
		play_medium->music->stop();
		music_switch_q = false;
	}
	// TODO: 在此添加控件通知处理程序代码
}
