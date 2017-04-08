// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 BDMFCSERIAL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// BDMFCSERIAL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef __cplusplus    // If used by C++ code,   
extern "C" {          // we need to export the C interface  
#endif  
#ifdef BDMFCSERIAL_EXPORTS
#define BDMFCSERIAL_API __declspec(dllexport)
#else
#define BDMFCSERIAL_API __declspec(dllimport)
#endif

// 此类是从 BDMFCSerial.dll 导出的
class BDMFCSERIAL_API CBDMFCSerial {
public:
	CBDMFCSerial(void);
	// TODO:  在此添加您的方法。
};

extern BDMFCSERIAL_API int nBDMFCSerial;

BDMFCSERIAL_API int fnBDMFCSerial(void);


#define WINAPI __stdcall

// 此类是从 bdassSerial.dll 导出的

//货道复位
BDMFCSERIAL_API int goodsReset();

//电机测试后置和左右电机
BDMFCSERIAL_API int CoorDinateCaseGood(int , int );

//电机测试前置电机

BDMFCSERIAL_API  int PreposeMotorCase(int ZLine);

//出货指令
BDMFCSERIAL_API int goodsSellCase(int , int , int );

//后置和左右归位
BDMFCSERIAL_API  int CoorDinateHome(int , int );

//前置电机归位
BDMFCSERIAL_API  int PreposeMotorHome(int);

#ifdef __cplusplus  
}
#endif 