// LOCAL_LIST.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "LOCAL_LIST.h"
#include "afxdialogex.h"
#include "lianliankanDlg.h"

// LOCAL_LIST 对话框

IMPLEMENT_DYNAMIC(LOCAL_LIST, CDialogEx)

LOCAL_LIST::LOCAL_LIST(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOCAL_LIST, pParent)
{

}

LOCAL_LIST::~LOCAL_LIST()
{
}
//排行榜具体文件操作以及读写
//直接使用变量user
void LOCAL_LIST::setText() {

	//以下是实例获取方式
	int id = user->getId();//用户名
	Record re = user->recordAt(0);//角标是记录的下标，一个用户会有多个记录包括（id,string_score,mode)
	int num_ = user->getRecordLength();//一共具有的记录个数


	string user_id = re.getInfo();//字符串的用户id
	string mode__ = re.getMode();//字符串的游戏模式
	int score__ = re.getScore();//int分数

	//变量务必使用我命名的，为了避免跟一些全局变量撞了
	//////////////////


	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);

	CString strFileName = _T("localphb.txt");
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

void LOCAL_LIST::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void LOCAL_LIST::OnPaint()
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
BEGIN_MESSAGE_MAP(LOCAL_LIST, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK, &LOCAL_LIST::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &LOCAL_LIST::OnEnChangeEdit1)
END_MESSAGE_MAP()


// LOCAL_LIST 消息处理程序


void LOCAL_LIST::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void LOCAL_LIST::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
