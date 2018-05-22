// PLAY.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "PLAY.h"
#include "afxdialogex.h"
#include "HELP.h"
#include "MENU.h"
#include "CSETTINS.h"
//使用透明png
#include <comdef.h>//初始化一下com口  
#include "GdiPlus.h"  
using namespace Gdiplus;
#pragma comment(lib,"gdiplus.lib")  

// PLAY 对话框

IMPLEMENT_DYNAMIC(PLAY, CDialogEx)

PLAY::PLAY(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLAY, pParent)
{

}

PLAY::~PLAY()
{
}

void PLAY::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BEGIN, m_begin);
	DDX_Control(pDX, IDC_PAUSE, m_pause);
	DDX_Control(pDX, IDC_HINT, m_hint);
	DDX_Control(pDX, IDC_SHUFFLE, m_shuffle);
	DDX_Control(pDX, IDC_STATIC3, Time);
	
}

void PLAY::InitMap()
{
}

void PLAY::ShowMap()
{
}

void PLAY::OnCancel()
{
	MENU * parent = (MENU*)GetParent();
	parent->ShowWindow(IDD_MENU);
	KillTimer(2);
	CDialogEx::OnCancel();
}


void PLAY::OnPaint()
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
		bmpbackground.LoadBitmap(IDB_BITMAP2);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);

		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);


		
	}
}

void PLAY::OnTimer(UINT_PTR nIDEvent)
{
}

bool PLAY::IsFinished()
{
	return false;
}

HBRUSH PLAY::OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor)
{

	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC3:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:
		break;
	}

	return HBRUSH();
}

BEGIN_MESSAGE_MAP(PLAY, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &PLAY::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &PLAY::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &PLAY::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &PLAY::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &PLAY::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &PLAY::OnBnClickedButton5)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_32774, &PLAY::On32774)
	ON_COMMAND(ID_32772, &PLAY::On32772)
	ON_COMMAND(ID_32773, &PLAY::Music_off)
	ON_BN_CLICKED(IDC_BEGIN, &PLAY::OnBnClickedBegin)
END_MESSAGE_MAP()


// PLAY 消息处理程序


BOOL PLAY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	font.CreatePointFont(220, _T("宋体"));
	GetDlgItem(IDC_STATIC3)->SetFont(&font);






	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

//开始
void PLAY::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}

//暂停
void PLAY::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}

//提示
void PLAY::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
}

//重排
void PLAY::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}

//设置
void PLAY::OnBnClickedButton6()
{
	CSETTINS *setting = new CSETTINS();
	setting->Create(IDD_SETTINGS);
	setting->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}

//帮助
void PLAY::OnBnClickedButton5()
{

	HELP *help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void PLAY::On32774()
{
	HELP *help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);
	// TODO: 在此添加命令处理程序代码
}

//开始音乐
void PLAY::On32772()
{
	// TODO: 在此添加命令处理程序代码
}

//关闭音乐
void PLAY::Music_off()
{
	// TODO: 在此添加命令处理程序代码
}

//开始游戏
void PLAY::OnBnClickedBegin()
{
	// TODO: 在此添加控件通知处理程序代码
	m_time = 120;//剩余时间
	Time.ShowWindow(SW_HIDE);
	Time.SetWindowTextW(_T("00 : 00 : 00"));
	Time.ShowWindow(SW_SHOW);
}
