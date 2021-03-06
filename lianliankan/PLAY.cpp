// PLAY.cpp: 实现文件
#include "stdafx.h"
#include "lianliankan.h"
#include "PLAY.h"
#include "afxdialogex.h"
#include "HELP.h"
#include "MENU.h"
#include "CBUTTON.h"
//使用透明png
#include <comdef.h>//初始化一下com口  
#include "GdiPlus.h"  
using namespace Gdiplus;
#pragma comment(lib,"gdiplus.lib")  
// PLAY 对话框
MusicPlayer* PLAY::music = new MusicPlayer();
MusicPlayer* PLAY::music_b = new MusicPlayer();
CSETTINS * setting = new CSETTINS();
IMPLEMENT_DYNAMIC(PLAY, CDialogEx)

int score_ = 120;


PLAY::PLAY(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLAY, pParent)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	sum = 0;
	cur = 0;
}

PLAY::~PLAY()
{

}

void PLAY::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BEGIN, m_begin);
	DDX_Control(pDX, IDC_PAUSE, m_pause);
	DDX_Control(pDX, IDC_HINT, m_hint);
	DDX_Control(pDX, IDC_SHUFFLE, m_shuffle);
	DDX_Control(pDX, IDC_STATIC3, Time);

	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_STATIC12, user_ID);
	DDX_Control(pDX, IDC_STATIC20, USER_RE_ID);
	DDX_Control(pDX, IDC_STATIC9, score);
}

void PLAY::InitMap()
{
	game->initMap();
}

void PLAY::ShowMap()
{
	int i, j;
	CPoint p;//按钮的位置
	CString str=_T("");
	//清楚原有的按钮
	for (i = 0; i < m_btnGroup.GetSize(); i++)
		delete (CBUTTON *)m_btnGroup.GetAt(i);
	m_btnGroup.RemoveAll();
	//添加新的按钮

	for (i=1;i<game->getDifficulty()+1;i++)
	{
		for (j = 1; j <  game->getDifficulty() +1+2; j++)
		{
			p.x = i;
			p.y = j;

			//将按钮数组放入指针数组中
		    m_btnGroup.Add(new CBUTTON(game->map[i][j], p));
		}
	}

	//显示按钮
	sum = (game->getDifficulty())*(game->getDifficulty() + 2);//总共的按钮数目
	for (i=0;i<(game->getDifficulty())*(game->getDifficulty()+2);i++)
	{
		CBUTTON *btn = (CBUTTON *)m_btnGroup.GetAt(i);

		if (btn->ID>0)
		{
			str.Format(_T("res\\%d.png"), btn->ID);

			CImage image;
			image.Load(str);

			btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE, CRect(70 + (i % (game->getDifficulty()+2)) * 50,
				70 + (i / (game->getDifficulty()+2)) * 50, 
				120 + (i % (game->getDifficulty()+2)) * 50,
				120 + (i /(game->getDifficulty()+2)) * 50
				),this, IDC_BLOCK___ +1);
			btn->SetBitmap(image);
			btn->ShowWindow(SW_SHOW);

		}
	}

}

void PLAY::OnCancel()
{
	MENU * parent = (MENU*)GetParent();
	parent->ShowWindow(IDD_MENU);
	KillTimer(2);
	KillTimer(4);
	CDialogEx::OnCancel();
}

