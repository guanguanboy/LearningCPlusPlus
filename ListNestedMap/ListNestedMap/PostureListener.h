//
// Created by liguanlin on 2019/4/15.
//

#ifndef SKELETONDEMO_POSTURELISTENER_H
#define SKELETONDEMO_POSTURELISTENER_H

//#include "PostureBase.h"
#include "PostureCustomParam.h"

typedef void (*DetectPostureHandler)();
typedef void (*DetectInProgressHandler)(float progress);
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


#endif //SKELETONDEMO_POSTURELISTENER_H
