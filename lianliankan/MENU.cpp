// MENU.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "afxdialogex.h"
#include "MENU.h"
#include  "PLAY.h"

// MENU 对话框

IMPLEMENT_DYNAMIC(MENU, CDialogEx)

MENU::MENU(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MENU, pParent)
{

}

MENU::~MENU()
{
}

void MENU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MENU, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MENU::OnClickedButton1)
END_MESSAGE_MAP()


// MENU 消息处理程序


void MENU::OnClickedButton1()
{
	PLAY *play = new PLAY();
	play->Create(IDD_PLAY);
	play->ShowWindow(SW_SHOW);

	/*MENU *menu = new MENU();
	menu->Create(IDD_MENU);
	menu->ShowWindow(SW_HIDE);*/


	// TODO: 在此添加控件通知处理程序代码
}
