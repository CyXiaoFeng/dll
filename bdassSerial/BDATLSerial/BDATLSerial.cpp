// BDATLSerial.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "BDATLSerial.h"
using namespace PointingDevice;
using namespace std;

// 这是导出变量的一个示例
BDATLSERIAL_API int nBDATLSerial=0;

// 这是导出函数的一个示例。
BDATLSERIAL_API int fnBDATLSerial(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 BDATLSerial.h
CBDATLSerial::CBDATLSerial()
{
    return;
}

System::String^ getConfig(TCHAR *second) {
	TCHAR lpPath[MAX_PATH] = _T(".\\config.ini");
	TCHAR Value[10];
	GetPrivateProfileString(TEXT("Section"), second, TEXT("NULL"), Value, 10, lpPath);
	_tprintf(_T("Value=%s\n"), Value);
	return gcnew System::String(Value);
}
//gcroot<PointingDevice::GoodsDevice^> m_goodsDevice = gcnew PointingDevice::GoodsDevice("GOODS2","COM4","9600");
//gcroot<PointingDevice::GoodsDevice^> m_goodsDevice = gcnew PointingDevice::GoodsDevice(getConfig(TEXT("TYPE"))/*"GOODS2"*/,
//	getConfig(TEXT("COM")), getConfig(TEXT("RATE")));
//
//int goodsReset()
//{
//	return m_goodsDevice->goodsReset();
//}
//
//int CoorDinateCaseGood(int YLine, int XLine)
//{
//	return m_goodsDevice->CoorDinateCaseGood(YLine, XLine);
//}
//
//int PreposeMotorCase(int ZLine)
//{
//	return m_goodsDevice->PreposeMotorCase(ZLine);
//}
//
//int goodsSellCase(int ZLine, int YLine, int XLine)
//{
//	return m_goodsDevice->goodsSellCase(ZLine, YLine, XLine);
//
//}
//
//int CoorDinateHome(int YLine, int XLine)
//{
//	return m_goodsDevice->CoorDinateHome(YLine, XLine);
//}
//
//int PreposeMotorHome(int ZLine)
//{
//	return m_goodsDevice->PreposeMotorHome(ZLine);
//}
//
//int goodsStatus()
//{
//	return m_goodsDevice->goodsStatus();
//}

int add(int x, int y) {
	
	return x + y;
}