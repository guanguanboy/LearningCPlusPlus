#include<iostream>
#include<thread>
#include<mutex>

/* ���demo��Ҫ������ʾ����Ա������Ϊ�߳�ִ�к��� */
std::mutex mut;

class A {

public:

	volatile int temp;
	/*
	volatile��const�ؼ������ƣ��������α����ģ�ֻ�Ƕ��߹��ܲ�һ����
	volatile�ڶ��̵߳��о���ʹ�ã���Ϊ��ĳһ�̶߳�ε���ĳһ��������������������Ż������ñ���������ڼĴ������У�����ÿ�ζ����ڴ浱�ж��롣��Ȼ�ñ���ͬʱ�������̵߳��б��޸ģ������ͻᷢ�����ȡ����

	������volatile���Σ�������ѱ�����������������ܻᱻ�ı䣬���ܴ�ŵ��Ĵ������У���Ҫÿ�ζ����ڴ浱�ж�ȡ��
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

//�ο����ͣ�https://www.cnblogs.com/code-wangjun/p/7476559.html