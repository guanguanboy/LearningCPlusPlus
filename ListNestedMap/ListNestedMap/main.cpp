//#include "PostureListener.h"
#include <iostream>
#include <map>
#include <list>

#include "PostureCustomParam.h"

typedef void(*DetectPostureHandler)();
typedef void(*DetectInProgressHandler)(float progress);
//class PostureBase;

class PostureListener {

public:
	//PostureBase *m_pPosture; //为什么要在listener中保存一个基类的指针
	DetectPostureHandler m_OnDetectStart;
	DetectInProgressHandler m_InDetectProgress;
	DetectPostureHandler m_OnDetectComplete;

	PostureListener(
		DetectPostureHandler detectStartCallBack,
		DetectInProgressHandler detectInProgressCallBack,
		DetectPostureHandler detectCompleteCallBack,
		PostureCustomParam *pargs);

	~PostureListener();
};



using namespace std;

void dectectHandler()
{
	cout << " This is dectectHandler" << endl;
}

void inProgress(float progress)
{
	cout << "this is inPrograss" << endl;
}

void dectectStart()
{
	cout << "This is dectectStart" << endl;
}

int main()
{
	map<int, list<PostureListener> > postureListenerMap;

	list<PostureListener> postureListenerList;

	PostureListener p1(dectectStart, inProgress, dectectHandler,nullptr);
	PostureListener p2(dectectStart, inProgress, dectectHandler, nullptr);

	PostureListener p3(dectectStart, inProgress, dectectHandler, nullptr);
	PostureListener p4(dectectStart, inProgress, dectectHandler, nullptr);


	postureListenerList.push_back(p1);
	postureListenerList.push_back(p2);

	postureListenerMap[10] = postureListenerList;


	cout << "postureListenerMap size = " << postureListenerMap.size() << endl;

	postureListenerMap.erase(10);

	cout << "postureListenerMap size = " << postureListenerMap.size() << endl;

	list<PostureListener> postureListenerList1;

	postureListenerList1.push_back(p3);
	postureListenerList1.push_back(p4);

	postureListenerMap[10] = postureListenerList1;

	cout << "postureListenerMap size = " << postureListenerMap.size() << endl;

	postureListenerMap.erase(10);

	cout << "postureListenerMap size = " << postureListenerMap.size() << endl;

	list<PostureListener> *postureListenerList2 = new list<PostureListener>;

	postureListenerList2->push_back(p3);
	postureListenerList2->push_back(p4);

	postureListenerMap[10] = *postureListenerList2;

	delete postureListenerList2;

	cout << "postureListenerMap size = " << postureListenerMap.size() << endl;


	system("pause");

	return 0;
}