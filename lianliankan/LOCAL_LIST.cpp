// LOCAL_LIST.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "LOCAL_LIST.h"
#include "afxdialogex.h"


// LOCAL_LIST 对话框

IMPLEMENT_DYNAMIC(LOCAL_LIST, CDialogEx)

LOCAL_LIST::LOCAL_LIST(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOCAL_LIST, pParent)
{

}

LOCAL_LIST::~LOCAL_LIST()
{
}

void LOCAL_LIST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LOCAL_LIST, CDialogEx)
END_MESSAGE_MAP()


// LOCAL_LIST 消息处理程序
