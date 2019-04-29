/****** C++源文件cpp.cpp ******/
/* 
	主要展示了，在cpp文件中调用c文件中的函数，需要在c文件中将函数声明为extern “c”的，否则会找不到符号
*/
#include <iostream>
#include "cfun.h"

int main()
{
	C_fun();
	system("pause");

	return 0;
}