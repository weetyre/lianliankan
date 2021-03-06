
// lianliankanDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "lianliankanDlg.h"
#include "afxdialogex.h"
#include "MENU.h"
#include "NEWID.h"
#include "Client.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

User *user = new User();
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void B_MUsic_on();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ClianliankanDlg 对话框



ClianliankanDlg::ClianliankanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIANLIANKAN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void ClianliankanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON3, deleteUser);
	DDX_Control(pDX, IDC_BUTTON4, exitAtLogin);
}

BEGIN_MESSAGE_MAP(ClianliankanDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &ClianliankanDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ClianliankanDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &ClianliankanDlg::OnBnClickedButton4)
	ON_LBN_SELCHANGE(IDC_LIST2, &ClianliankanDlg::OnLbnSelchangeList2)
	ON_BN_CLICKED(IDC_BUTTON3, &ClianliankanDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// ClianliankanDlg 消息处理程序
void ClianliankanDlg::hideWindow()
{
	// TODO: 在此处添加消息处理程序代码
	static bool bNotPaint = true;
	if (bNotPaint)
	{
		ShowWindow(SW_HIDE);
		bNotPaint = false;
	}
	else
	{
		CDialogEx::OnNcPaint();
	}
}

BOOL ClianliankanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	AllocConsole();
    freopen("CONOUT$", "a+", stdout);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void ClianliankanDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void ClianliankanDlg::OnPaint()
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
		bmpbackground.LoadBitmap(IDB_BITMAP3);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);
		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);

		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ClianliankanDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//登录
void ClianliankanDlg::OnClickedButton1()
{
	MENU *menu = new MENU();
	menu->Create(IDD_MENU);
	menu->ShowWindow(SW_SHOW);

	this->hideWindow();//隐藏主窗口
	// TODO: 在此添加控件通知处理程序代码
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}

//注册
void ClianliankanDlg::OnBnClickedButton2()
{
	NEWID *newid = new NEWID();
	newid->Create(IDD_NEWID);
	newid->ShowWindow(SW_SHOW);

	
	// TODO: 在此添加控件通知处理程序代码
}


void ClianliankanDlg::OnBnClickedButton4()
{
	exit(0);
	// TODO: 在此添加控件通知处理程序代码
}


void ClianliankanDlg::OnLbnSelchangeList2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void ClianliankanDlg::OnBnClickedButton3()
{
	CString s1, s2;
	GetDlgItemText(IDC_EDIT2, s1); //第一个变量为控件名，第二个为赋值的地址  
	GetDlgItemText(IDC_EDIT1, s2); //第一个变量为控件名，第二个为赋值的地址
	std::string strID(CW2A(s1.GetString()));       //CString 转string
	std::string strPW(CW2A(s2.GetString()));       //CString 转string
	if (s1.GetLength() == 0) {
		AfxMessageBox(_T("请输入账号！"));
	}
	else {
		string sendstr = strID + "##" + strPW;
		int ok = sendms(sendstr);
		if (ok == 1)
		{
			AfxMessageBox(_T("登录成功！"));
			user->setId(atol(strID.c_str()));
			user->setPassword(strPW);

			MENU *menu = new MENU();
			menu->Create(IDD_MENU);
			menu->ShowWindow(SW_SHOW);

			this->hideWindow();//隐藏主窗口

		//CDialogEx::OnOK();
		}
		else {
			AfxMessageBox(_T("登录失败！"));
		}
	}
	
	// TODO: 在此添加控件通知处理程序代码
}


