// NEWID.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "NEWID.h"
#include "afxdialogex.h"


// NEWID 对话框

IMPLEMENT_DYNAMIC(NEWID, CDialogEx)

NEWID::NEWID(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWID, pParent)
{

}

NEWID::~NEWID()
{
}

void NEWID::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NEWID, CDialogEx)
END_MESSAGE_MAP()


// NEWID 消息处理程序
