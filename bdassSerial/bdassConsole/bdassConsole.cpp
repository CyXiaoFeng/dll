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
	char *next_token = NULL;
	result = (char**)malloc(sizeof(char*) * count);

	if (result)
	{
		size_t idx = 0;
		char* token = strtok_s(a_str, delim, &next_token);

		while (token)
		{
			assert(idx < count);
			*(result + idx++) = _strdup(token);
			token = strtok_s(0, delim, &next_token);
		}
		assert(idx == count - 1);
		*(result + idx) = 0;
	}

	return result;
}

vector<string> split(const string &s, const string &seperator) {
	vector<string> result;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		//找到字符串中首个不等于分隔符的字母；
		int flag = 0;
		while (i != s.size() && flag == 0) {
			flag = 1;
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[i] == seperator[x]) {
					++i;
					flag = 0;
					break;
				}
		}

		//找到又一个分隔符，将两个分隔符之间的字符串取出；
		flag = 0;
		string_size j = i;
		while (j != s.size() && flag == 0) {
			for (string_size x = 0; x < seperator.size(); ++x)
				if (s[j] == seperator[x]) {
					flag = 1;
					break;
				}
			if (flag == 0)
				++j;
		}
		if (i != j) {
				result.push_back(s.substr(i, j - i));
			i = j;
		}
	}
	return result;
}

int main(int argc, char *argv[])
{
	int nRetCode = 0;
	char* desc = "success";
	try {
		if (argc < 2) {
			desc = "the parameter occor error";
			nRetCode = -1;

		} else {
			//printf("param cnt->%d\n", argc);
			hInstLibrary = LoadLibrary(L"BDMFCSerial.dll");
			if (hInstLibrary)
			{
	
				switch (atoi(argv[1])) {
				case IS_goodsReset:
					{
						goodsReset goodsreset = (goodsReset)GetProcAddress(hInstLibrary, "goodsReset");
						if (NULL != goodsreset) {
							nRetCode = goodsreset();
							desc = "goodsReset method success";
							
						}
						else {
							nRetCode = -2;
							desc = "not found goodsReset method";
						}
							
					}
			
					break;

				case IS_CoorDinateCaseGood:
				{
					//cout << "the parameter->" << argv[2] << "\n";
					if (argc != 3) {
						desc = "the second parameter occor error";
						nRetCode = -1;
						break;
					}
					vector<string> v = split(argv[2], ":");
						if (v.size() != 2) {
							nRetCode = -2;
							desc = "the second parameter split occor error";
							break;
						}

							int x = 0, y = 0;
							x = atoi(v[0].data());
							y = atoi(v[1].data());
							CoorDinateCaseGood coorDinateCaseGood = (CoorDinateCaseGood)GetProcAddress(hInstLibrary, "CoorDinateCaseGood");
							if (NULL != coorDinateCaseGood) {
								nRetCode = coorDinateCaseGood(x, y);
								desc = "CoorDinateCaseGood method success";
							}
							else {
								nRetCode = -2;
								desc = "not found CoorDinateCaseGood method";
							}
						}
						
				
				
					break;

				case IS_PreposeMotorCase:
					{
						//cout << "the parameter->" << argv[2] << "\n";
					if (argc != 3) {
						desc = "the second parameter occor error";
						nRetCode = -1;
						break;
					}
						int x = 0;
						x = atoi(argv[2]);
						//printf("x=%d\n", x);
						PreposeMotorCase preposeMotorCase = (PreposeMotorCase)GetProcAddress(hInstLibrary, "PreposeMotorCase");
						if (NULL != preposeMotorCase) {
							nRetCode = preposeMotorCase(x);
							desc ="PreposeMotorCase method success";
						}
						else {
							nRetCode = -2;
							desc = "not found PreposeMotorCase method";
						}
					}

					break;

				case IS_goodsSellCase:
					{
						//cout << "the parameter->" << argv[2] << "\n";
					if (argc != 3) {
						desc = "the second parameter occor error";
						nRetCode = -1;
						break;
					}
				
					vector<string> v = split(argv[2], ":");
					if (v.size() != 3) {
						nRetCode = -2;
						desc = "the second parameter split occor error";
						break;
					}
					int z = 0, x = 0, y = 0;
					z = atoi(v[0].data());
					x = atoi(v[1].data());
					y = atoi(v[2].data());
						//printf("z=%d,x=%d,y=%d\n", z, x, y);
						goodsSellCase goodssellCase = (goodsSellCase)GetProcAddress(hInstLibrary, "goodsSellCase");

						if (NULL != goodssellCase) {
							nRetCode = goodssellCase(z, x, y);
							desc = "goodsSellCase method success";
						}
						else {
							nRetCode = -2;
							desc ="not found goodsSellCase method";
						}
					}
					break;

				case IS_CoorDinateHome:
					{
						//cout << "the parameter->" << argv[2] << "\n";
					if (argc != 3) {
						desc = "the second parameter occor error";
						nRetCode = -1;
						break;
					}
					
					vector<string> v = split(argv[2], ":");
					if (v.size() != 2) {
						nRetCode = -2;
						desc = "the second parameter split occor error";
						break;
					}
						//printf("x=%d,y=%d\n", x, y);
						int x = 0, y = 0;
						x = atoi(v[0].data());
						y = atoi(v[1].data());
						CoorDinateHome coorDinateHome = (CoorDinateHome)GetProcAddress(hInstLibrary, "CoorDinateHome");
						if (NULL != coorDinateHome) {
							nRetCode = coorDinateHome(x, y);
							desc = "CoorDinateHome method success";
						}
						else {
							nRetCode = -2;
							desc = "not found CoorDinateHome method";
						}
					}

					break;

				case IS_PreposeMotorHome:
				{
					//cout << "the parameter->" << argv[2] << "\n";
					if (argc != 3) {
						desc = "the second parameter occor error";
						nRetCode = -1;
						break;
					}
					int x = 0;
					x = atoi(argv[2]);
					//printf("x=%d\n", x);
					PreposeMotorHome preposeMotorHome = (PreposeMotorHome)GetProcAddress(hInstLibrary, "PreposeMotorHome");
					if (NULL != preposeMotorHome) {
						nRetCode = preposeMotorHome(x);
						desc = "PreposeMotorHome method success";
					}
					else {
						nRetCode = -2;
						desc = "not found PreposeMotorHome method";
					}
				}
					break;

				default:
					nRetCode = -2;
					desc = "input method serial error";
					
				}
			
			}
			else
				{
					nRetCode = -2;
					desc = "错误: GetModuleHandle 失败";
					
				}

			}
	}catch (...) {
		nRetCode = -2;
		desc = "错误: 代码抛出异常 失败";
	}
	printf("code:%d,desc:%s", nRetCode,desc);
    return nRetCode;
}
