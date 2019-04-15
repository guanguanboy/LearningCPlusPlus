#include <iostream>

using namespace std;

class Singleton {

private:
	int num;
	static Singleton* sp;
	Singleton(int _num) { num = _num; }
	Singleton(const Singleton&) {}; //·ÀÖ¹¸´ÖÆ¶ÔÏó
public:
	static Singleton* getInstance(int _num);
	void handle() {
		if (num > 0) {
			cout << num << endl;
			num -= 1;
		}
		else
		{
			cout << "num is zero!" << endl;
		}
	}
};

Singleton* Singleton::sp = 0;

Singleton* Singleton::getInstance(int _num)
{
	if (0 == sp)
	{
		sp = new Singleton(_num);
		return sp;
	}
}

int main()
{
	Singleton* sp = Singleton::getInstance(1);
	sp->handle();

	Singleton* st = Singleton::getInstance(10);
	sp->handle();

	system("pause");

	return 0;
}