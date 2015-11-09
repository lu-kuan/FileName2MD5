
// MFCApplication1Dlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMFCApplication1Dlg 对话框

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
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDHtmlDialog::OnInitDialog();
	listbox.SetHorizontalExtent(500);
	listbox2.SetHorizontalExtent(200);
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
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
		CDHtmlDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	for (int i = listbox.GetCount() - 1;i >= 0;i--)
	{
		if (listbox.GetSel(i))
		{

			listbox2.SetCurSel(i);
		}
	}
}


void CMFCApplication1Dlg::OnDropFiles(HDROP hDropInfo)
{
	 // TODO: 在此添加消息处理程序代码和/或调用默认值
	char szFilePathName[_MAX_PATH + 1] = { 0 };

	//得到文件个数      
	UINT nNumOfFiles = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);

	for (UINT nIndex = 0; nIndex< nNumOfFiles; ++nIndex) {
		//　得到文件名   
		DragQueryFile(hDropInfo, nIndex, (LPTSTR)szFilePathName, _MAX_PATH);

		CString str2 = (_tcsrchr(szFilePathName, '\\'));
		str2.Remove('\\'); //截取得到文件全名。如abc.avi

		CString str4 = ",";
		CString str8;
		//CString str5 = "字节";
		WIN32_FILE_ATTRIBUTE_DATA FindFileData;
		GetFileAttributesEx(szFilePathName, GetFileExInfoStandard, &FindFileData);
		//通过GetFileAttributesEx取的文件字节数
		ULONGLONG FileSize = (FindFileData.nFileSizeHigh * 4294967296) + FindFileData.nFileSizeLow;
		str8.Format("%I64u", FileSize);
		str2 =str2 + str4 +str8;//文件全名+，+字节数 readme.txt,137
		CString strmd5;
		MD5 md5;                 //定义MD5的类
		md5.update(str2.GetBuffer());          //因为update函数只接收string类型，所以使用getbuffer()函数转换CString为string
		//md5.update(ifstream("E:\TDDownload\jre-8u66-windows-x64.exe)"));
		strmd5 = md5.toString().c_str() + str4;     //toString()函数获得加密字符串，c_str();函数重新转换成CString类型
	 	listbox.AddString(str2);
		listbox2.AddString(strmd5); //32位小写md5 （文件名.拓展名,字节数）
		md5.reset();//每次计算后重置

	}

	DragFinish(hDropInfo);
	CDHtmlDialog::OnDropFiles(hDropInfo);
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{

 CStdioFile file;

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

	HMODULE module = GetModuleHandle(0);
	char pFileName[MAX_PATH];
	GetModuleFileName(module, pFileName, MAX_PATH);

	CString csFullPath(pFileName);
	int nPos = csFullPath.ReverseFind(_T('\\'));
	if (nPos < 0) {
		csFullPath =  CString("");
	}
		
	else {
		csFullPath = csFullPath.Left(nPos);
	}
	file.Close();
	MessageBox("生成成功！生成路径为：" + csFullPath);

}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	listbox.ResetContent();
	listbox2.ResetContent();
}


void CMFCApplication1Dlg::OnLbnSelchangeList2()
{
	for (int i = listbox2.GetCount() - 1;i >= 0;i--)
	{
		if (listbox2.GetSel(i))
		{
			
			listbox.SetCurSel(i);
		}
	}

}


void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDHtmlDialog::OnSize(nType, cx, cy);
	CWnd* pWnd = GetDlgItem(IDC_LIST1);
	if (pWnd->GetSafeHwnd())
		pWnd->MoveWindow(15, 15, 220, cy - 30);
	CWnd* pWnd2 = GetDlgItem(IDC_LIST2);
	if (pWnd2->GetSafeHwnd())
		pWnd2->MoveWindow(220, 15, 210, cy - 30);
//	CWnd* pWnd3 = GetDlgItem(IDC_BUTTON2);
//	if (pWnd3->GetSafeHwnd())
////		pWnd3->MoveWindow(cx - 50, cy-200, cx - 10, cy - 100);

	// TODO: 在此处添加消息处理程序代码
	//CWnd *pWnd3;
//	pWnd3 = GetDlgItem(IDC_BUTTON2);    //获取控件指针，IDC_BUTTON1为控件ID号  
	//pWnd3->SetWindowPos(NULL, 50, 80, 0, 0, SWP_NOZORDER | SWP_NOSIZE);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here   
	// 设置过滤器   
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString szFilePathName;

	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		szFilePathName = fileDlg.GetPathName();
		//SetDlgItemText(IDC_OPEN_EDIT, strFilePath);

		CString str2 = (_tcsrchr(szFilePathName, '\\'));
		str2.Remove('\\'); //截取得到文件全名。如abc.avi

		CString str4 = ",";
		CString str8;
		//CString str5 = "字节";
		WIN32_FILE_ATTRIBUTE_DATA FindFileData;
		GetFileAttributesEx(szFilePathName, GetFileExInfoStandard, &FindFileData);
		//通过GetFileAttributesEx取的文件字节数
		ULONGLONG FileSize = (FindFileData.nFileSizeHigh * 4294967296) + FindFileData.nFileSizeLow;
		str8.Format("%I64u", FileSize);
		str2 = str2 + str4 + str8;//文件全名+，+字节数 readme.txt,137
		CString strmd5;
		MD5 md5;                 //定义MD5的类
		md5.update(str2.GetBuffer());          //因为update函数只接收string类型，所以使用getbuffer()函数转换CString为string
											   //md5.update(ifstream("E:\TDDownload\jre-8u66-windows-x64.exe)"));
		strmd5 = md5.toString().c_str() + str4;     //toString()函数获得加密字符串，c_str();函数重新转换成CString类型
		listbox.AddString(str2);
		listbox2.AddString(strmd5); //32位小写md5 （文件名.拓展名,字节数）
	 
	}
}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	//CString str;
	for (int i = listbox.GetCount() - 1;i >= 0;i--)
	{
		if (listbox.GetSel(i))
		{

			//listbox.GetText(i, str);
			//m_ToBeAdded.AddString(str);
			listbox.DeleteString(i);
			listbox2.DeleteString(i);
		}
	}
	for (int i = listbox2.GetCount() - 1;i >= 0;i--)
	{
		if (listbox2.GetSel(i))
		{

			//listbox.GetText(i, str);
			//m_ToBeAdded.AddString(str);
			listbox.DeleteString(i);
			listbox2.DeleteString(i);
		}
	}
}



void CMFCApplication1Dlg::OnBnClickedButton5()
{
	char szPath[MAX_PATH];     //存放选择的目录路径 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = "请选择需要存放加密文件的目录：";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		CStdioFile file;
		CString info = "\\info.txt";
		info = szPath + info;
		
		
		if (file.Open(info, CFile::modeWrite | CFile::modeCreate))
		{
			int total = (int)listbox2.GetCount();

			for (int ii = 0; ii< total; ii++)
			{
				char str[MAX_PATH] = { 0 };
				listbox2.GetText(ii, str);
				file.WriteString(str);
			}
		}
		file.Close();
		MessageBox("生成成功！生成路径为：" + info);

	}
	else
		AfxMessageBox("无效的目录，请重新选择");
}
