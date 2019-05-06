#include<iostream>
#include<thread>
#include<mutex>

/* 这个demo主要用来演示，成员函数作为线程执行函数 */
std::mutex mut;

class A {

public:

	volatile int temp;
	/*
	volatile和const关键很相似，都是修饰变量的，只是二者功能不一样。
	volatile在多线程当中经常使用，因为在某一线程多次调用某一个变量，编译器会进行优化，将该变量存放在在寄存器当中，不会每次都从内存当中读入。果然该变量同时在其他线程当中被修改，这样就会发生脏读取错误。

	而加上volatile修饰，则会提醒编译器，这个变量可能会被改变，不能存放到寄存器当中，需要每次都从内存当中读取。
	*/

	A() {
		temp = 0;
	}

	void fun(int num) {

		int count = 10;
		while (count>0) {

			mut.lock();
			temp++;
			std::cout << "thread_" << num << "...temp=" << temp << std::endl;
			mut.unlock();

			count--;
		}
	}

	void thread_run() {
		std::thread t1(&A::fun, this, 1);

		std::thread t2(&A::fun, this, 2);

		t1.join();
		t2.join();
	}
};

int main() {

	A a;

	a.thread_run();

	system("pause");

	return 0;
}

//参考博客：https://www.cnblogs.com/code-wangjun/p/7476559.html