// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BDMFCSERIAL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BDMFCSERIAL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef __cplusplus    // If used by C++ code,   
extern "C" {          // we need to export the C interface  
#endif  
#ifdef BDMFCSERIAL_EXPORTS
#define BDMFCSERIAL_API __declspec(dllexport)
#else
#define BDMFCSERIAL_API __declspec(dllimport)
#endif

// �����Ǵ� BDMFCSerial.dll ������
class BDMFCSERIAL_API CBDMFCSerial {
public:
	CBDMFCSerial(void);
	// TODO:  �ڴ�������ķ�����
};

extern BDMFCSERIAL_API int nBDMFCSerial;

BDMFCSERIAL_API int fnBDMFCSerial(void);


#define WINAPI __stdcall

// �����Ǵ� bdassSerial.dll ������

//������λ
BDMFCSERIAL_API int goodsReset();

//������Ժ��ú����ҵ��
BDMFCSERIAL_API int CoorDinateCaseGood(int , int );

//�������ǰ�õ��

BDMFCSERIAL_API  int PreposeMotorCase(int ZLine);

//����ָ��
BDMFCSERIAL_API int goodsSellCase(int , int , int );

//���ú����ҹ�λ
BDMFCSERIAL_API  int CoorDinateHome(int , int );

//ǰ�õ����λ
BDMFCSERIAL_API  int PreposeMotorHome(int);

#ifdef __cplusplus  
}
#endif 