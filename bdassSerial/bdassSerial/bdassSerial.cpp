// bdassSerial.cpp : 定义 DLL 应用程序的导出函数。
//
#include "stdafx.h"
#include <vcclr.h>  
#include "bdassSerial.h"
#include <stdio.h>
#include <stdlib.h>
using namespace PointingDevice;
using namespace std;
// 唯一的应用程序对象
gcroot<GoodsDevice^> m_goodsDevice = gcnew GoodsDevice("GOODS2", "COM4", "9600");

BDASSSERIAL_API int goodsReset()
{
	return m_goodsDevice->goodsReset();
}

BDASSSERIAL_API int CoorDinateCaseGood(int YLine, int XLine)
{
	return m_goodsDevice->CoorDinateCaseGood(YLine, XLine);
}

BDASSSERIAL_API int PreposeMotorCase(int ZLine)
{
	return m_goodsDevice->PreposeMotorCase(ZLine);
}

BDASSSERIAL_API int goodsSellCase(int ZLine, int YLine, int XLine)
{
		return m_goodsDevice->goodsSellCase(ZLine, YLine, XLine);
		
}

BDASSSERIAL_API int CoorDinateHome(int YLine, int XLine)
{
	return m_goodsDevice->CoorDinateHome(YLine, XLine);
}

BDASSSERIAL_API int PreposeMotorHome(int ZLine)
{
	return m_goodsDevice->PreposeMotorHome(ZLine);
}


