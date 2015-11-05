#pragma once


// listbox 对话框

class listbox : public CDialogEx
{
	DECLARE_DYNAMIC(listbox)

public:
	listbox(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~listbox();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
