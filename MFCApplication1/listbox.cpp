// listbox.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "listbox.h"
#include "afxdialogex.h"


// listbox 对话框

IMPLEMENT_DYNAMIC(listbox, CDialogEx)

listbox::listbox(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{

}

listbox::~listbox()
{
}

void listbox::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(listbox, CDialogEx)
END_MESSAGE_MAP()


// listbox 消息处理程序
