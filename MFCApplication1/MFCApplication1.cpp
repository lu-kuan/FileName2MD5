
// MFCApplication1.cpp : ����Ӧ�ó��������Ϊ��
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


// CMFCApplication1App ����

CMFCApplication1App::CMFCApplication1App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMFCApplication1App ����

CMFCApplication1App theApp;


// CMFCApplication1App ��ʼ��

BOOL CMFCApplication1App::InitInstance()
{
	HKEY Key;
	CString sKeyPath;
	sKeyPath = "Software\\mingrisoft";
	if (RegOpenKey(HKEY_CURRENT_USER, sKeyPath, &Key) != 0 && RegOpenKey(HKEY_CURRENT_USER, sKeyPath, &Key) != ERROR_SUCCESS)
	{
		//��ע����м�¼�����õĴ���
		::RegCreateKey(HKEY_CURRENT_USER, sKeyPath, &Key);
		::RegSetValueEx(Key, "TryTime", 0, REG_SZ, (unsigned char*)"20", 2);
		::RegCloseKey(Key);
		MessageBox(NULL, "������������20�Σ�", "ϵͳ��ʾ", MB_OK | MB_ICONEXCLAMATION);
	}
	else //�Ѿ�����ע����Ϣ
	{
		CString sTryTime;
		int nTryTime;
		LPBYTE Data = new BYTE[80];
		DWORD TYPE = REG_SZ;
		DWORD cbData = 80;
		//ȡ���Ѽ��ص�����
		::RegQueryValueEx(Key, "TryTime", 0, &TYPE, Data, &cbData);
		sTryTime.Format("%s", Data);
		nTryTime = atoi(sTryTime);
		if (nTryTime<1)
		{
			MessageBox(NULL, "����������ô����ѹ���ֻ��ע�����������ʹ�ã�", "ϵͳ��ʾ", MB_OK | MB_ICONSTOP);

			return FALSE;
		}
		nTryTime--;
		sTryTime.Format("%d", nTryTime);
		::RegSetValueEx(Key, "TryTime", 0, REG_SZ, (unsigned char*)sTryTime.GetBuffer(sTryTime.GetLength()), 2);
		::RegCloseKey(Key);
		MessageBox(NULL, "������������" + sTryTime + "�Σ�", "ϵͳ��ʾ", MB_OK | MB_ICONEXCLAMATION);

	}
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()��  ���򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ���Windows Native���Ӿ����������Ա��� MFC �ؼ�����������
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CMFCApplication1Dlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "����: �Ի��򴴽�ʧ�ܣ�Ӧ�ó���������ֹ��\n");
		TRACE(traceAppMsg, 0, "����: ������ڶԻ�����ʹ�� MFC �ؼ������޷� #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS��\n");
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

