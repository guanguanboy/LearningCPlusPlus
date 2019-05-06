// lock_guard example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard
#include <stdexcept>      // std::logic_error

std::mutex mtx;

void print_even(int x) {
	if (x % 2 == 0) std::cout << x << " is even\n";
	else throw (std::logic_error("not even"));
}

void print_thread_id(int id) {
	try {
		// using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
		std::lock_guard<std::mutex> lck(mtx);  //这是自动锁机制，调用这句话之后，相当于加锁了，然后离开try的大括号作用域之后会自动解锁
		print_even(id);
	}
	catch (std::logic_error&) {
		std::cout << "[exception caught]\n";
	}
}

int main()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i<10; ++i)
		threads[i] = std::thread(print_thread_id, i + 1);

	for (auto& th : threads) th.join();

	system("pause");

	return 0;
}