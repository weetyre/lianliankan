#pragma once
#include "stdafx.h"
#include "afxdialogex.h"
#include "PLAY.h"
#include <iostream>
#include "afxwin.h"

class CLLKButton : public CButton
{
	DECLARE_DYNAMIC(CLLKButton);

public:

protected:
	DECLARE_MESSAGE_MAP();
public:
	int ID;//按钮的类型，即按钮图片上的类型
	CPoint location;//按钮对应在map中的位置

public:
	CLLKButton(int type, CPoint point);
	static CLLKButton * firstbutton;//第一次点中的按钮
	static CLLKButton * secondbutton;//第二次点中的按钮

	//两个拐点

	static CPoint conner1;
	static CPoint conner2;
	

	static PLAY* game;//游戏窗口

	bool LinkInLine(CPoint p1, CPoint p2);//一条直线消去
	bool oneCornerLink(CPoint p1, CPoint p2);//两条直线消去
	bool TwoCornerLink(CPoint p1, CPoint p2);//三条支线消去

	afx_msg  void OnLButtonDown(UINT nFlags, CPoint point); // 点击按钮响应函数

};

