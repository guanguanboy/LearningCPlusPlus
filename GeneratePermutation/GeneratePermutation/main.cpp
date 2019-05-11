#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	for (string str; cin >> str;)
	{
		if (str.empty())
		{
			continue;
		}

		if (str.length() <= 1)
		{
			cout << "No more Permutation" << endl;
		}

		string::iterator iPivot = str.end(), iNewHead;//iPivotΪ�ұ�
		//�������Ӽ�������ڵ�һ��Ԫ��

		for (--iPivot; iPivot != str.begin(); --iPivot)
			//�����ұ����ļ����Ӽ�
		{
			if (*(iPivot - 1) < *iPivot)
			{
				break;
			}
		}

		if (iPivot == str.begin())//����������ж�Ϊ���������Ž���
		{
			cout << "No more Permutation" << endl;
		}

		iPivot--;//��iPivotָ���Ӽ�������ڵ�һ��Ԫ��
		
		//INewHeadΪ����iPivot���Ԫ�أ����Ҳ�����Ӽ���Ѱ��
		for (iNewHead = iPivot + 1; iNewHead != str.end(); ++iNewHead)
		{
			if (*iNewHead < *iPivot)
			{
				break;
			}
		}

		iter_swap(iPivot, --iNewHead);//����iPivot��iNewHead��ֵ�������ı����ǵ�ָ��

		reverse(iPivot + 1, str.end()); //��ת�Ҳ�����Ӽ���ʹ֮��Ϊ��С�������Ӽ�

		cout << str << endl; //����������ɣ�������
	}

	system("pause");

	return 0;
}