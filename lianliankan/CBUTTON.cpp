// CBUTTON.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "CBUTTON.h"
#include "Game.h"
#include "Client.h"
#include <iostream>
#include <fstream>
using namespace std;
void addOneUserMessage(string name, int scores, string clss) {
	string strsend;
	strsend = "userid: ";
	strsend += name;
	strsend += "!!scores: ";
	strsend += to_string(scores);
	strsend += "!!class : ";
	strsend += clss;
	int ok = sendms(strsend);
	cout << "增加一条消息";
	cout << ok << endl;
	//ofstream  input_file;
	//input_file.open("localphb.txt", ios::app);//在文件的结尾进行文件的操作，写入.
	//if (!input_file.is_open()) {
	//	cout << "file open erro!" << endl;
	//}
	//else {
	//	input_file << "userid: " << name.data() << "!!";
	//	input_file << "scores: " << scores << "!!";
	//	input_file << "class: " << clss.data() << endl;

	//	cout << "增加一条消息" << endl;
	//	input_file.close();
	//}
}


// CBUTTON
CBUTTON* CBUTTON::firstbutton = NULL;
CBUTTON* CBUTTON::secondbutton = NULL;
CPoint CBUTTON::conner1(-1, -1);
CPoint CBUTTON::conner2(-1, -1);

IMPLEMENT_DYNAMIC(CBUTTON, CButton)

CBUTTON::CBUTTON()
{
	ID = 0;
	location = 0;
}

CBUTTON::~CBUTTON()
{
}

CBUTTON::CBUTTON(int type, CPoint point)
{
	ID = type;
	location = point;
}

bool CBUTTON::LinkInLine(CPoint p1, CPoint p2)
{
	return false;
}

bool CBUTTON::oneCornerLink(CPoint p1, CPoint p2)
{
	return false;
}

bool CBUTTON::TwoCornerLink(CPoint p1, CPoint p2)
{
	return false;
}
//按钮的消息响应函数
void CBUTTON::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (game2!=NULL)
	{
		if (firstbutton == NULL)//第一次按按钮时
		{
			firstbutton = this;
		}
		else if (firstbutton == this)
		{
			firstbutton = NULL;//两次点击同一个按钮时，取消选中

		}
		else if (firstbutton->ID != this->ID)
		{
			//第二次点击按钮但是图片不相同的时候
			firstbutton = this;
		}
		else if (firstbutton->ID == this->ID)
		{
			//第二次点击按钮但是图片相同

			////////////////////////////////////////////////////////

			//就在这里用服务器套接字，发送两个button对象，先发送，firstbutton,然后在发送this


			secondbutton = this;
			if (game2->game->judge(MyPoint(firstbutton->location.y, firstbutton->location.x), MyPoint(secondbutton->location.y, secondbutton->location.x)))//此判断为如果两张照片可以连接
			{
				//画线
				game2->OnPaint();
				game2->game->map[CBUTTON::firstbutton->location.x][CBUTTON::firstbutton->location.y] = 0;
				game2->game->map[CBUTTON::secondbutton->location.x][CBUTTON::secondbutton->location.y] = 0;
				firstbutton->ID = 0;
				secondbutton->ID = 0;

				firstbutton->ShowWindow(SW_HIDE);
				secondbutton->ShowWindow(SW_HIDE);
				firstbutton = NULL;
				secondbutton = NULL;
				if (game2->IsFinished())
				{
					char a[10];
					MessageBox(_T("恭喜通关！"), _T("通过！"));
					if (MessageBox(_T("是否保存记录？"), _T("提示"), MB_YESNO) == IDYES)
					{
						string nameid = user->recordAt(0).getInfo();
						int score = user->recordAt(0).getScore();
						string clss = user->getName();
						addOneUserMessage(nameid, score, clss);
					}
				}

			}
			else {
				firstbutton = NULL;
				secondbutton = NULL;
			}




		}
	}else if (game3!=NULL&&game3_net!=NULL)
	{
		if (firstbutton == NULL)//第一次按按钮时
		{
			firstbutton = this;
		}
		else if (firstbutton == this)
		{
			firstbutton = NULL;//两次点击同一个按钮时，取消选中

		}
		else if (firstbutton->ID != this->ID)
		{
			//第二次点击按钮但是图片不相同的时候
			firstbutton = this;
		}
		else if (firstbutton->ID == this->ID)
		{
			//第二次点击按钮但是图片相同

			secondbutton = this;
			if (game3->game_->judge(MyPoint(firstbutton->location.y, firstbutton->location.x), MyPoint(secondbutton->location.y, secondbutton->location.x)))//此判断为如果两张照片可以连接
			{
				//画线
				game3->OnPaint();
				game3->game_->map[CBUTTON::firstbutton->location.x][CBUTTON::firstbutton->location.y] = 0;
				game3->game_->map[CBUTTON::secondbutton->location.x][CBUTTON::secondbutton->location.y] = 0;
				firstbutton->ID = 0;
				secondbutton->ID = 0;

				firstbutton->ShowWindow(SW_HIDE);
				secondbutton->ShowWindow(SW_HIDE);
				firstbutton = NULL;
				secondbutton = NULL;
				if (game3->IsFinished())
				{
					MessageBox(_T("恭喜通关！"), _T("通过！"));
					if (MessageBox(_T("是否保存记录？"), _T("提示"), MB_YESNO) == IDYES)
					{
						//void addScore(string name, int scores, string data, int clss)
					}
				}

			}
			else {
				firstbutton = NULL;
				secondbutton = NULL;
			}

			//test
			for (int i = 0; i < game3->game_->path->getSize(); i++) {
				cout << "(" << game3->game_->path->get(i).x << ", " << game3->game_->path->get(i).y << ") ->";
			}
			cout << endl << endl;


		}
	}
	
	
}

BEGIN_MESSAGE_MAP(CBUTTON, CButton)
	ON_WM_LBUTTONDOWN()//按钮的消息响应函数
END_MESSAGE_MAP()



// CBUTTON 消息处理程序


