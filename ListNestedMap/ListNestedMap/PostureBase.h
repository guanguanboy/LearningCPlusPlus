//
// Created by liguanlin on 2019/4/11.
//

#ifndef SKELETONDEMO_POSTUREBASE_H
#define SKELETONDEMO_POSTUREBASE_H

#include "PostureCustomParam.h"
#include "PostureManager.h"

class PostureManager;

class PostureBase {

public:
    PostureBase(PostureManager *pPostureManager);
    virtual ~PostureBase();
    virtual void checkForGesture(int userId, float timestamp) = 0;
    void setGestureJoint( float timestamp);
    void checkPoseComplete( float timestamp, bool isInPose,float durationToComplete);
    void setGestureCancelled();
    void setCustonParam(PostureCustomParam *pCustomParam);
    bool isComplete(){return m_complete;}
    bool isCancelled(){return m_cancelled;}
    float getProgress(){return m_progress;}
    float getStartTrackingTime(){return m_startTrackingAtTime;}

    void setProgress(float progress){m_progress = progress;}
    void setStartTrackingTime(double currTime){m_startTrackingAtTime = currTime;}
    void resetCompletionStatus(){m_complete = false;}
    void resetCancelledStatus(){m_cancelled = false;}
    void setRecognitionStatus(int status){m_state = status;}
    PostureCustomParam *getCustonParamg(){return m_pCustomParam;}
protected:
    int m_state;//识别状态 0：尚未识别 1：正在识别
    float m_timestamp; // 上次检查时间戳
    float m_progress; // 识别百分比 在gesture是wheel时 表示旋转角度，gesture是ZoomIn/Out时候 表示 增大缩小倍数
    bool m_complete; // 是否识别完成
    bool m_cancelled; // 是否识别取消
    float m_startTrackingAtTime; // 可以开始识别的时间点
    float m_poseCompleteDuration; // 动态动作这个值设置为0，静态动作设置为识别该动作需要保持的时间
    PostureCustomParam *m_pCustomParam; //定制姿势识别参数类，若此值为空，姿势识别使用默认参数，否则以此值内容为准
    PostureManager *m_pPostureManager;
};


#endif //SKELETONDEMO_POSTUREBASE_H