void PLAY::OnPaint()
{
		MyPoint p1;
		MyPoint p2;

		CWindowDC dc2(this); // 用于绘制的设备上下文
		dc2.SetROP2(R2_NOT);//那么第一次画，出现线条，再画，就抹去了。因为他对像素点做的异或运算（同样像素值异或清0了）
		CPen pen(PS_SOLID, 5, RGB(255, 0, 0));
		dc2.SelectObject(pen);

		



		if (CBUTTON::firstbutton != NULL && CBUTTON::secondbutton != NULL)
		{

			//进度条
			cur+=2;
			music->playAndRepeat(0);
			m_progress.SetPos((int)(((float)cur / (float)sum)*100));

			int n = game->getDifficulty() * (game->getDifficulty() + 2);
			if ((n - cur) <= 30) {
				game->printVisited();
			}

			SetTimer(1, 100, 0);
			pt1.x = (CBUTTON::firstbutton->location.y - 1) * 50 + 100;
			pt1.y = (CBUTTON::firstbutton->location.x) * 50 + 90;
			pt2.x = (CBUTTON::secondbutton->location.y - 1) * 50 + 100;
			pt2.y = (CBUTTON::secondbutton->location.x) * 50 + 90;


			int i = game->path->getSize();

			if (i==2)
			{
            dc2.MoveTo(pt1);
			dc2.LineTo(pt2);
			Sleep(100);
			//等待0.1秒消除线条
			//没有拐弯的情况
			dc2.MoveTo(pt1);
			dc2.LineTo(pt2);
			}else if (i==3)
			{
				//一个拐弯
				p1 = game->path->get(1);
				CBUTTON::conner1.x = p1.y;
				CBUTTON::conner1.y = p1.x;
				pt3.x = (CBUTTON::conner1.y - 1) * 50 + 100;
				pt3.y = (CBUTTON::conner1.x) * 50 + 90;
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt2);
				Sleep(100);
				//等待0.1秒消除线条
				//没有拐弯的情况
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt2);

			}else if (i == 4)
			{
				//两个拐弯
				p1 = game->path->get(1);
				CBUTTON::conner1.x = p1.y;
				CBUTTON::conner1.y = p1.x;
				p2 = game->path->get(2);
				CBUTTON::conner2.x = p2.y;
				CBUTTON::conner2.y = p2.x;
				pt3.x = (CBUTTON::conner1.y - 1) * 50 + 100;
				pt3.y = (CBUTTON::conner1.x) * 50 + 90;
				pt4.x = (CBUTTON::conner2.y-1) * 50 + 100;
				pt4.y = (CBUTTON::conner2.x ) * 50 + 90;
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt4);
				dc2.LineTo(pt2);

				Sleep(100);
				//等待0.1秒消除线条
				//没有拐弯的情况
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt4);
				dc2.LineTo(pt2);

			}

			

		}

			//CDialogEx::OnPaint();
			CPaintDC dc(this);
			CRect rect;
			GetClientRect(&rect);

			CDC dcBmp;
			dcBmp.CreateCompatibleDC(&dc);
			CBitmap bmpbackground;
			bmpbackground.LoadBitmap(IDB_BITMAP2);


			BITMAP M_BITMAP;
			bmpbackground.GetBitmap(&M_BITMAP);

			CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);

			//避免图片失去真，因为使用stretch函数来拉伸图片
			dc.SetStretchBltMode(COLORONCOLOR);
			dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);

			CWnd::OnPaint();//防止弹不出messagebox

		
	
}
//相应计时器的信号
void PLAY::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent==1)
	{
		
		KillTimer(nIDEvent);
	}

	if (nIDEvent==2&&!firstPause)
	{
		m_time--;
		int m = m_time / 60;//分钟
		int s = m_time % 60;//秒钟
		CString sm;
		CString ss;
		//一下是对格式的处理
		if (m>9)
		{
			sm.Format(_T("%d"), m);
		}else if (m==0)
		{
			sm = "00";
		}
		else {
			sm.Format(_T("%d%d"), 0, m);
		}

		if (s>9)
		{
			ss.Format(_T("%d"), s);
		}else if (s==0)
		{
			ss = "00";
		}
		else
		{
			ss.Format(_T("%d%d"), 0, s);
		}
		Time.ShowWindow(SW_HIDE);
		Time.SetWindowTextW(_T("00: " + sm + " : " + ss));
		Time.ShowWindow(SW_SHOW);

		if (s==0&&m==0&&!IsFinished())
		{
			KillTimer(nIDEvent);
			KillTimer(4);
			MessageBox(_T("时间到！闯关失败"), _T("失败"));
			MessageBox(_T("请推出或者重新开始"), _T("失败"));
			for (int i = 0; i < m_btnGroup.GetSize(); i++)
			{
				delete(CBUTTON*)m_btnGroup.GetAt(i);
			}
			m_btnGroup.SetSize(0);
			m_pause.EnableWindow(false);
			m_hint.EnableWindow(false);
			m_shuffle.EnableWindow(false);
		}

		if (IsFinished())
		{
			m_pause.EnableWindow(false);
			m_hint.EnableWindow(false);
			m_shuffle.EnableWindow(false);
			KillTimer(nIDEvent);
		}



	}

	if (nIDEvent == 4 && !firstPause)
	{
		score_--;
		CString S__;

		S__.Format(_T("%d %s"),score_,L"分");
		score.ShowWindow(SW_HIDE);
		score.SetWindowTextW(S__);
		score.ShowWindow(SW_SHOW);

		

		if (IsFinished())
		{
			m_pause.EnableWindow(false);
			m_hint.EnableWindow(false);
			m_shuffle.EnableWindow(false);
			KillTimer(2);
			KillTimer(4);
		}



	}
}

