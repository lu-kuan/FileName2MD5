// listbox.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "listbox.h"
#include "afxdialogex.h"


// listbox �Ի���

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


// listbox ��Ϣ�������
