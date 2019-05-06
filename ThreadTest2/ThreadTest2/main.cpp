#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

bool g_threadReady = true;

void threadFunc()
{

	while (true)
	{
		if (false == g_threadReady)
		{
			cout << "g_threadReady is false" << endl;
			break;
		}

		cout << "I love c++ thread." << endl;
	}
}

#if 0
void main()
{
	thread t1(threadFunc);

	t1.detach();//t1 线程非阻塞，后台执行

	this_thread::sleep_for(chrono::seconds(3));//main 函数所在主线程休眠3秒

	//g_threadReady = false; //将全局变量置为false ，如果这里不将g_threadReady置为false，则main线程无法结束
								//这个时候如果点击任意一个键，则main线程会结束，随后t1线程被强行终止
								//将g_threadReady置为false之后，3 seconds之后，会提示“按任意键退出”

	system("pause");

	return;
}

#endif

#if 0
void pause_thread(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";

	ofstream ofs;
	ofs.open("test.txt", ofstream::out | ofstream::app);

	ofs << "pause of " << n << " seconds ended\n";

	ofs.close();
}

//thread t3(pause_thread, 10);
thread *g_pt3;
int main()
{
	std::cout << "Spawning and detaching 3 threads...\n";
	std::thread(pause_thread, 1).detach();
	std::thread(pause_thread, 2).detach();
	std::thread(pause_thread, 10).detach();
	//t3.detach();

	//g_pt3 = new thread(pause_thread, 10);

	//g_pt3->detach();

	std::cout << "Done spawning threads.\n";

	std::cout << "(the main thread will now pause for 5 seconds)\n";
	// give the detached threads time to finish (but not guaranteed!):
	pause_thread(5);

	system("pause");

	return 0;
}

/* 
	如上程序的运行结果：
	Spawning and detaching 3 threads...
	Done spawning threads.
	(the main thread will now pause for 5 seconds)
	pause of 1 seconds ended
	pause of 2 seconds ended
	pause of 5 seconds ended

	从结果可以看出，没有语句	system("pause"); 程序会在5s后退出，而不等待	std::thread(pause_thread, 10).detach();运行结束

	如果带system("pause"); 则程序在5s后会打印“请按任意键继续...”
	10s后会打印pause of 10 seconds ended

	F:\CPlusPlusLearningDemos\ThreadTest2\Debug>ThreadTest2.exe
	Spawning and detaching 3 threads...
	Done spawning threads.
	(the main thread will now pause for 5 seconds)
	pause of 1 seconds ended
	pause of 2 seconds ended
	pause of 5 seconds ended
	请按任意键继续. . . pause of 10 seconds ended

	*/
#endif

#if 1
void show()
{
	cout << "hello cplusplus!" << endl;
}
int main()
{
	thread th(show);
	//th.join();   
	th.detach();//脱离主线程的绑定，主线程挂了，子线程不报错，子线程执行完自动退出。  
				//detach以后，子线程会成为孤儿线程，线程之间将无法通信。  
	cout << th.joinable() << endl;
	return 0;
}

#endif
