#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <vector>

using namespace std;

//map 简单应用
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

//map 嵌套使用
#if 0
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
动态申请内存的玩法
map<int, map<int, int>* > nestedMap;
map<int, int>* temp = new map<int, int>;
nestedMap[10] = temp;

申请的内存得释放：
map<int, int>* temp1;

for (nestedItr = nestedMap.begin(); nestedItr != nestedMap.end(); nestedItr++)
{
	temp1 = nestedMap->second;
	delete temp1;
	temp1 = NULL;
}
*/
#endif


//list使用

#if 0
//利用迭代器操作list
class Demo
{
	//string str;

public:
	string str;

public:
	Demo(string _str = "hi") { str = _str; }
	string getString() {
		return str;
	}
};

int main()
{
	list<int> ilist(2, 2); //创建一个拥有两个元素的list，每个元素的初始值是2
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
		//cout << de_iter->getString() << endl;
		cout << de_iter->str << endl;
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

#if 0

void printList(list<int>& templist)
{
	//it = templist.begin();

	for (list<int>::iterator it = templist.begin(); it != templist.end(); it++)
	{
		cout << ' '<< *it;
	}

	cout << endl;
}

int main()
{
	list<int> mylist;
	list<int>::iterator it;

	for (int i = 1; i <= 5; i++)
	{
		mylist.push_back(i); // 1 2 3 4 5
	}

	printList(mylist);

	it = mylist.begin();
	++it; //it points now to number 2

	mylist.insert(it, 10); // 1 10 2 3 4 5

	printList(mylist);

	mylist.insert(it, 2, 20); // "it" still points to number 2, 1 10 20 20 2 3 4 5

	printList(mylist);

	--it; // it points noew to the second 20

	vector<int> myvector(2, 30);
	mylist.insert(it, myvector.begin(), myvector.end()); // 1 10 20 30 30 20 2 3 4 5

	cout << "mylist contains:";

	printList(mylist);
	
	system("pause");

	return 0;
}

#endif

#if 0

//vector<int> *kkk;//vector向量指针**

int main()
{
	vector<int> *k;//vector向量指针  
	k = new vector<int>[5];
	//相当于int *p = new int[5];即vector<int> *kkk=new vector<int>[5];  
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j<10; j++)
		{
			k[i].push_back(j);//像向量指针中追加值  
		}
	}
	for (int i = 0; i<5; i++)
	{
		for (int j = 0; j < k[i].size(); j++)
			cout << k[i][j] << "  ";
		cout << endl;
	}
	delete[] k;

	vector<int> *pVec;
	pVec = new vector<int>;

	for (int i = 0; i < 20; i++)
	{
		pVec->push_back(i);
	}

	cout << " size = " << pVec->size() << endl;

	for (vector<int>::iterator it = pVec->begin(); it != pVec->end(); it++)
	{
		cout << *it << " ";
	}

	delete pVec;
	system("pause");
}

#endif

#if 0

int main()
{
	map <int, string> scores;

	scores.insert(make_pair(100, "maxi"));
	scores[100] = "MAXI";
	scores.insert(make_pair(300, "xiaoyu"));
	scores.insert(make_pair(300, "xiao"));
	scores[200] = "xiaoma";

	map<int, string>::iterator pScores;

	for (pScores = scores.begin(); pScores != scores.end(); pScores++)
	{
		cout << pScores->first << " " << pScores->second << endl;
	}

	system("pause");

	return 0;
}

/*
从上面这个demo可以看出，scores[100] = "MAXI"; 会直接替换掉 原来map中key 100 对应的value,.
如果调用scores.insert()函数，则由于map中已存在key 为 100的记录，新记录将无法插入。
由于是单映射，后面加入的新的pair对如果有key值和前面一样，那么后面的pair对元素将不会被加入到map中
*/
#endif

#if 1

int main()
{
	map<int, map<int, string>> multiMap;

	map<int, string> temp;

	temp.insert(make_pair(90, "hi"));
	temp.insert(pair<int, string>(100, "maxit"));

	multiMap.insert(make_pair(10, temp));

	multiMap[10][80] = "xiaoyu";
	multiMap[5][30] = "xiaoma";

	map<int, map<int, string>>::iterator multiIterator;
	map<int, string>::iterator iter;

	for (multiIterator = multiMap.begin(); multiIterator != multiMap.end(); multiIterator++)
	{
		for (iter = multiIterator->second.begin(); iter != multiIterator->second.end(); iter++)
		{
			cout << multiIterator->first << " " << iter->first << "(" << iter->second << ")" << endl;
		}
	}

	map<int, string>& ref = multiMap[10];

	for (iter = ref.begin(); iter != ref.end(); iter++)
	{
		cout << iter->first << "(" << iter->second << ")" << endl;
	}


	multiMap.erase(10);

	cout << "after erase" << endl;

	for (multiIterator = multiMap.begin(); multiIterator != multiMap.end(); multiIterator++)
	{
		for (iter = multiIterator->second.begin(); iter != multiIterator->second.end(); iter++)
		{
			cout << multiIterator->first << " " << iter->first << "(" << iter->second << ")" << endl;
		}
	}

	map<int, string> temp1;

	temp1.insert(make_pair(110, "hi"));
	temp1.insert(make_pair(120, "hi"));

	multiMap[10] = temp1;


	cout << "after add temp1" << endl;

	for (multiIterator = multiMap.begin(); multiIterator != multiMap.end(); multiIterator++)
	{
		for (iter = multiIterator->second.begin(); iter != multiIterator->second.end(); iter++)
		{
			cout << multiIterator->first << " " << iter->first << "(" << iter->second << ")" << endl;
		}
	}

	system("pause");

	return 0;
}

#endif