bool PLAY::IsFinished()
{

	bool b = true;
	for (int i = 1; i < game->getDifficulty() + 1; i++)
	{
		for (int j = 1; j < game->getDifficulty() + 1+2; j++)
		{
			if (game->map[i][j] != 0)
			{
				return b = false;

			}
		}
	}

	return b;

}

HBRUSH PLAY::OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor)
{

	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC3:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,255,255));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	case IDC_STATIC12:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	case IDC_STATIC20:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	case IDC_STATIC8:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	case IDC_STATIC9:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:
		break;
	}

	return HBRUSH();
}

BEGIN_MESSAGE_MAP(PLAY, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON6, &PLAY::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &PLAY::OnBnClickedButton5)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
	ON_COMMAND(ID_32774, &PLAY::On32774)
	ON_COMMAND(ID_32772, &PLAY::On32772)
	ON_COMMAND(ID_32773, &PLAY::Music_off)
	ON_BN_CLICKED(IDC_BEGIN, &PLAY::OnBnClickedBegin)
	ON_BN_CLICKED(IDCANCEL, &PLAY::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_HINT, &PLAY::OnBnClickedHint)
	ON_BN_CLICKED(IDC_PAUSE, &PLAY::OnBnClickedPause)
	ON_BN_CLICKED(IDC_SHUFFLE, &PLAY::OnBnClickedShuffle)
	ON_COMMAND(ID_32782, &PLAY::Q1_MUSIC_ON)
	ON_COMMAND(ID_32783, &PLAY::Q1_MUSIC_OFF)
END_MESSAGE_MAP()


// PLAY 消息处理程序

BOOL PLAY::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CFont font2;

	font.CreatePointFont(220, _T("宋体"));
	font2.CreatePointFont(200, _T("宋体"));

	GetDlgItem(IDC_STATIC3)->SetFont(&font);
	GetDlgItem(IDC_STATIC12)->SetFont(&font);
	GetDlgItem(IDC_STATIC20)->SetFont(&font);
	GetDlgItem(IDC_STATIC8)->SetFont(&font2);
	GetDlgItem(IDC_STATIC9)->SetFont(&font2);

	m_hint.EnableWindow(false);
	m_shuffle.EnableWindow(false);
	HICON m_hIcon;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);//IDR_ICON为图标资源名

	//SetIcon(m_hIcon, TRUE); // Set big icon

	SetIcon(m_hIcon, FALSE); // Set small icon
	SetTimer(3, 1000, NULL);
	m_pause.EnableWindow(false);

	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//设置
void PLAY::OnBnClickedButton6()
{
	CSETTINS *setting = new CSETTINS();
	setting->Create(IDD_SETTINGS);
	setting->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}

//帮助
void PLAY::OnBnClickedButton5()
{

	HELP *help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);

	help->setText();
	// TODO: 在此添加控件通知处理程序代码
}


void PLAY::On32774()
{
	HELP *help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);
	help->setText();
	// TODO: 在此添加命令处理程序代码
}

//开始音乐
void PLAY::On32772()
{
	music_b->load("像风一样.mp3");
	music_b->playAndRepeat(1);
	// TODO: 在此添加命令处理程序代码
}

//关闭音乐
void PLAY::Music_off()
{
	music_b->stop();
	// TODO: 在此添加命令处理程序代码
}

PLAY * CBUTTON:: game2;

//开始游戏
void PLAY::OnBnClickedBegin()
{
	id = user->getId();
	score_ = 300;
	CString s;
	s.Format(_T("%d"), id);
	USER_RE_ID.SetWindowTextW(s);
	score.ShowWindow(SW_HIDE);
	score.SetWindowTextW(_T("300分"));
	score.ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代
	m_time = 120;//剩余时间
	Time.ShowWindow(SW_HIDE);
	Time.SetWindowTextW(_T("00 : 00 : 00"));
	Time.ShowWindow(SW_SHOW);
	SetTimer(2, 1000, NULL);
	SetTimer(4, 1000, NULL);
	m_hint.EnableWindow(true);
	m_shuffle.EnableWindow(true);
	InitMap();
	ShowMap();
	CBUTTON::game2 = this;
	m_pause.EnableWindow(true);
	//进度条
	m_progress.SetRange(0, 100);
	m_progress.SetStep(1);
	m_progress.SetPos(0);
	cur = 0;
}


