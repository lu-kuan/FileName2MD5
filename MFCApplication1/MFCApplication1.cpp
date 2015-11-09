
// MFCApplication1.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1App

BEGIN_MESSAGE_MAP(CMFCApplication1App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCApplication1App 构造

CMFCApplication1App::CMFCApplication1App()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMFCApplication1App 对象

CMFCApplication1App theApp;


// CMFCApplication1App 初始化

BOOL CMFCApplication1App::InitInstance()
{
	HKEY Key;
	CString sKeyPath;
	sKeyPath = "Software\\mingrisoft";
	if (RegOpenKey(HKEY_CURRENT_USER, sKeyPath, &Key) != 0 && RegOpenKey(HKEY_CURRENT_USER, sKeyPath, &Key) != ERROR_SUCCESS)
	{
		//在注册表中记录已试用的次数
		::RegCreateKey(HKEY_CURRENT_USER, sKeyPath, &Key);
		::RegSetValueEx(Key, "TryTime", 0, REG_SZ, (unsigned char*)"20", 2);
		::RegCloseKey(Key);
		MessageBox(NULL, "您还可以试用20次！", "系统提示", MB_OK | MB_ICONEXCLAMATION);
	}
	else //已经存在注册信息
	{
		CString sTryTime;
		int nTryTime;
		LPBYTE Data = new BYTE[80];
		DWORD TYPE = REG_SZ;
		DWORD cbData = 80;
		//取出已记载的数量
		::RegQueryValueEx(Key, "TryTime", 0, &TYPE, Data, &cbData);
		sTryTime.Format("%s", Data);
		nTryTime = atoi(sTryTime);
		if (nTryTime<1)
		{
			MessageBox(NULL, "您的最大试用次数已过，只有注册后才允许继续使用！", "系统提示", MB_OK | MB_ICONSTOP);

			return FALSE;
		}
		nTryTime--;
		sTryTime.Format("%d", nTryTime);
		::RegSetValueEx(Key, "TryTime", 0, REG_SZ, (unsigned char*)sTryTime.GetBuffer(sTryTime.GetLength()), 2);
		::RegCloseKey(Key);
		MessageBox(NULL, "您还可以试用" + sTryTime + "次！", "系统提示", MB_OK | MB_ICONEXCLAMATION);

	}
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CMFCApplication1Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败，应用程序将意外终止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您在对话框上使用 MFC 控件，则无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

