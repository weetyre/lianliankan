// CBUTTON.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "CBUTTON.h"
#include "Game.h"


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
	if (firstbutton==NULL)//第一次按按钮时
	{
		firstbutton = this;
	}else if (firstbutton==this)
	{
		firstbutton = NULL;//两次点击同一个按钮时，取消选中

	}else if (firstbutton->ID!=this->ID)
	{
		//第二次点击按钮但是图片不相同的时候
		firstbutton = NULL;
	}else if (firstbutton->ID==this->ID)
	{
		//第二次点击按钮但是图片相同
		
	     secondbutton = this;
		if (game2->game->judge(MyPoint(firstbutton->location.x,firstbutton->location.y ),MyPoint(secondbutton->location.x,secondbutton->location.y)))//此判断为如果两张照片可以连接
		{
			//画线

			game2->OnPaint();
		
			//隐藏按钮
			firstbutton->ShowWindow(SW_HIDE);
			secondbutton->ShowWindow(SW_HIDE);
			game2->game->map[firstbutton->location.y][firstbutton->location.x] = 0;
		   	game2->game->map[secondbutton->location.y][secondbutton->location.x] = 0;
			firstbutton->ID = 0;
			secondbutton->ID = 0;
			firstbutton = NULL;
			secondbutton = NULL;
		}
		else {
			firstbutton = NULL;
			secondbutton =NULL;
		}

	}
}

BEGIN_MESSAGE_MAP(CBUTTON, CButton)
	ON_WM_LBUTTONDOWN()//按钮的消息响应函数
END_MESSAGE_MAP()



// CBUTTON 消息处理程序


