// LOCAL_LIST.cpp: 实现文件
//

#include "stdafx.h"
#include "LOCAL_LIST.h"
#include <vector>
#include "Client.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include "CBUTTON.h"

using namespace std;


void getFile() {
	sendms("-");
}
// LOCAL_LIST 对话框

IMPLEMENT_DYNAMIC(LOCAL_LIST, CDialogEx)

LOCAL_LIST::LOCAL_LIST(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOCAL_LIST, pParent)
{

}

LOCAL_LIST::~LOCAL_LIST()
{
}

int getAtMAX(vector<int>* vi) {
	int sc = 0;
	int pos = 0;
	for (size_t i = 0; i < vi->size(); i++)
	{
		if (sc < vi->at(i))
		{
			sc = vi->at(i);
			pos = i;
		}
	}

	//cout << "max score" << sc << endl;
	//tihuan
	vector<int>::iterator vit;
	vit = find(vi->begin(), vi->end(), sc);
	*vit = 0;     //newValue是你要赋的新值，把vier看成指针就好
	return pos;
}

int SplitString(const CString str, char split, CStringArray &strArray)
{
	strArray.RemoveAll();
	CString strTemp = str;
	int iIndex = 0;
	while (1)
	{
		iIndex = strTemp.Find(split);
		if(iIndex >= 0)
		{
			strArray.Add(strTemp.Left(iIndex));
			strTemp = strTemp.Right(strTemp.GetLength()-iIndex-1);
		}
		else
		{
			break;
		}
	}
	strArray.Add(strTemp);

	return strArray.GetSize();
}

CString getScore(CString str) {
	CStringArray strArray;
	
	int d = SplitString(str, '!', strArray);
	//cout <<"有str个数："<< d << endl;
	return strArray.GetAt(2);
}

vector<int> getScoreArray(CStringArray* csa) {
	vector<int> scos;
	int sco = 0;
	string str;
	CString strtemp;
	//cout << "截取字符串" << endl;
	for (size_t i = 0; i < csa->GetSize(); i++)
	{
		strtemp = getScore(csa->GetAt(i));//截取字符串
		//AfxMessageBox(strtemp);
		CString st = strtemp.Mid(7, strtemp.GetLength() - 7);
		sco = _ttoi(st);
		//cout << i << "->" << sco << endl;

		scos.push_back(sco);
	}
	
	//ok
	return scos;
}

void sortOnScores(CStringArray* csa) {
	CStringArray temp;
	int pos = 0;
	int len = csa->GetSize();
	vector<int> scos = getScoreArray(csa);
	//ok
	//cout << csa->GetSize() << endl;
	for (size_t i = 0; i < len; i++)
	{
		pos = getAtMAX(&scos);
		//cout <<"位置"<<i<<"---"<< pos << endl;
		temp.Add(csa->GetAt(pos));
	}

	csa->Copy(temp);
	//string str;
	//for (size_t i = 0; i < csa->GetSize(); i++)
	//{
	//	str = CT2A(csa->GetAt(i));
	//	cout << "str" << "->" << str.data() << endl;
	//}

}

//排行榜具体文件操作以及读写
//直接使用变量user
void LOCAL_LIST::setText() {
	//调用服务器上排行榜信息
	getFile();


	//char*到string出错
	CEdit* pBoxOne;
	pBoxOne = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString strFileName = _T("localphb.txt");
	CString strValue = _T("");
	CStringArray cstrArray;
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
		cstrArray.Add(strValue);
	}
	file.Close();

	//按分数排序
	sortOnScores(&cstrArray);
	/*for (size_t i = 0; i < cstrArray.GetSize(); i++)
	{
		AfxMessageBox(cstrArray.GetAt(i));
	}*/
	CString strshow = _T("");
	for (int i = 0; i < cstrArray.GetSize(); i++) {
		strshow += cstrArray.GetAt(i);
		strshow += _T("\r\n");
	}
	strshow.Replace(_T("!!"), _T("\t"));//替换文件中字符串

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
