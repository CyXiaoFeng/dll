// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BDATLSERIAL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BDATLSERIAL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef __cplusplus    // If used by C++ code,   
extern "C" {          // we need to export the C interface  
#endif  
#ifdef BDATLSERIAL_EXPORTS
#define BDATLSERIAL_API __declspec(dllexport)
#else
#define BDATLSERIAL_API __declspec(dllimport)
#endif

// �����Ǵ� BDATLSerial.dll ������
class BDATLSERIAL_API CBDATLSerial {
public:
	CBDATLSerial(void);
	// TODO:  �ڴ�������ķ�����
};

extern BDATLSERIAL_API int nBDATLSerial;

BDATLSERIAL_API int fnBDATLSerial(void);

//������λ
BDATLSERIAL_API int goodsReset();

//������Ժ��ú����ҵ��
BDATLSERIAL_API int CoorDinateCaseGood(int, int);

//�������ǰ�õ��

BDATLSERIAL_API  int PreposeMotorCase(int ZLine);

//����ָ��
BDATLSERIAL_API int goodsSellCase(int, int, int);

//���ú����ҹ�λ
BDATLSERIAL_API  int CoorDinateHome(int, int);

//ǰ�õ����λ
BDATLSERIAL_API  int PreposeMotorHome(int);

#ifdef __cplusplus  
}
#endif 