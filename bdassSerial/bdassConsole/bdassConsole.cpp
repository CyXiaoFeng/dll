// bdassConsole.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "bdassConsole.h"
#include <windows.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include<iostream>
// 唯一的应用程序对象

using namespace std;

HINSTANCE hInstLibrary;

char** str_split(char* a_str, const char a_delim)
{
	char** result = 0;
	size_t count = 0;
	char* tmp = a_str;
	char* last_comma = 0;
	char delim[2];
	delim[0] = a_delim;
	delim[1] = 0;

	/* Count how many elements will be extracted. */
	while (*tmp)
	{
		if (a_delim == *tmp)
		{
			count++;
			last_comma = tmp;
		}
		tmp++;
	}

	/* Add space for trailing token. */
	count += last_comma < (a_str + strlen(a_str) - 1);

	/* Add space for terminating null string so caller
	knows where the list of returned strings ends. */
	count++;

	result = (char**)malloc(sizeof(char*) * count);

	if (result)
	{
		size_t idx = 0;
		char* token = strtok(a_str, delim);

		while (token)
		{
			assert(idx < count);
			*(result + idx++) = strdup(token);
			token = strtok(0, delim);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

int main(int argc, char *argv[])
{
	int nRetCode = 0;
	try {
	int cnt = 0;

	cout << "\nCommand-line arguments:\n";
	for (cnt =0 ;cnt < argc; cnt++)
		cout << "  argv[" << cnt << "]   "
		<< argv[cnt] << "\n";
	
	hInstLibrary  = LoadLibrary(L"BDMFCSerial.dll");
	if (argc <= 1) {
		printf("the parameter occor error\n");
		return -1;
	}

    if (hInstLibrary)
    {
	
		switch (atoi(argv[1])) {
		case IS_goodsReset:
			{
				goodsReset goodsreset = (goodsReset)GetProcAddress(hInstLibrary, "goodsReset");
				if (NULL != goodsreset) {
					nRetCode = goodsreset();
					printf("goodsReset method-> %d\n", nRetCode);
				}
				else
					printf("not found goodsReset method\n");
			}
			
			break;

		case IS_CoorDinateCaseGood:
			{
			cout << "the parameter->" << argv[2] << "\n";
			char** tokens;
			tokens = str_split(argv[2], ':');
			int len = sizeof(tokens) / sizeof(*tokens);
			printf("len->%d\n", len);
			int x=0, y=0;
			if (tokens) {
				x = atoi(*(tokens));
				free(*(tokens));
				y = atoi(*(tokens+1));
				free(*(tokens+1));
			}
			free(tokens);
			printf("x=%d,y=%d\n", x, y);
			CoorDinateCaseGood coorDinateCaseGood = (CoorDinateCaseGood)GetProcAddress(hInstLibrary, "CoorDinateCaseGood");
				if (NULL != coorDinateCaseGood) {
					nRetCode = coorDinateCaseGood(x, y);
					printf("CoorDinateCaseGood method-> %d\n", nRetCode);
				}
				else
					printf("not found CoorDinateCaseGood method\n");
			}

			break;

		case IS_PreposeMotorCase:
			{
				cout << "the parameter->" << argv[2] << "\n";
				int x = 0;
				x = atoi(argv[2]);
				printf("x=%d\n", x);
				PreposeMotorCase preposeMotorCase = (PreposeMotorCase)GetProcAddress(hInstLibrary, "PreposeMotorCase");
				if (NULL != preposeMotorCase) {
					nRetCode = preposeMotorCase(x);
					printf("PreposeMotorCase method-> %d\n", nRetCode);
				}
				else
					printf("not found PreposeMotorCase method\n");
			}

			break;

		case IS_goodsSellCase:
			{
				cout << "the parameter->" << argv[2] << "\n";
				char** tokens;
				tokens = str_split(argv[2], ':');
				int z=0, x = 0, y = 0;
				if (tokens) {
					z = atoi(*(tokens));
					free(*(tokens));
					x = atoi(*(tokens + 1));
					free(*(tokens + 1));
					y = atoi(*(tokens + 2));
					free(*(tokens + 2));
				}
				free(tokens);
				printf("z=%d,x=%d,y=%d\n", z, x, y);
				goodsSellCase goodssellCase = (goodsSellCase)GetProcAddress(hInstLibrary, "goodsSellCase");
				if (NULL != goodssellCase) {
					nRetCode = goodssellCase(z, x, y);
					printf("goodsSellCase method-> %d\n", nRetCode);
				}
				else
					printf("not found goodsSellCase method\n");
			}
			break;

		case IS_CoorDinateHome:
			{
				cout << "the parameter->" << argv[2] << "\n";
				char** tokens;
				tokens = str_split(argv[2], ':');
				int x = 0, y = 0;
				if (tokens) {
					x = atoi(*(tokens));
					free(*(tokens));
					y = atoi(*(tokens + 1));
					free(*(tokens + 1));
				}
				free(tokens);
				printf("x=%d,y=%d\n", x, y);
				CoorDinateHome coorDinateHome = (CoorDinateHome)GetProcAddress(hInstLibrary, "CoorDinateHome");
				if (NULL != coorDinateHome) {
					nRetCode = coorDinateHome(x, y);
					printf("CoorDinateHome method-> %d\n", nRetCode);
				}
				else
					printf("not found CoorDinateHome method\n");
			}

			break;

		case IS_PreposeMotorHome:
		{
			cout << "the parameter->" << argv[2] << "\n";
			int x = 0;
			x = atoi(argv[2]);
			printf("x=%d\n", x);
			PreposeMotorHome preposeMotorHome = (PreposeMotorHome)GetProcAddress(hInstLibrary, "PreposeMotorHome");
			if (NULL != preposeMotorHome) {
				nRetCode = preposeMotorHome(x);
				printf("PreposeMotorHome method-> %d\n", nRetCode);
			}
			else
				printf("not found PreposeMotorHome method\n");
		}
			break;

		default:
			printf("input method serial error");
		}
	/*
			if (atoi(argv[1]) == 0) {
				CoorDinateCaseGood coorDinateCaseGood = (CoorDinateCaseGood)GetProcAddress(hInstLibrary, "CoorDinateCaseGood");
				if (NULL != coorDinateCaseGood) {

					printf("CoorDinateCaseGood method-> %d\n", coorDinateCaseGood(1, 2));
				}

			}
			*/
		
		
    }
    else
    {
        // TODO: 更改错误代码以符合您的需要
		printf("错误: GetModuleHandle 失败\n");
        nRetCode = 1;
    }
	system("PAUSE");
	}
	catch (...) {
		printf("错误: 代码抛出异常 失败\n");
	}
    return nRetCode;
}
