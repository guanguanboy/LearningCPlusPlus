/*���ܣ�C�ļ��е���C++�Ľӿ�
�����cpp�ļ���û�н�add��������Ϊextern "C" �ģ�����c�ļ��е���ʱ����linkʱ���ᷢ��������ʾ�޷��������ⲿ����
*/
/**** CԴ�ļ�c.c *****/
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