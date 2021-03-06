// Net_fighting.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "Net_fighting.h"
#include "afxdialogex.h"
#include "HELP.h"
#include "CBUTTON.h"
#include "MENU.h"
#include "lianliankanDlg.h"
using namespace std;
MusicPlayer* Net_fighting::music = new MusicPlayer();
MusicPlayer* Net_fighting::music_b = new MusicPlayer();
//PLAY* Net_fighting::play_ = new PLAY();
// Net_fighting 对话框

IMPLEMENT_DYNAMIC(Net_fighting, CDialogEx)

Net_fighting::Net_fighting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

BOOL Net_fighting::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	menu.LoadMenu(IDR_MENU2);
	SetMenu(&menu);

	font.CreatePointFont(220, _T("宋体"));
	GetDlgItem(IDC_STATIC7)->SetFont(&font);
	GetDlgItem(IDC_STATIC11)->SetFont(&font);
	GetDlgItem(IDC_STATIC10)->SetFont(&font);
	hint_switch.EnableWindow(FALSE);
	h__shuffle.EnableWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
void Net_fighting::InitMap()
{
	game_->initMap();
}
void Net_fighting::InitMap_net()
{
	game_NET->initMap();
}
void Net_fighting::ShowMap()
{
	int i, j;
	CPoint p;//按钮的位置
	CString str = _T("");
	//清楚原有的按钮
	for (i = 0; i < m_btnGroup.GetSize(); i++)
		delete (CBUTTON *)m_btnGroup.GetAt(i);
	m_btnGroup.RemoveAll();
	//添加新的按钮

	for (i = 1; i < game_->getDifficulty() + 1; i++)
	{
		for (j = 1; j <game_->getDifficulty() + 1 + 2; j++)
		{
			p.x = i;
			p.y = j;

			//将按钮数组放入指针数组中
			m_btnGroup.Add(new CBUTTON(game_->map[i][j], p));
		}
	}

	//显示按钮
	sum = (game_->getDifficulty())*(game_->getDifficulty() + 2);//总共的按钮数目
	for (i = 0; i < (game_->getDifficulty())*(game_->getDifficulty() + 2); i++)
	{
		CBUTTON *btn = (CBUTTON *)m_btnGroup.GetAt(i);

		if (btn->ID > 0)
		{
			str.Format(_T("res\\%d.png"), btn->ID);

			CImage image;
			image.Load(str);

			btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE, CRect(130 + (i % (game_->getDifficulty() + 2)) * 50,
				130 + (i / (game_->getDifficulty() + 2)) * 50,
				180 + (i % (game_->getDifficulty() + 2)) * 50,
				180 + (i / (game_->getDifficulty() + 2)) * 50
			), this, IDC_BLOCK___ + 1);
			btn->SetBitmap(image);
			btn->ShowWindow(SW_SHOW);

		}
	}

}
void Net_fighting::ShowMap_net()
{
	int i, j;
	CPoint p;//按钮的位置
	CString str = _T("");
	//清楚原有的按钮
	for (i = 0; i < m_btnGroup_net.GetSize(); i++)
		delete (CBUTTON *)m_btnGroup_net.GetAt(i);
	m_btnGroup_net.RemoveAll();
	//添加新的按钮

	for (i = 1; i < game_NET->getDifficulty() + 1; i++)
	{
		for (j = 1; j < game_NET->getDifficulty() + 1 + 2; j++)
		{
			p.x = i;
			p.y = j;

			//将按钮数组放入指针数组中
			m_btnGroup_net.Add(new CBUTTON(game_NET->map[i][j], p));
		}
	}

	//显示按钮
	sum = (game_NET->getDifficulty())*(game_NET->getDifficulty() + 2);//总共的按钮数目
	for (i = 0; i < (game_NET->getDifficulty())*(game_NET->getDifficulty() + 2); i++)
	{
		CBUTTON *btn = (CBUTTON *)m_btnGroup_net.GetAt(i);

		if (btn->ID > 0)
		{
			str.Format(_T("res\\%d.png"), btn->ID);

			CImage image;
			image.Load(str);

			btn->Create(str, WS_CHILD | BS_BITMAP | WS_VISIBLE, CRect(740 + (i % (game_NET->getDifficulty() + 2)) * 50,
				130 + (i / (game_NET->getDifficulty() + 2)) * 50,
				790 + (i % (game_NET->getDifficulty() + 2)) * 50,
				180+ (i / (game_NET->getDifficulty() + 2)) * 50
			), this, IDC_BLOCK___ + 1);
			btn->SetBitmap(image);
			btn->ShowWindow(SW_SHOW);

		}
	}

}

