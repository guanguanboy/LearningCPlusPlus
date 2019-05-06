// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx;           // mutex for critical section

/* ��������Ч�������ַ��Ž����ӡ */
void print_block_no_mutex(int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	//mtx.lock();
	for (int i = 0; i<n; ++i) { std::cout << c; }
	std::cout << '\n';
	//mtx.unlock();
}

/* ������Ч����һ�ַ��Ŵ�ӡ��֮���ٴ�ӡ��һ�ַ��� */
void print_block_with_mutex(int n, char c) {
	// critical section (exclusive access to std::cout signaled by locking mtx):
	mtx.lock();
	for (int i = 0; i<n; ++i) { std::cout << c; }
	std::cout << '\n';
	mtx.unlock();
}

int main()
{
	std::thread th1(print_block_with_mutex, 500, '*');
	std::thread th2(print_block_with_mutex, 500, '$');

	//th1.join();
	//th2.join();

	th1.detach();
	th2.detach();

	system("pause");

	return 0;
}