void PLAY::OnBnClickedCancel()
{
	KillTimer(4);
	KillTimer(2);
	MENU *menu = new MENU();
	menu->Create(IDD_MENU);
	menu->ShowWindow(SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();

}

//提示按钮
void PLAY::OnBnClickedHint()
{
	if (game->getHint())
	{
		MyPoint p1;
		MyPoint p2;

        


		CWindowDC dc2(this); // 用于绘制的设备上下文
		dc2.SetROP2(R2_NOT);//那么第一次画，出现线条，再画，就抹去了。因为他对像素点做的异或运算（同样像素值异或清0了）
		CPen pen(PS_SOLID, 5, RGB(255, 0, 0));
		dc2.SelectObject(pen);
		
			SetTimer(1, 100, 0);
			pt1.x = (game->path->getFirst().x - 1) * 50 + 100;
			pt1.y = (game->path->getFirst().y) * 50 + 90;
			pt2.x = (game->path->getLast().x - 1) * 50 + 100;
			pt2.y = (game->path->getLast().y) * 50 + 90;


			int i = game->path->getSize();

			if (i == 2)
			{
				dc2.MoveTo(pt1);
				dc2.LineTo(pt2);
				Sleep(300);
				//等待0.1秒消除线条
				//没有拐弯的情况
				dc2.MoveTo(pt1);
				dc2.LineTo(pt2);
			}
			else if (i == 3)
			{
				//一个拐弯
				p1 = game->path->get(1);
				CBUTTON::conner1.x = p1.y;
				CBUTTON::conner1.y = p1.x;
				pt3.x = (CBUTTON::conner1.y - 1) * 50 + 100;
				pt3.y = (CBUTTON::conner1.x) * 50 + 90;
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt2);
				Sleep(300);
				//等待0.1秒消除线条
				//没有拐弯的情况
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt2);

			}
			else if (i == 4)
			{
				//两个拐弯
				p1 = game->path->get(1);
				CBUTTON::conner1.x = p1.y;
				CBUTTON::conner1.y = p1.x;
				p2 = game->path->get(2);
				CBUTTON::conner2.x = p2.y;
				CBUTTON::conner2.y = p2.x;
				pt3.x = (CBUTTON::conner1.y - 1) * 50 + 100;
				pt3.y = (CBUTTON::conner1.x) * 50 + 90;
				pt4.x = (CBUTTON::conner2.y - 1) * 50 + 100;
				pt4.y = (CBUTTON::conner2.x) * 50 + 90;
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt4);
				dc2.LineTo(pt2);

				Sleep(300);
				//等待0.1秒消除线条
				//没有拐弯的情况
				dc2.MoveTo(pt1);
				dc2.LineTo(pt3);
				dc2.LineTo(pt4);
				dc2.LineTo(pt2);

			}



		



	}
	else
	{
		MessageBox(_T("无法消除，请尝试重排！"), _T("警告"));
	    
	}
	// TODO: 在此添加控件通知处理程序代码
}

//暂停按钮
void PLAY::OnBnClickedPause()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!firstPause)//第一次点击暂停按钮
	{
		firstPause = true;
		for (int i = 0; i < (game->getDifficulty())*(game->getDifficulty() + 2); i++)
		{
			CBUTTON *btn = (CBUTTON *)m_btnGroup.GetAt(i);
			if (btn->ID > 0)
			{
				//使按钮消失不见
				
				btn->ShowWindow(SW_HIDE);

			}

		}
		m_begin.EnableWindow(false);
		m_hint.EnableWindow(false);
		m_shuffle.EnableWindow(false);
		m_pause.SetWindowTextW(_T("继续游戏"));

	}//第二次点击暂停按钮
	else {
		firstPause = false;
		for (int i = 0; i < (game->getDifficulty())*(game->getDifficulty() + 2); i++)
		{
			CBUTTON *btn = (CBUTTON *)m_btnGroup.GetAt(i);
			if (btn->ID > 0)
			{
				//使按钮可见

				btn->ShowWindow(SW_SHOW);

			}

		}
		m_begin.EnableWindow(true);
		m_hint.EnableWindow(true);
		m_shuffle.EnableWindow(true);
		m_pause.SetWindowTextW(_T("暂停游戏"));
	}
}


void PLAY::OnBnClickedShuffle()
{
	game->rearrangeMap();
	ShowMap();
	// TODO: 在此添加控件通知处理程序代码
}


void PLAY::Q1_MUSIC_ON()
{
	music->load("15.mp3");
	

	// TODO: 在此添加命令处理程序代码
}


void PLAY::Q1_MUSIC_OFF()
{
	music->stop();
	// TODO: 在此添加命令处理程序代码
}