void Net_fighting::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 1)
	{

		KillTimer(nIDEvent);
	}
	if (nIDEvent == 2 && !firstPause)
	{
		m_time--;
		int m = m_time / 60;//分钟
		int s = m_time % 60;//秒钟
		CString sm;
		CString ss;
		//一下是对格式的处理
		if (m > 9)
		{
			sm.Format(_T("%d"), m);
		}
		else if (m == 0)
		{
			sm = "00";
		}
		else {
			sm.Format(_T("%d%d"), 0, m);
		}

		if (s > 9)
		{
			ss.Format(_T("%d"), s);
		}
		else if (s == 0)
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

		if (s == 0 && m == 0 && !IsFinished())
		{
			KillTimer(nIDEvent);
			MessageBox(_T("时间到！闯关失败"), _T("失败"));
			for (int i = 0; i < m_btnGroup.GetSize(); i++)
			{
				delete(CBUTTON*)m_btnGroup.GetAt(i);
			}
			m_btnGroup.SetSize(0);
			
		}

		if (IsFinished())
		{
			KillTimer(nIDEvent);
		}



	}//人机
	if (nIDEvent == 3 && !firstPause)
	{






		if (game_NET->getHint())
		{
			MyPoint p1;
			MyPoint p2;




			CWindowDC dc2(this); // 用于绘制的设备上下文
			dc2.SetROP2(R2_NOT);//那么第一次画，出现线条，再画，就抹去了。因为他对像素点做的异或运算（同样像素值异或清0了）
			CPen pen(PS_SOLID, 5, RGB(255, 0, 0));
			dc2.SelectObject(pen);

			SetTimer(1, 100, 0);
			pt1.x = (game_NET->path->getFirst().x - 1) * 50 + 770;
			pt1.y = (game_NET->path->getFirst().y) * 50 + 155;
			pt2.x = (game_NET->path->getLast().x - 1) * 50 + 770;
			pt2.y = (game_NET->path->getLast().y) * 50 + 155;


			for (int i = 0; i < (game_NET->getDifficulty())*(game_NET->getDifficulty() + 2); i++)
			{
				CBUTTON *btn = (CBUTTON *)m_btnGroup_net.GetAt(i);

				if (game_NET->path->getFirst().y==btn->location.x&&game_NET->path->getFirst().x == btn->location.y)
				{
					btn->ShowWindow(false);
					btn->ID = 0;
					game_NET->map[btn->location.x][btn->location.y] = 0;

				}else if (game_NET->path->getLast().y == btn->location.x&&game_NET->path->getLast().x == btn->location.y)
				{
					btn->ShowWindow(false);
					btn->ID = 0;
                    game_NET->map[btn->location.x][btn->location.y] = 0;
				}
			}

			
			
			


			int i = game_NET->path->getSize();

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
				p1 = game_NET->path->get(1);
				CBUTTON::conner1.x = p1.y;
				CBUTTON::conner1.y = p1.x;
				pt3.x = (CBUTTON::conner1.y - 1) * 50 + 770;
				pt3.y = (CBUTTON::conner1.x) * 50 + 155;
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
				p1 = game_NET->path->get(1);
				CBUTTON::conner1.x = p1.y;
				CBUTTON::conner1.y = p1.x;
				p2 = game_NET->path->get(2);
				CBUTTON::conner2.x = p2.y;
				CBUTTON::conner2.y = p2.x;
				pt3.x = (CBUTTON::conner1.y - 1) * 50 + 770;
				pt3.y = (CBUTTON::conner1.x) * 50 + 155;
				pt4.x = (CBUTTON::conner2.y - 1) * 50 + 770;
				pt4.y = (CBUTTON::conner2.x) * 50 + 155;
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



			if (IsFinished_())
			{
				KillTimer(3);
				KillTimer(2);
				MessageBox(_T("你输了！"), _T("警告"));
				

				MENU *menu = new MENU();
				menu->Create(IDD_MENU);
				menu->ShowWindow(SW_SHOW);
				
				CDialogEx::OnCancel();

			}



		}
		else
		{
			MessageBox(_T("无法消除，系统将尝试重排！"), _T("警告"));
			game_NET->rearrangeMap();
			ShowMap_net();

		}



	}
}
bool Net_fighting::IsFinished()
{
	bool b = true;
	for (int i = 1; i < game_->getDifficulty() + 1; i++)
	{
		for (int j = 1; j < game_->getDifficulty() + 1 + 2; j++)
		{
			if (game_->map[i][j] != 0)
			{
				b = false;
				break;
			}
		}
	}

	return b;
	return false;
}
bool Net_fighting::IsFinished_()
{
	bool b = true;
	for (int i = 1; i < game_NET->getDifficulty() + 1; i++)
	{
		for (int j = 1; j < game_NET->getDifficulty() + 1 + 2; j++)
		{
			if (game_NET->map[i][j] != 0)
			{
				return b = false;
				
			}
		}
	}

	return b;
}
Net_fighting::~Net_fighting()
{
}

