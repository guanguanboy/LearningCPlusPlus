/*功能：C文件中调用C++的接口
如果在cpp文件中没有将add函数声明为extern "C" 的，则在c文件中调用时，在link时，会发生错误，提示无法解析的外部符号
*/
/**** C源文件c.c *****/
#include <stdlib.h>
#include <stdio.h>

extern int add(int x, int y);

int main(int argc, char* argv[])
{
	int x = 4;
	int y = 6;

	int sum = add(4,6);

	printf("sum= %d.", sum);
	system("pause");
}