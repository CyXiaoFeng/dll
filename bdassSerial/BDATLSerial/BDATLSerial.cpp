// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include<stdio.h>
#include<Psapi.h>
#include<Windows.h>
typedef void(*pFnPtr)(char*);


extern "C"
{
	TCHAR lpPath[MAX_PATH] = _T(".\\config.ini");
	void readConfig() {

		TCHAR lpPath[MAX_PATH] = _T(".\\config.ini");
		/*WritePrivateProfileString(TEXT("Hotel"), TEXT("IP"), TEXT("10.15.40.123"), lpPath);
		WritePrivateProfileString(TEXT("Hotel"), TEXT("Mask"), TEXT("255.255.255.0"), lpPath);
		WritePrivateProfileString(TEXT("Hotel"), TEXT("Gateway"), TEXT("10.15.40.1"), lpPath);
		WritePrivateProfileString(TEXT("Hotel"), TEXT("DNS"), TEXT("211.82.96.1"), lpPath);

		WritePrivateProfileString(TEXT("Match"), TEXT("IP"), TEXT("172.17.29.120"), lpPath);
		WritePrivateProfileString(TEXT("Match"), TEXT("Mask"), TEXT("255.255.255.0"), lpPath);
		WritePrivateProfileString(TEXT("Match"), TEXT("Gateway"), TEXT("172.17.29.1"), lpPath);
		WritePrivateProfileString(TEXT("Match"), TEXT("DNS"), TEXT("0.0.0.0"), lpPath);*/


		TCHAR Ip[16];
		TCHAR Mask[16];
		TCHAR Gateway[16];
		TCHAR DNS[16];

		GetPrivateProfileString(TEXT("Section"), TEXT("TYPE"), TEXT("NULL"), Ip, 100, lpPath);
		/*GetPrivateProfileString(TEXT("Match"), TEXT("Mask"), TEXT("NULL"), Mask, 100, lpPath);
		GetPrivateProfileString(TEXT("Match"), TEXT("Gateway"), TEXT("NULL"), Gateway, 100, lpPath);
		GetPrivateProfileString(TEXT("Match"), TEXT("DNS"), TEXT("NULL"), DNS, 100, lpPath);*/

		_tprintf(_T("IP=%s\n"), Ip);
		/*_tprintf(_T("Mask=%s\n"), Mask);
		_tprintf(_T("Gateway=%s\n"), Gateway);
		_tprintf(_T("DNS=%s\n"), DNS);*/


		/*delete[] lpPath;
		delete[] Ip;
		delete[] Mask;
		delete[] Gateway;
		delete[] DNS;*/
	}
	//主调进程将调用该函数，该函数再调用主调进程的ExeFn函数
	_declspec(dllexport) int fnImportingDLL()
	{
		//readConfig();
		MessageBox(NULL, L"Dll Function called!", L"mydll", MB_OK);
		pFnPtr fn = (pFnPtr)::GetProcAddress(GetModuleHandle(NULL), "ExeFn");
		if (fn)
			fn("梦回吹角连营");
		else
		{
			MessageBox(NULL, L"It Did not work:", L"From DLL", MB_OK);
			return -1;
		}
	}
	System::String^ getConfig(TCHAR *second) {
		TCHAR Value[10];
		GetPrivateProfileString(TEXT("Section"), second, TEXT("NULL"), Value, 10, lpPath);
		return gcnew System::String(Value);
	}
	gcroot<PointingDevice::GoodsDevice^> m_goodsDevice = gcnew PointingDevice::GoodsDevice(getConfig(TEXT("Type")),
		getConfig(TEXT("COM")), getConfig(TEXT("RATE")));
}

//TCHAR   inBuf[80];


//#pragma unmanaged  
//BOOL APIENTRY DllMain(HMODULE hModule,
//	DWORD  ul_reason_for_call,
//	LPVOID lpReserved
//)
//{
//	readConfig();
//	char szName[MAX_PATH];
//	if (lpReserved != 0)
//	{
//		//只允许动态加载，静态加载将提示错误并退出
//		//MessageBox(NULL, "只允许动态加载", "Sorry", MB_OK);
//		return FALSE;
//	}
//	GetModuleBaseName(GetCurrentProcess(), NULL, L"名字", MAX_PATH);//获取当前主进程的base name
//	switch (ul_reason_for_call)
//	{
//	case DLL_PROCESS_ATTACH:
//		//故意将调用进程的名字改为test.exe，该动态链接库将无法加载。
//		if (strcmp(szName, "test.exe") == 0)
//			return FALSE;
//	case DLL_THREAD_ATTACH:
//	case DLL_THREAD_DETACH:
//	case DLL_PROCESS_DETACH:
//		break;
//	}
//	return TRUE;
//}