// Net_fighting.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "Net_fighting.h"
#include "afxdialogex.h"


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
	ON_COMMAND(ID_32784, &Net_fighting::HELP)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Net_fighting 消息处理程序


void Net_fighting::B_MUSIC_O()
{

	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::B_MUSIC_OFF()
{
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::Q_MUSIC_ON()
{
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::Q_MUSIC_OFF()
{
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


void Net_fighting::HELP()
{
	// TODO: 在此添加命令处理程序代码
}
