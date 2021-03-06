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
	m_hIcon = AfxGetApp()->LoadIcon(IDR_HELP);
}

HELP::~HELP()
{
}

void HELP::setText() {
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDITHELP);

	/*CString strFileName = _T("localphb.txt");
	CString strValue = _T("");*/
	CString strshow = _T("1，将相同的两张图片用三根以内的直线连在一起就可以消除。\r\n");
	strshow += _T("2，每消除一次图片，都会使可用的时间增加。\r\n");
	strshow += _T("3，在规定时间里，当所有的图片都消除时，即为胜利。\r\n");
	strshow += _T("4，规定的时间内有图片未消除，即为失败。");

	/*if (!PathFileExists(strFileName))
	{
		return exit(0);
	}
	CStdioFile file;
	if (!file.Open(strFileName, CFile::modeRead))
	{
		return exit(0);
	}

	while (file.ReadString(strValue))
	{
		strshow += strValue;
		strshow += _T("\r\n");
	}
	file.Close();
*/
	pBoxOne->SetWindowText(strshow);
}


void HELP::OnPaint()
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
		bmpbackground.LoadBitmap(IDB_BITMAP4);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);
		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);




	}
}

void HELP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HELP, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

