// NEWID.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "NEWID.h"
#include "afxdialogex.h"
#include "Client.h"
#include <stdlib.h>



// NEWID 对话框

IMPLEMENT_DYNAMIC(NEWID, CDialogEx)

NEWID::NEWID(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEWID, pParent)
{

}

NEWID::~NEWID()
{
}

HBRUSH NEWID::OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor)
{

	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC0:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	case IDC_STATIC2:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:
		break;
	}

	return HBRUSH();
}

void NEWID::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void NEWID::OnPaint()
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
		bmpbackground.LoadBitmap(IDB_BITMAP6);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);

		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);


	}
}
BEGIN_MESSAGE_MAP(NEWID, CDialogEx)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDOK, &NEWID::OnBnClickedOk)
END_MESSAGE_MAP()


// NEWID 消息处理程序


void NEWID::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s1, s2;
	GetDlgItemText(IDC_EDIT2, s1); //第一个变量为控件名，第二个为赋值的地址  
	GetDlgItemText(IDC_EDIT1, s2); //第一个变量为控件名，第二个为赋值的地址
	std::string strID(CW2A(s1.GetString()));       //CString 转string
	std::string strPW(CW2A(s2.GetString()));       //CString 转string
	if (s1.GetLength() == 0) {
		AfxMessageBox(_T("请输入账号账号！"));
	}
	else {
		string sendstr = strID + "##" + strPW;
		int ok = addIDOnserver(sendstr);
		if (ok == 1)
		{
			AfxMessageBox(_T("账号注册成功！"));
			
			CDialogEx::OnOK();
		}
		else {
			AfxMessageBox(_T("此账号已存在！"));
		}
	}
	
}
