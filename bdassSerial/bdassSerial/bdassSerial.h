// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� BDASSSERIAL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// BDASSSERIAL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�

#ifdef BDASSSERIAL_EXPORTS
#define BDASSSERIAL_API __declspec(dllexport)

#else
#define BDASSSERIAL_API __declspec(dllimport)
#endif

#define WINAPI __stdcall

// �����Ǵ� bdassSerial.dll ������

//������λ
	BDASSSERIAL_API int goodsReset();

//������Ժ��ú����ҵ��
	BDASSSERIAL_API int CoorDinateCaseGood(int YLine, int XLine);

//�������ǰ�õ��

	BDASSSERIAL_API  int PreposeMotorCase(int ZLine);

//����ָ��
	BDASSSERIAL_API int goodsSellCase(int ZLine, int YLine, int XLine);

//���ú����ҹ�λ
	BDASSSERIAL_API  int CoorDinateHome(int YLine, int XLine);

//ǰ�õ����λ
	BDASSSERIAL_API  int PreposeMotorHome(int ZLine);




