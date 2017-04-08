// BDMFCSerial.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "BDMFCSerial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;
using namespace PointingDevice;
using namespace std;
gcroot<PointingDevice::GoodsDevice^> m_goodsDevice = gcnew PointingDevice::GoodsDevice("GOODS2", "COM4", "9600");
int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // ��ʼ�� MFC ����ʧ��ʱ��ʾ����
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: ���Ĵ�������Է���������Ҫ
            wprintf(L"����: MFC ��ʼ��ʧ��\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
        }
    }
    else
    {
        // TODO: ���Ĵ�������Է���������Ҫ
        wprintf(L"����: GetModuleHandle ʧ��\n");
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
