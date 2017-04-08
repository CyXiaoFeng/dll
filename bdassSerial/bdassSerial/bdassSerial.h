// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 BDASSSERIAL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// BDASSSERIAL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。

#ifdef BDASSSERIAL_EXPORTS
#define BDASSSERIAL_API __declspec(dllexport)

#else
#define BDASSSERIAL_API __declspec(dllimport)
#endif

#define WINAPI __stdcall

// 此类是从 bdassSerial.dll 导出的

//货道复位
	BDASSSERIAL_API int goodsReset();

//电机测试后置和左右电机
	BDASSSERIAL_API int CoorDinateCaseGood(int YLine, int XLine);

//电机测试前置电机

	BDASSSERIAL_API  int PreposeMotorCase(int ZLine);

//出货指令
	BDASSSERIAL_API int goodsSellCase(int ZLine, int YLine, int XLine);

//后置和左右归位
	BDASSSERIAL_API  int CoorDinateHome(int YLine, int XLine);

//前置电机归位
	BDASSSERIAL_API  int PreposeMotorHome(int ZLine);




