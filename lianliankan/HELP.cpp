// HELP.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "HELP.h"
#include "afxdialogex.h"


// HELP 对话框

IMPLEMENT_DYNAMIC(HELP, CDialogEx)

HELP::HELP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HELP, pParent)
{

}

HELP::~HELP()
{
}

void HELP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HELP, CDialogEx)
END_MESSAGE_MAP()


// HELP 消息处理程序
