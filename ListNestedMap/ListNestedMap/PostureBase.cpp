//
// Created by liguanlin on 2019/4/11.
//

#include <android/log.h>
#include "include/PostureBase.h"

#define LOG_TAG "PostureBase"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, __VA_ARGS__)

PostureBase::PostureBase(PostureManager *pPostureManager) {

    m_state = 0;
    m_timestamp = 0.0f;
    m_progress = 0.0f;
    m_complete = false;
    m_cancelled = false;
    m_startTrackingAtTime = 0.0f;
    m_poseCompleteDuration = 0.0f;
    m_poseCompleteDuration = -1;

    m_pCustomParam = nullptr;
    m_pPostureManager = pPostureManager;
}

PostureBase::~PostureBase() {

//    if (nullptr != m_pPostureManager){
//        delete m_pPostureManager;
//        m_pPostureManager = nullptr;
//    } //不能在这里删除m_pPostureManager，m_pPostureManager是全局存在的唯一对象，至少也应该在PostureCheckDemo中去销毁
    //其实可以不在PostureBase中弄这个成员变量，其实只有在需要通过m_pPostureManager获取世界坐标时，获取唯一的对象就可以了。
    //这里为了避免每次获取的麻烦，所以在这里设计了这个成员变量

    if (nullptr != m_pCustomParam){
        delete  m_pCustomParam;
        m_pCustomParam = nullptr;
    }
}

void PostureBase::setGestureJoint(float timestamp) {

    m_timestamp = timestamp;
    m_state ++;

    LOGD("PostureBase::setGestureJoint");
}

void PostureBase::checkPoseComplete(float timestamp, bool isInPose, float durationToComplete) {

    if (true == isInPose){
        float timeLeft = timestamp - m_timestamp;
        float ratio = timeLeft / durationToComplete;

        //下面这段代码用来实现Mathf.Clamp01(timeLeft / durationToComplete)
        float  tempProgress;
        if (ratio < 0){
            tempProgress = 0.0f;
        } else if (ratio > 1){
            tempProgress = 1.0f;
        } else{
            tempProgress = ratio;
        }

        m_progress = durationToComplete > 0.0f ? tempProgress : 1.0f;

        LOGD("timeLeft = %f, durationToComplete = %f", timeLeft, durationToComplete);

        if (timeLeft >= durationToComplete)
        {
            m_timestamp = timestamp;
            m_state++;
            m_complete = true;
            LOGD("PostureBase::checkPoseComplete set m_complete to true");

        }

        LOGD("PostureBase::checkPoseComplete complete");
    }
    else{
        setGestureCancelled();
        LOGD("PostureBase::checkPoseComplete canceled");

    }
}

void PostureBase::setGestureCancelled() {

    m_state = 0;
    m_progress = 0.0f;
    m_cancelled = true;
}

void PostureBase::setCustonParam(PostureCustomParam *pCustomParam) {

    m_pCustomParam = pCustomParam;
}
