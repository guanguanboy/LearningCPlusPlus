#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

//map ��Ӧ��
#if 0

int main()
{
	map<string, int> dic;
	string word;

	//ifstream file("wordstype.txt");

	//while (file >> word)
	//{
	//	dic[word] += 1;
	//}

	dic["I"] = 10;
	dic["simple"] = 20;

	dic.insert(map<string, int>::value_type("aq", 2));
	dic.insert(map<string, int>::value_type("choice", 10));

	dic.insert(std::pair<string, int>("image", 5));

	map<string, int>::iterator p;

	for (p = dic.begin(); p != dic.end(); p++)
	{
		cout << p->first << "\t" << p->second << endl;
	}

	system("pause");
}
#endif

//map Ƕ��ʹ��
#if 1
int main()
{
	map<int, map<int, int> > nestedMap;

	map<int, int> temp;

	temp[9] = 9;
	temp[10] = 10;

	nestedMap[10] = temp;

	nestedMap[10][11] = 11;

	nestedMap[5][30] = 30;

	map<int, map<int, int> >::iterator nestedIter;
	map<int, int>::iterator iterator;

	for (nestedIter = nestedMap.begin(); nestedIter != nestedMap.end(); nestedIter++)
	{
		for (iterator = nestedIter->second.begin(); iterator != nestedIter->second.end(); iterator++)
		{
			cout << nestedIter->first << " " << iterator->first << "(" << iterator->second << ")" << endl;
		}
	}

	system("pause");
}

/*
��̬�����ڴ���淨
map<int, map<int, int>* > nestedMap;
map<int, int>* temp = new map<int, int>;
nestedMap[10] = temp;

������ڴ���ͷţ�
map<int, int>* temp1;

for (nestedItr = nestedMap.begin(); nestedItr != nestedMap.end(); nestedItr++)
{
	temp1 = nestedMap->second;
	delete temp1;
	temp1 = NULL;
}
*/
#endif


//listʹ��

#if 0
//���õ���������list
class Demo
{
	string str;

public:
	Demo(string _str = "hi") { str = _str; }
	string getString() {
		return str;
	}
};

int main()
{
	list<int> ilist(2, 2); //����һ��ӵ������Ԫ�ص�list��ÿ��Ԫ�صĳ�ʼֵ��2
	list<int>::iterator iter = ilist.begin();

	while (iter != ilist.end())
	{
		cout << *iter << endl;
		iter++;
	}

	list<Demo> delist(2, Demo());

	for (list<Demo>::iterator de_iter = delist.begin();
		de_iter != delist.end(); de_iter++)
	{
		cout << de_iter->getString() << endl;
	}

	list<int> empty;
	list<int>::iterator first = empty.begin(), last = empty.end();

	if (first == last)
	{
		cout << "container is empty" << endl;
	}

	system("pause");
}
#endif
