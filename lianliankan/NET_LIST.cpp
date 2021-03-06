// NET_LIST.cpp: 实现文件
//

#include "stdafx.h"
#include "NET_LIST.h"

// NET_LIST 对话框

IMPLEMENT_DYNAMIC(NET_LIST, CDialogEx)

NET_LIST::NET_LIST(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NET_LIST, pParent)
{
	
}

NET_LIST::~NET_LIST()
{
}




void NET_LIST::setText() {

	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT2);

	CString strFileName = _T("netphb.txt");
	CString strValue = _T("");
	CString strshow = _T("");
	if (!PathFileExists(strFileName))
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

	pBoxOne->SetWindowText(strshow);
}

void NET_LIST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
void NET_LIST::OnPaint()
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
		bmpbackground.LoadBitmap(IDB_BITMAP5);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);

		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);




	}
}

BEGIN_MESSAGE_MAP(NET_LIST, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// NET_LIST 消息处理程序
