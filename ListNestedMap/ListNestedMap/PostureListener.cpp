//
// Created by liguanlin on 2019/5/16.
//

#include <iostream>
#include "PostureListener.h"

using namespace std;

PostureListener::PostureListener(
DetectPostureHandler detectStartCallBack,
        DetectInProgressHandler detectInProgressCallBack,
DetectPostureHandler detectCompleteCallBack,
        PostureCustomParam *pargs)
{

    //m_pPosture = detectPosture;

    //if (nullptr != m_pPosture){
    //    m_pPosture->setCustonParam(pargs);
    //}

    m_OnDetectStart = detectStartCallBack;
    m_InDetectProgress = detectInProgressCallBack;
    m_OnDetectComplete = detectCompleteCallBack;
}

PostureListener::~PostureListener()
{
	std::cout << "listener destroyed" << std::endl;
}