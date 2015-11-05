
// MFCApplication1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "md5.h"
//#include "resource.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �Ի���

BEGIN_DHTML_EVENT_MAP(CMFCApplication1Dlg)
	DHTML_EVENT_ONCLICK(_T("ButtonOK"), OnButtonOK)
	DHTML_EVENT_ONCLICK(_T("ButtonCancel"), OnButtonCancel)
END_DHTML_EVENT_MAP()


CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(IDD_MFCAPPLICATION1_DIALOG, IDR_HTML_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, listbox);
	DDX_Control(pDX, IDC_LIST2, listbox2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFCApplication1Dlg::OnLbnSelchangeList1)
	ON_WM_DROPFILES()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST2, &CMFCApplication1Dlg::OnLbnSelchangeList2)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CMFCApplication1Dlg ��Ϣ��������

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	listbox.SetHorizontalExtent(500);
	listbox2.SetHorizontalExtent(200);
	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CMFCApplication1Dlg::OnButtonOK(IHTMLElement* /*pElement*/)
{
	OnOK();
	return S_OK;
}

HRESULT CMFCApplication1Dlg::OnButtonCancel(IHTMLElement* /*pElement*/)
{
	OnCancel();
	return S_OK;
}


void CMFCApplication1Dlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
}


void CMFCApplication1Dlg::OnDropFiles(HDROP hDropInfo)
{
	 // TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	char szFilePathName[_MAX_PATH + 1] = { 0 };

	//�õ��ļ�����      
	UINT nNumOfFiles = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);

	for (UINT nIndex = 0; nIndex< nNumOfFiles; ++nIndex) {
		//���õ��ļ���   
		DragQueryFile(hDropInfo, nIndex, (LPTSTR)szFilePathName, _MAX_PATH);

		CString str2 = (_tcsrchr(szFilePathName, '\\'));
		str2.Remove('\\'); //��ȡ�õ��ļ�ȫ������abc.avi

		CString str4 = ",";
		CString str8;
		//CString str5 = "�ֽ�";
		WIN32_FILE_ATTRIBUTE_DATA FindFileData;
		GetFileAttributesEx(szFilePathName, GetFileExInfoStandard, &FindFileData);
		//ͨ��GetFileAttributesExȡ���ļ��ֽ���
		ULONGLONG FileSize = (FindFileData.nFileSizeHigh * 4294967296) + FindFileData.nFileSizeLow;
		str8.Format("%I64u", FileSize);
		str2 =str2 + str4 +str8;//�ļ�ȫ��+��+�ֽ��� readme.txt,137
		CString strmd5;
		MD5 md5;                 //����MD5����
		md5.update(str2.GetBuffer());          //��Ϊupdate����ֻ����string���ͣ�����ʹ��getbuffer()����ת��CStringΪstring
		//md5.update(ifstream("E:\TDDownload\jre-8u66-windows-x64.exe)"));
		strmd5 = md5.toString().c_str() + str4;     //toString()������ü����ַ�����c_str();��������ת����CString����
	 	listbox.AddString(str2);
		listbox2.AddString(strmd5); //32λСдmd5 ���ļ���.��չ��,�ֽ�����
		md5.reset();//ÿ�μ��������

	}

	DragFinish(hDropInfo);
	CDHtmlDialog::OnDropFiles(hDropInfo);
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	//CFile f("�ı��ĵ�.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
//	CString s;
	//GetDlgItemText(IDC_LIST1, s);
//	MessageBox(listbox.GetText);
	
	//return;
	// write it to file
 CStdioFile file;
	//CFile f("aaa.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);

//	f.SeekToEnd();
	//f.Write((LPCTSTR)s, s.GetLength());
//	f.Close();
	if (file.Open("info.txt", CFile::modeWrite | CFile::modeCreate))
	{
		int total = (int)listbox2.GetCount();

		for (int ii = 0; ii< total; ii++)
		{
			char str[MAX_PATH] = { 0 };
			listbox2.GetText(ii, str);
			file.WriteString(str);
		}
	}

}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	listbox.ResetContent();
	listbox2.ResetContent();
}


void CMFCApplication1Dlg::OnLbnSelchangeList2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
}


void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDHtmlDialog::OnSize(nType, cx, cy);
	CWnd* pWnd = GetDlgItem(IDC_LIST1);
	if (pWnd->GetSafeHwnd())
		pWnd->MoveWindow(15, 15, 240, cy - 30);
	CWnd* pWnd2 = GetDlgItem(IDC_LIST2);
	if (pWnd2->GetSafeHwnd())
		pWnd2->MoveWindow(250, 15, 240, cy - 30);
//	CWnd* pWnd3 = GetDlgItem(IDC_BUTTON2);
//	if (pWnd3->GetSafeHwnd())
////		pWnd3->MoveWindow(cx - 50, cy-200, cx - 10, cy - 100);

	// TODO: �ڴ˴�������Ϣ�����������
	//CWnd *pWnd3;
//	pWnd3 = GetDlgItem(IDC_BUTTON2);    //��ȡ�ؼ�ָ�룬IDC_BUTTON1Ϊ�ؼ�ID��  
	//pWnd3->SetWindowPos(NULL, 50, 80, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
}