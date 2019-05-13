#include "Vector3.h"
#include <iostream>

using namespace std;

int main()
{
	Vector3 p1(4, 5, 6);
	Vector3 p2(1, 2, 3);

	Vector3 p3;
	p3.add(p1, p2);

	cout << p3.x << p3.y << p3.z << endl;

	if (p1 != p2)
	{
		cout << "p1 is different from p2" << endl;
	}
	system("pause");

}