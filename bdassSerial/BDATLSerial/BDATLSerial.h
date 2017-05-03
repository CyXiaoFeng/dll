// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 BDATLSERIAL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// BDATLSERIAL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef _cplusplus
extern "C" {
#endif
#ifdef BDATLSERIAL_EXPORTS
#define  BDATLSERIAL_API  _declspec(dllexport)
#else
#define BDATLSERIAL_API _declspec(dllimport)
#endif

#define EXPORTFUN extern "C" _declspec(dllexport)
// 此类是从 BDATLSerial.dll 导出的
class BDATLSERIAL_API CBDATLSerial {
public:
	CBDATLSerial(void);
	// TODO:  在此添加您的方法。
};

extern BDATLSERIAL_API int nBDATLSerial;

BDATLSERIAL_API int fnBDATLSerial(void);

//货道复位
EXPORTFUN int goodsReset();

//电机测试后置和左右电机
EXPORTFUN int CoorDinateCaseGood(int, int);

//电机测试前置电机

EXPORTFUN  int PreposeMotorCase(int ZLine);

//出货指令
EXPORTFUN int goodsSellCase(int, int, int);

//后置和左右归位
EXPORTFUN  int CoorDinateHome(int, int);

//前置电机归位
EXPORTFUN  int PreposeMotorHome(int);

//货道状态
/*
14:出货成功
19 没有该列
20 没有该层
21：表示货道忙碌
22:需要人工处理(电机故障)
25:出货失败 26：传感器故障
27：货物被取走(货物已掉出但是没有归位)
29:关门失败,不能进行下次出货
*/
EXPORTFUN  int goodsStatus();

EXPORTFUN  int add(int, int);
#ifdef _cplusplus
}
#endif
