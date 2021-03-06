#pragma once
#include "stdafx.h"
#include "afxdialogex.h"
#include "PLAY.h"
#include <iostream>
#include "afxwin.h"
#include "Net_fighting.h"

// CBUTTON
void addOneUserMessage(string name, int scores, string clss);

class CBUTTON : public CButton
{
	DECLARE_DYNAMIC(CBUTTON)

public:
	CBUTTON();
	virtual ~CBUTTON();
	CBUTTON(int type, CPoint point);
public:
	int ID;//按钮的类型，即按钮图片上的类型
	CPoint location;//按钮对应在map中的位置

public:
	static CBUTTON * firstbutton;//第一次点中的按钮
	static CBUTTON * secondbutton;//第二次点中的按钮

									 //两个拐点

	static CPoint conner1;
	static CPoint conner2;


	static PLAY* game2;//游戏窗口
	static Net_fighting* game3;//游戏窗口
	static Net_fighting* game3_net;//游戏窗口网络

	bool LinkInLine(CPoint p1, CPoint p2);//一条直线消去
	bool oneCornerLink(CPoint p1, CPoint p2);//两条直线消去
	bool TwoCornerLink(CPoint p1, CPoint p2);//三条支线消去

	afx_msg  void OnLButtonDown(UINT nFlags, CPoint point); // 点击按钮响应函数
protected:
	DECLARE_MESSAGE_MAP()
};


