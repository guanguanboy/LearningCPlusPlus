#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

#if 0
int main()
{
	list<list<map<int, string>>> l;

	map<int, string> m1;

	m1.insert(pair<int, string>(1, "1"));
	m1.insert(pair<int, string>(2, "2"));
	m1.insert(pair<int, string>(3, "3"));

	list<map<int, string>> ol;

	ol.push_back(m1);

	l.push_back(ol);

	for (list<list<map<int, string>>>::iterator it = l.begin(); it != l.end(); it++)
	{
		for (list<map<int, string>>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++)
		{
			for (map<int, string>::iterator it2 = (*it1).begin(); it2 != (*it1).end(); it2++)
			{
				cout << "value:" << it2->first << " " << it2->second << endl;
			}
		}
	}

	printf("n");

	system("pause");

	return 0;
}

#endif

#if 1

int main()
{
	list<list<int>> l;

	list<int> l1;
	list<int> l2;

	l1.push_back(1);
	l1.push_back(2);

	l2.push_back(3);
	l2.push_back(4);

	l.push_back(l1);
	l.push_back(l2);

	for (list<list<int>>::iterator it = l.begin(); it != l.end(); it++)
	{
		for (list<int>::iterator it1 = (*it).begin(); it1 != (*it).end(); it1++)
		{
			cout << "value:" << *it1 << endl;
		}
	}

	system("pause");

	return 0;
}

#endif