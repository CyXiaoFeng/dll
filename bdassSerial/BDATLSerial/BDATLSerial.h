// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BDATLSERIAL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BDATLSERIAL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef _cplusplus
extern "C" {
#endif
#ifdef BDATLSERIAL_EXPORTS
#define  BDATLSERIAL_API  _declspec(dllexport)
#else
#define BDATLSERIAL_API _declspec(dllimport)
#endif

#define EXPORTFUN extern "C" _declspec(dllexport)
// �����Ǵ� BDATLSerial.dll ������
class BDATLSERIAL_API CBDATLSerial {
public:
	CBDATLSerial(void);
	// TODO:  �ڴ�������ķ�����
};

extern BDATLSERIAL_API int nBDATLSerial;

BDATLSERIAL_API int fnBDATLSerial(void);

//������λ
EXPORTFUN int goodsReset();

//������Ժ��ú����ҵ��
EXPORTFUN int CoorDinateCaseGood(int, int);

//�������ǰ�õ��

EXPORTFUN  int PreposeMotorCase(int ZLine);

//����ָ��
EXPORTFUN int goodsSellCase(int, int, int);

//���ú����ҹ�λ
EXPORTFUN  int CoorDinateHome(int, int);

//ǰ�õ����λ
EXPORTFUN  int PreposeMotorHome(int);

//����״̬
/*
14:�����ɹ�
19 û�и���
20 û�иò�
21����ʾ����æµ
22:��Ҫ�˹�����(�������)
25:����ʧ�� 26������������
27�����ﱻȡ��(�����ѵ�������û�й�λ)
29:����ʧ��,���ܽ����´γ���
*/
EXPORTFUN  int goodsStatus();

EXPORTFUN  int add(int, int);
#ifdef _cplusplus
}
#endif