HBRUSH Net_fighting::OnCtlColor(CDC * pDC, CWnd * pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC7:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	case IDC_STATIC11:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	case IDC_STATIC10:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));

		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:
		break;
	}
	return HBRUSH();
}

void Net_fighting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC7, Time);
	DDX_Control(pDX, IDC_STATIC11, user_idd_loc);
	DDX_Control(pDX, IDC_BUTTON4, hint_switch);
	DDX_Control(pDX, IDC_BUTTON5, h__shuffle);
}


BEGIN_MESSAGE_MAP(Net_fighting, CDialogEx)

	ON_COMMAND(ID_32776, &Net_fighting::B_MUSIC_O)
	ON_COMMAND(ID_32777, &Net_fighting::B_MUSIC_OFF)
	ON_COMMAND(ID_32779, &Net_fighting::Q_MUSIC_ON)
	ON_COMMAND(ID_32780, &Net_fighting::Q_MUSIC_OFF)
	ON_COMMAND(ID_32784, &Net_fighting::HELP_)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_WM_DRAWITEM()
	ON_BN_CLICKED(IDC_BUTTON3, &Net_fighting::BEGIN)
	ON_BN_CLICKED(IDC_BUTTON2, &Net_fighting::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &Net_fighting::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON5, &Net_fighting::shuffle)
	ON_BN_CLICKED(IDC_BUTTON4, &Net_fighting::HINT)
	ON_BN_CLICKED(IDC_BUTTON1, &Net_fighting::OnBnClickedButton1)
END_MESSAGE_MAP()


// Net_fighting 消息处理程序


void Net_fighting::B_MUSIC_O()
{
	music_b->load("像风一样.mp3");
	music_b->playAndRepeat(1);
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::B_MUSIC_OFF()
{
	music_b->stop();
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::Q_MUSIC_ON()
{
	music->load("15.mp3");
	music->playAndRepeat(0);
	// TODO: 在此添加命令处理程序代码
}


void Net_fighting::Q_MUSIC_OFF()
{
	music->stop();
	// TODO: 在此添加命令处理程序代码
}

void Net_fighting::OnPaint()
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
		cur += 2;
		music->playAndRepeat(0);
		SetTimer(1, 100, 0);
		pt1.x = (CBUTTON::firstbutton->location.y - 1) * 50 + 155;
		pt1.y = (CBUTTON::firstbutton->location.x) * 50 + 155;
		pt2.x = (CBUTTON::secondbutton->location.y - 1) * 50 + 155;
		pt2.y = (CBUTTON::secondbutton->location.x) * 50 + 155;


		int i = game_->path->getSize();

		if (i == 2)
		{
			dc2.MoveTo(pt1);
			dc2.LineTo(pt2);
			Sleep(100);
			//等待0.1秒消除线条
			//没有拐弯的情况
			dc2.MoveTo(pt1);
			dc2.LineTo(pt2);
		}
		else if (i == 3)
		{
			//一个拐弯
			p1 = game_->path->get(1);
			CBUTTON::conner1.x = p1.y;
			CBUTTON::conner1.y = p1.x;
			pt3.x = (CBUTTON::conner1.y - 1) * 50 + 155;
			pt3.y = (CBUTTON::conner1.x) * 50 + 155;
			dc2.MoveTo(pt1);
			dc2.LineTo(pt3);
			dc2.LineTo(pt2);
			Sleep(100);
			//等待0.1秒消除线条
			//没有拐弯的情况
			dc2.MoveTo(pt1);
			dc2.LineTo(pt3);
			dc2.LineTo(pt2);

		}
		else if (i == 4)
		{
			//两个拐弯
			p1 = game_->path->get(1);
			CBUTTON::conner1.x = p1.y;
			CBUTTON::conner1.y = p1.x;
			p2 = game_->path->get(2);
			CBUTTON::conner2.x = p2.y;
			CBUTTON::conner2.y = p2.x;
			pt3.x = (CBUTTON::conner1.y - 1) * 50 + 155;
			pt3.y = (CBUTTON::conner1.x) * 50 + 155;
			pt4.x = (CBUTTON::conner2.y - 1) * 50 + 155;
			pt4.y = (CBUTTON::conner2.x) * 50 + 155;
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
		bmpbackground.LoadBitmap(IDB_BITMAP8);


		BITMAP M_BITMAP;
		bmpbackground.GetBitmap(&M_BITMAP);

		CBitmap *pbmpOLD = dcBmp.SelectObject(&bmpbackground);

		//避免图片失去真，因为使用stretch函数来拉伸图片
		dc.SetStretchBltMode(COLORONCOLOR);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, M_BITMAP.bmWidth, M_BITMAP.bmHeight, SRCCOPY);

}


void Net_fighting::HELP_()
{
	HELP * help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);

	help->setText();
	// TODO: 在此添加命令处理程序代码
}

    Net_fighting * CBUTTON::game3;
	Net_fighting * CBUTTON::game3_net;
	Game * Net_fighting::game_ = new Game();
	Game * Net_fighting::game_NET = new Game();

