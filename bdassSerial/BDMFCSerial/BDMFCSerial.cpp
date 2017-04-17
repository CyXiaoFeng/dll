// BDMFCSerial.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "BDMFCSerial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;
using namespace PointingDevice;
using namespace std;
System::String^ getConfig(TCHAR *second) {
	TCHAR lpPath[MAX_PATH] = _T(".\\config.ini");
	TCHAR Value[10];
	GetPrivateProfileString(TEXT("Section"), second, TEXT("NULL"), Value, 10, lpPath);
	_tprintf(_T("Value=%s\n"), Value);
	return gcnew System::String(Value);
}
//gcroot<PointingDevice::GoodsDevice^> m_goodsDevice = gcnew PointingDevice::GoodsDevice("GOODS2","COM4","9600");
gcroot<PointingDevice::GoodsDevice^> m_goodsDevice = gcnew PointingDevice::GoodsDevice(getConfig(TEXT("TYPE"))/*"GOODS2"*/,
	getConfig(TEXT("COM")), getConfig(TEXT("RATE")));
int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // 初始化 MFC 并在失败时显示错误
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 更改错误代码以符合您的需要
            wprintf(L"错误: MFC 初始化失败\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 在此处为应用程序的行为编写代码。
        }
    }
    else
    {
        // TODO: 更改错误代码以符合您的需要
        wprintf(L"错误: GetModuleHandle 失败\n");
        nRetCode = 1;
    }

    return nRetCode;
}

BDMFCSERIAL_API int goodsReset()
{
	return m_goodsDevice->goodsReset();
}

BDMFCSERIAL_API int CoorDinateCaseGood(int YLine, int XLine)
{
	return m_goodsDevice->CoorDinateCaseGood(YLine, XLine);
}

BDMFCSERIAL_API int PreposeMotorCase(int ZLine)
{
	return m_goodsDevice->PreposeMotorCase(ZLine);
}

BDMFCSERIAL_API int goodsSellCase(int ZLine, int YLine, int XLine)
{
	return m_goodsDevice->goodsSellCase(ZLine, YLine, XLine);

}

BDMFCSERIAL_API int CoorDinateHome(int YLine, int XLine)
{
	return m_goodsDevice->CoorDinateHome(YLine, XLine);
}

BDMFCSERIAL_API int PreposeMotorHome(int ZLine)
{
	return m_goodsDevice->PreposeMotorHome(ZLine);
}
