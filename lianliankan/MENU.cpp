// MENU.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "afxdialogex.h"
#include "MENU.h"
#include "PLAY.h"
#include "HELP.h"
#include "LOCAL_LIST.h"
#include "NET_LIST.h"
#include "Net_fighting.h"

IMPLEMENT_DYNAMIC(MENU, CDialogEx)
int mode = 0;
MENU::MENU(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MENU, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

MENU::~MENU()
{
	
}

void MENU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


void MENU::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		//////////////////////////////////////////////////////////////////////////
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

HCURSOR MENU::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL MENU::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

									// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void MENU::OnPaint()
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
		bmpbackground.LoadBitmap(IDB_BITMAP1);
		 

		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);
		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);




	}
}



BEGIN_MESSAGE_MAP(MENU, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MENU::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &MENU::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MENU::OnBnClickedButton4)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON6, &MENU::OnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &MENU::OnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON5, &MENU::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &MENU::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &MENU::OnBnClickedButton9)
END_MESSAGE_MAP()

// MENU 消息处理程序

//游戏1
Game * PLAY::game = new Game();
void MENU::OnClickedButton1()
{
	mode = 1;
	PLAY::game->setDifficulty(8);
	
	PLAY *play = new PLAY();
	play->Create(IDD_PLAY);
	play->ShowWindow(SW_SHOW);

	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}

//本地排行榜
void MENU::OnBnClickedButton3()
{
	LOCAL_LIST *nlsit = new LOCAL_LIST();
	nlsit->Create(IDD_LOCAL_LIST);
	nlsit->ShowWindow(SW_SHOW);
	nlsit->setText();
	// TODO: 在此添加控件通知处理程序代码
}

//网络对战
void MENU::OnBnClickedButton4()
{
	Net_fighting *fighting = new Net_fighting();
	fighting->Create(IDD_DIALOG1);
	fighting->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
	//一些初始化

	CDialogEx::OnCancel();
}

//游戏3
void MENU::OnClickedButton6()
{
	mode = 3;
	PLAY::game->setDifficulty(12);
	PLAY *play3 = new PLAY();
	play3->Create(IDD_PLAY);
	play3->ShowWindow(SW_SHOW);

	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码*/
}

//游戏2
void MENU::OnClickedButton7()
{
	mode = 2;
	PLAY::game->setDifficulty(10);
	PLAY *play2 = new PLAY();
	play2->Create(IDD_PLAY);
	play2->ShowWindow(SW_SHOW);

	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码*/
}


//网络排行榜
void MENU::OnBnClickedButton5()
{
	NET_LIST *nlist = new NET_LIST();
	nlist->Create(IDD_NET_LIST);
	nlist->ShowWindow(SW_SHOW);

	nlist->setText();
	// TODO: 在此添加控件通知处理程序代码
}

//帮助
void MENU::OnBnClickedButton8()
{
	HELP *help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);
	help->setText();
	// TODO: 在此添加控件通知处理程序代码
}


void MENU::OnBnClickedButton9()
{
	exit(1);
	// TODO: 在此添加控件通知处理程序代码
}
