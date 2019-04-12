
#if 0
#include<iostream>
using namespace std;
int main() {
	int n, m;
	//n����������m��������
	//  cout << "Please input the N:";
	cin >> n;
	if (n<1) {
		cout << "���벻����Ҫ������������" << endl;
		cin >> n;
	}
	//cout << "Please input the M:";
	cin >> m;
	if (m>1000) {
		cout << "���벻����Ҫ������������" << endl;
		cin >> m;
	}
	int **iArr1 = NULL;
	//��̬���ٶ�ά����,�ص�
	iArr1 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		iArr1[i] = new int[m];
	}
	//cout << endl;
	int **iArr2 = NULL;
	iArr2 = new int*[m];
	for (int i = 0; i < m; i++)
	{
		iArr2[i] = new int[n];
	}
	//����ά����iArr1��ֵ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> iArr1[i][j];
		}
	}
	//int temp = 0;
	//ת��λ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			iArr2[j][i] = iArr1[i][j];
		}
	}
	//int temp = 0;
	for (int i = 0; i < m / 2; i++) {
		for (int j = 0; j < n; j++) {
			/*
			����ʹ���м��������ñ���Ĵ����㷨
			a=a+b;
			b=a-b;
			a=a-b;
			*/
			iArr2[i][j] = iArr2[i][j] + iArr2[m - 1 - i][j];
			iArr2[m - 1 - i][j] = iArr2[i][j] - iArr2[m - 1 - i][j];
			iArr2[i][j] = iArr2[i][j] - iArr2[m - 1 - i][j];
		}
	}
	//������
	//cout << "The Array iArr1 is��" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << iArr1[i][j] << " ";
		}
		cout << endl;
	}

	//cout << "The Array iArr2 is:"<<endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << iArr2[i][j] << " ";
		}
		cout << endl;
	}
	//���ٿ��ٵĿռ�,��delete���ص�
	for (int i = 0; i < n; i++)
	{
		delete[] iArr1[i];
		iArr1[i] = NULL;
	}
	delete[]iArr1;
	iArr1 = NULL;
	for (int i = 0; i < m; i++)
	{
		delete[] iArr2[i];
		iArr2[i] = NULL;
	}
	delete[]iArr2;
	iArr2 = NULL;
	return 0;

}
//-------------------- -
//���ߣ�wangfanna
//��Դ��CSDN
//ԭ�ģ�https ://blog.csdn.net/wangfanna/article/details/52463713 
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

#endif

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int RotationRight90(unsigned char * src, int srcW, int srcH, int channel)
{
	unsigned char * tempSrc = NULL;
	int mSize = srcW * srcH * sizeof(char) * channel;
	int i = 0;
	int j = 0;
	int k = 0;
	int desW = 0;
	int desH = 0;

	desW = srcH;
	desH = srcW;

	tempSrc = (unsigned char *)malloc(sizeof(char) * srcW * srcH * channel);
	memcpy(tempSrc, src, mSize);

	for (i = 0; i < desH; i++)
	{
		for (j = 0; j < desW; j++)
		{
			for (k = 0; k < channel; k++)
			{
				
				src[(i * desW + j) * channel + k] = tempSrc[((desW - j - 1) * desH + i) * channel + k];

			}

		}
	}

	free(tempSrc);
	return 0;
}

// ��ʱ��90��
int RotationLeft90(unsigned char * src, int srcW, int srcH, int channel)
{
	unsigned char * tempSrc = NULL;
	int mSize = srcW * srcH * sizeof(char) * channel;
	int i = 0;
	int j = 0;
	int k = 0;
	int desW = 0;
	int desH = 0;

	desW = srcH;
	desH = srcW;

	tempSrc = (unsigned char *)malloc(sizeof(char) * srcW * srcH * channel);
	memcpy(tempSrc, src, mSize);

	for (i = 0; i < desH; i++)
	{
		for (j = 0; j < desW; j++)
		{
			for (k = 0; k < channel; k++)
			{
				src[(i * desW + j) * channel + k] = tempSrc[(j * desH + desH - i - 1) * channel + k];

			}

		}
	}

	free(tempSrc);
	return 0;
}

void printImage(unsigned char * image, int width, int height, int channel)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < channel; k++)
			{
				printf("%c ", image[(i*width + j) * channel + k]);
			}
			
			printf("  ");
		}

		printf("\r\n");
	}
}

//single channel test
/*
int main()
{
	unsigned char image[12] = { '1','2','3','4','5','6','7','8','9', 'a', 'b', 'c' };

	int width = 4;
	int height = 3;

	printImage(image, width, height,1);

	RotationRight90(image, width, height, 1);
	//RotationLeft90(image, width, height, 1);

	int width_afterrotation = height;
	int height_afterrotation = width;
	printImage(image, width_afterrotation, height_afterrotation, 1);

	system("pause");
	return 0;
}*/

//multichanneltest
int main()
{
	unsigned char image[16] = { '1','2','3','4','5','6','7','8','9', 'a', 'b', 'c', 'd', 'e', 'f', 'g'};

	int width = 4;
	int height = 2;

	printImage(image, width, height, 2);

	//RotationRight90(image, width, height, 1);
	RotationLeft90(image, width, height, 2);

	int width_afterrotation = height;
	int height_afterrotation = width;
	printImage(image, width_afterrotation, height_afterrotation, 2);

	system("pause");
	return 0;
}