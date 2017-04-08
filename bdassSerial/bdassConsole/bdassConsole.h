#pragma once

#include "resource.h"
#define IS_goodsReset  0
#define IS_CoorDinateCaseGood 1
#define IS_PreposeMotorCase  2
#define IS_goodsSellCase 3
#define	IS_CoorDinateHome 4
#define IS_PreposeMotorHome 5

typedef int(_cdecl * goodsReset)();
typedef int(_cdecl * CoorDinateCaseGood)(int, int);
typedef int(_cdecl * PreposeMotorCase)(int);
typedef int(_cdecl * goodsSellCase)(int, int, int);
typedef int(_cdecl * CoorDinateHome)(int, int);
typedef int(_cdecl * PreposeMotorHome)(int);