void Net_fighting::BEGIN()
{

	launch_server();
	launch_CLIENT();

	hint_switch.EnableWindow(TRUE);
	h__shuffle.EnableWindow(true);
	game_->setDifficulty(8);
	game_NET->setDifficulty(8);
	id_loc=user->getId();
	CString s;
	s.Format(_T("%d"), id_loc);
	user_idd_loc.SetWindowTextW(s);

	m_time = 120;//剩余时间
	Time.ShowWindow(SW_HIDE);
	Time.SetWindowTextW(_T("00 : 00 : 00"));
	Time.ShowWindow(SW_SHOW);
	SetTimer(2, 1000, NULL);
	InitMap();
	InitMap_net();
	ShowMap();
	ShowMap_net();
	SetTimer(3, 1500, NULL);
	CBUTTON::game3 = this;
	CBUTTON::game3_net = this;
	


}


void Net_fighting::OnBnClickedButton2()
{
	HELP * help = new HELP();
	help->Create(IDD_HELP);
	help->ShowWindow(SW_SHOW);
	help->setText();
	// TODO: 在此添加命令处理程序代码
	// TODO: 在此添加控件通知处理程序代码
}


void Net_fighting::OnBnClickedCancel()
{

	MENU *menu = new MENU();
	menu->Create(IDD_MENU);
	menu->ShowWindow(SW_SHOW);

	KillTimer(2);
	CDialogEx::OnCancel();
	
}


void Net_fighting::shuffle()
{
	game_->rearrangeMap();
	ShowMap();
	// TODO: 在此添加控件通知处理程序代码
}


void Net_fighting::HINT()
{

	if (game_->getHint())
	{
		MyPoint p1;
		MyPoint p2;




		CWindowDC dc2(this); // 用于绘制的设备上下文
		dc2.SetROP2(R2_NOT);//那么第一次画，出现线条，再画，就抹去了。因为他对像素点做的异或运算（同样像素值异或清0了）
		CPen pen(PS_SOLID, 5, RGB(255, 0, 0));
		dc2.SelectObject(pen);

		SetTimer(1, 100, 0);
		pt1.x = (game_->path->getFirst().x - 1) * 50 + 155;
		pt1.y = (game_->path->getFirst().y) * 50 + 155;
		pt2.x = (game_->path->getLast().x - 1) * 50 + 155;
		pt2.y = (game_->path->getLast().y) * 50 + 155;


		int i = game_->path->getSize();

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
			p1 = game_->path->get(1);
			CBUTTON::conner1.x = p1.y;
			CBUTTON::conner1.y = p1.x;
			pt3.x = (CBUTTON::conner1.y - 1) * 50 + 155;
			pt3.y = (CBUTTON::conner1.x) * 50 + 155;
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
			p1 = game_->path->get(1);
			CBUTTON::conner1.x = p1.y;
			CBUTTON::conner1.y = p1.x;
			p2 = game_->path->get(2);
			CBUTTON::conner2.x = p2.y;
			CBUTTON::conner2.y = p2.x;
			pt3.x = (CBUTTON::conner1.y - 1) * 50 + 155;
			pt3.y = (CBUTTON::conner1.x) * 50 + 155;
			pt4.x = (CBUTTON::conner2.y - 1) * 50 + 155;
			pt4.y = (CBUTTON::conner2.x) * 50 + 155;
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
	// TODO: 在此添加控件通知处理程序代码
}

//认输
void Net_fighting::OnBnClickedButton1()
{

	if (MessageBox(_T("是否认输？"), _T("提示"), MB_YESNO) == IDYES)
	{
		MENU *menu = new MENU();
		menu->Create(IDD_MENU);
		menu->ShowWindow(SW_SHOW);
		CDialogEx::OnCancel();
	}
	// TODO: 在此添加控件通知处理程序代码
}


void Net_fighting::t1() {

}

void Net_fighting::t2()
{
}

void * Net_fighting::t1_(void *__this)
{
	return 0;
}

//客户端发送
void * Net_fighting::t2_(void *__this)
{
	return 0;
	
}

void Net_fighting::launch_CLIENT()
{
	
}
void Net_fighting::launch_server()
{
}