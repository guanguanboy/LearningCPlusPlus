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

		string::iterator iPivot = str.end(), iNewHead;//iPivot为右边
		//最大减序子集左边相邻的一个元素

		for (--iPivot; iPivot != str.begin(); --iPivot)
			//查找右边最大的减序子集
		{
			if (*(iPivot - 1) < *iPivot)
			{
				break;
			}
		}

		if (iPivot == str.begin())//如果整个序列都为减序，则重排结束
		{
			cout << "No more Permutation" << endl;
		}

		iPivot--;//让iPivot指向子集左边相邻的一个元素
		
		//INewHead为仅比iPivot大的元素，在右侧减序子集中寻找
		for (iNewHead = iPivot + 1; iNewHead != str.end(); ++iNewHead)
		{
			if (*iNewHead < *iPivot)
			{
				break;
			}
		}

		iter_swap(iPivot, --iNewHead);//交换iPivot和iNewHead的值，但不改变它们的指向

		reverse(iPivot + 1, str.end()); //反转右测减序子集，使之成为最小的增序子集

		cout << str << endl; //本轮重排完成，输出结果
	}

	system("pause");

	return 0;
}