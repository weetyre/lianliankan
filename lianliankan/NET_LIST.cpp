// NET_LIST.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "NET_LIST.h"
#include "afxdialogex.h"


// NET_LIST 对话框

IMPLEMENT_DYNAMIC(NET_LIST, CDialogEx)

NET_LIST::NET_LIST(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NET_LIST, pParent)
{

}

NET_LIST::~NET_LIST()
{
}

void NET_LIST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NET_LIST, CDialogEx)
END_MESSAGE_MAP()


// NET_LIST 消息处理程序
