// CBUTTON.cpp: 实现文件
//

#include "stdafx.h"
#include "lianliankan.h"
#include "CBUTTON.h"


// CBUTTON

IMPLEMENT_DYNAMIC(CBUTTON, CButton)

CBUTTON::CBUTTON()
{

}

CBUTTON::~CBUTTON()
{
}

CBUTTON::CBUTTON(int type, CPoint point)
{
	ID = type;
	location = point;
}

BEGIN_MESSAGE_MAP(CBUTTON, CButton)
END_MESSAGE_MAP()



// CBUTTON 消息处理程序


