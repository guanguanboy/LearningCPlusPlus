class X {
	int m;

public:
	X(int v = 0):m(v){}
	void set(int v) { m = v; }
	int get() const{ return m; }
};

int main()
{
	const int iv = 100;
	//iv = 200;
	X a;
	a.set(10);
	a.get();

	const X b(5);
	b.get();   //正确操作，get函数是const成员函数
	b.set(10); //错误的操作，因为set函数不是const类型
}