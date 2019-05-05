#include <iostream>
#include <thread>
#include <string>
#include <chrono>
#include <mutex>

using namespace std;

//无参任务演示，通常是无参数无返回的函数，这种函数在其所属线程上运行，指导函数执行完毕，线程也就结束了。
//该程序会有异常，原因thread没有指定运行方式，joined或者是detached。
//void go()
//{
//	cout << "Welcome to Thread!";
//}
//
//void main()
//{
//	thread t1(go);
//	system("pause");
//
//	return;
//}

//有参任务演示,该程序会有异常，原因thread没有指定运行方式，joined或者是detached。
//void run(int num)
//{
//	cout << "Thread" << num << endl;
//}
//
//void main()
//{
//	thread p(run, 1);
//	system("pause");
//}

//启动了线程，你需要明确是要等待线程结束（加入式joined）,还是让其自主运行（分离式detached）.如果
//如果std::thread对象销毁之前还没有做出决定，程序就会终止(std::thread的析构函数会调用std::terminate()).因此，即便是有异常存在，
//也需要确保线程能够正确的加入(joined)或分离(detached)

//void run(int num)
//{
//	chrono::seconds(30); //休眠5秒钟
//	std::cout << "Thread " << num << endl;
//	cout << "This thread id " << this_thread::get_id() << endl;
//
//}
//
//void main()
//{
//	thread t(run, 1);
//	cout << "Thread id is " << t.get_id() << endl;
//
//	if (t.joinable()) //joinable()查看当前线程是否可被join  true thread没有被join， flase表示thread已被join
//	{
//		t.join();
//	}
//	cout << "Thread id is " << t.get_id() << endl;
//
//	system("pause");
//}

//分离线程，使用detach()会让线程在后台运行，这就意味着主线程不能与之产生之间交互。
//也就是说不会等待这个线程结束。如果线程分离，就不可能有std::thread对象能引用它，分离线程的确在后台运行
//所以分离线程不能被加入。不过c++运行库保证，当线程退出时，相关资源能够正确回收，
//后台线程的归属和控制，C++运行库都会处理。

//

//转移线程所有权
//假设要写一个在后台启动线程的函数，想通过新线程返回的所有权去调用这个函数，
//而不是等待线程结束再去调用；或完全与之相反的想法：创建一个线程，并在函数中
//转移所有权，都必须等待线程结束。
//总之，新线程的所有权都需要转移

//

//识别线程
//线程边思类型是thread::id,可以通过两种方式进行检索。
//第一种，可以通过调用thread对象的成员函数get_id()来直接获取。
//如果thread对象没有与任何执行线程相关联，get_id()将返回 std::thread::type 默认构造值，
//这个值表示没有线程。
//第二种，当前线程中调用std::this_thread::get_id() (这个函数定义在 <thread> 头文件中)也可
//以获得线程标识

//线程间共享数据
//当线程在访问共享数据的时候，必须定一些规矩，用来限定线程可访问的数据。
//还有，如果一个线程更新了共享数据，则需要对其它线程进行通知。
//从易用性的角度，同一进程中的多个线程进行数据共享，有利有弊。
//错误的共享数据使用，是产生并发bug的一个主要原因。
//

//共享数据带来的问题
//当涉及到共享数据时，问题很可能是因为共享数据修改所导致。
//如果共享数据是只读的，那么只读操作不会影响到数据，更不会涉及对数据的修改，
//所以，所有数据都会获得同样的数据
//但是，当一个或多个线程要修改共享数据时，就会产生很多麻烦，就必须小心谨慎。
//才能确保一切所有线程都工作正常。

//保护共享数据最基本的方式，是使用c++标准库提供的互斥量(mutex).

//使用互斥量保护共享数据
//当访问共享数据前，使用互斥量将相关数据锁住，再当访问结束后，再将数据解锁。线程库需要保证，当一个线程使用
//特定互斥量锁住共享数据时，其它的线程想要访问锁住的数据，都必须等到之前那个线程对数据进行解锁后，才能进行访问。
//这就保证所有线程都能看到共享数据，而不破坏不变量。
//互斥量是c++中一种最通用的数据保护机制，但它不是银蛋。
//精心组织代码来保护正确的数据，并在接口内部避免竞争条件是非常重要的。

//c++中使用互斥量
//c++中通过实例化mutex创建互斥量，通过调用成员函数lock进行上锁，unlock进行解锁。
//不推荐在实践中直接调用lock进行上锁，因为调用lock意味着，必须记住在每个函数出口都要去
//调用unlock，也包括异常的情况。
//为了解决这个问题C++标准库为互斥量提供了一个RAII语法的模板类std::lack_guard,其会在构造
//的时候提供已锁的互斥量，并在析构的时候进行解锁，从而保证一个已锁的互斥量总是会被正确的
//解锁。

//两个线程并行访问一个变量
int g_num = 20; //找到或者找不到标识

mutex g_mutex;

void goA(int num)
{
	g_mutex.lock();//你访问的变量g_num,在你访问期间，别人访问不了

	for (int i = 0; i < 15; i++) {
		g_num = 10;

		cout << "Thread " << num << " " << g_num << endl;
	}

	g_mutex.unlock();
}

void goB(int num)
{
	for (int i = 0; i < 15; i++)
	{
		g_num = 11;
		cout << "Thread " << num << " " << g_num << endl;
	}
}

void goC(int num)
{
	lock_guard<std::mutex>guard(g_mutex);//自动解锁

	for (int i = 0; i < 15; i++)

	{

		g_num = 10;

		std::cout << "线程" << num << "   " << g_num << endl;

	}
}
void main()
{
	//thread t1(goA, 1);
	thread t1(goC, 1);
	thread t2(goB, 2);

	t1.join();
	t2.join();

	system("pause");
}

////https://www.cnblogs.com/XiaoGuanYu/p/8168686.html