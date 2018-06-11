// Net_fighting.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "Net_fighting.h"
#include "afxdialogex.h"
#include "HELP.h"
#include "CBUTTON.h"
#include "MENU.h"

MusicPlayer* Net_fighting::music = new MusicPlayer();
MusicPlayer* Net_fighting::music_b = new MusicPlayer();
//PLAY* Net_fighting::play_ = new PLAY();
// Net_fighting 对话框

IMPLEMENT_DYNAMIC(Net_fighting, CDialogEx)

Net_fighting::Net_fighting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

BOOL Net_fighting::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	menu.LoadMenu(IDR_MENU2);
	SetMenu(&menu);





	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
Net_fighting::~Net_fighting()
{
}

void Net_fighting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Net_fighting, CDialogEx)

	ON_COMMAND(ID_32776, &Net_fighting::B_MUSIC_O)
	ON_COMMAND(ID_32777, &Net_fighting::B_MUSIC_OFF)
	ON_COMMAND(ID_32779, &Net_fighting::Q_MUSIC_ON)
	ON_COMMAND(ID_32780, &Net_fighting::Q_MUSIC_OFF)
	ON_COMMAND(ID_32784, &Net_fighting::HELP_)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON3, &Net_fighting::BEGIN)
	ON_BN_CLICKED(IDC_BUTTON2, &Net_fighting::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &Net_fighting::OnBnClickedCancel)
END_MESSAGE_MAP()


// Net_fighting 消息处理程序


void Net_fighting::B_MUSIC_O()
{
	music_b->load("BGSound6.mp3");
	music_b->play();
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::B_MUSIC_OFF()
{
	music_b->stop();
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::Q_MUSIC_ON()
{
	music->load("15.mp3");
	music->play();
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::Q_MUSIC_OFF()
{
	music->stop();
	// TODO: 在此添加命令处理程序代码
}

void Net_fighting::OnPaint()
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
		bmpbackground.LoadBitmap(IDB_BITMAP8);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);

		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);



	}
}


void Net_fighting::HELP_()
{
	HELP * help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);

	help->setText();
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::BEGIN()
{
	
	// TODO: 在此添加控件通知处理程序代码
}


void Net_fighting::OnBnClickedButton2()
{
	HELP * help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);

	help->setText();
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}


void Net_fighting::OnBnClickedCancel()
{
	MENU * parent = (MENU*)GetParent();
	parent->ShowWindow(IDD_MENU);
	KillTimer(2);
	CDialogEx::OnCancel();
	
}
