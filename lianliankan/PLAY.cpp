// PLAY.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "PLAY.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(PLAY, CDialogEx)
END_MESSAGE_MAP()


// PLAY 消息处理程序


BOOL PLAY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
