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
	ON_BN_CLICKED(IDC_BUTTON3, &PLAY::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &PLAY::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &PLAY::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &PLAY::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &PLAY::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &PLAY::OnBnClickedButton5)
END_MESSAGE_MAP()


// PLAY 消息处理程序


BOOL PLAY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

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
	// TODO: 在此添加控件通知处理程序代码
}

//帮助
void PLAY::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
}
