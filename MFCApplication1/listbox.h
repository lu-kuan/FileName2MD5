#pragma once


// listbox �Ի���

class listbox : public CDialogEx
{
	DECLARE_DYNAMIC(listbox)

public:
	listbox(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~listbox();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
