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

	t1.detach();//t1 �̷߳���������ִ̨��

	this_thread::sleep_for(chrono::seconds(3));//main �����������߳�����3��

	//g_threadReady = false; //��ȫ�ֱ�����Ϊfalse ��������ﲻ��g_threadReady��Ϊfalse����main�߳��޷�����
								//���ʱ������������һ��������main�̻߳���������t1�̱߳�ǿ����ֹ
								//��g_threadReady��Ϊfalse֮��3 seconds֮�󣬻���ʾ����������˳���

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
	���ϳ�������н����
	Spawning and detaching 3 threads...
	Done spawning threads.
	(the main thread will now pause for 5 seconds)
	pause of 1 seconds ended
	pause of 2 seconds ended
	pause of 5 seconds ended

	�ӽ�����Կ�����û�����	system("pause"); �������5s���˳��������ȴ�	std::thread(pause_thread, 10).detach();���н���

	�����system("pause"); �������5s����ӡ���밴���������...��
	10s����ӡpause of 10 seconds ended

	F:\CPlusPlusLearningDemos\ThreadTest2\Debug>ThreadTest2.exe
	Spawning and detaching 3 threads...
	Done spawning threads.
	(the main thread will now pause for 5 seconds)
	pause of 1 seconds ended
	pause of 2 seconds ended
	pause of 5 seconds ended
	�밴���������. . . pause of 10 seconds ended

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
	th.detach();//�������̵߳İ󶨣����̹߳��ˣ����̲߳��������߳�ִ�����Զ��˳���  
				//detach�Ժ����̻߳��Ϊ�¶��̣߳��߳�֮�佫�޷�ͨ�š�  
	cout << th.joinable() << endl;
	return 0;
}

#endif
