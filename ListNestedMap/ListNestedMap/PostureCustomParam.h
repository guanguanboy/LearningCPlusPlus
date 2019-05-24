//
// Created by liguanlin on 2019/4/12.
//

#ifndef SKELETONDEMO_POSTURECUSTOMPARAM_H
#define SKELETONDEMO_POSTURECUSTOMPARAM_H


class PostureCustomParam {

public:
    PostureCustomParam(){
        m_poseCompleteDuration = 0;
        m_maxPoseDetectTime = 0;
        m_checkTolerance = 0;
        m_minTimeBetweenNextDetect = 1;
    };
    PostureCustomParam(float poseCompleteDuration, float maxPoseDetectTime,
                       float checkTolerance,float minTimeBetweenNextDetect = 1){
        m_poseCompleteDuration = poseCompleteDuration;
        m_maxPoseDetectTime = maxPoseDetectTime;
        m_checkTolerance = checkTolerance;
        m_minTimeBetweenNextDetect = minTimeBetweenNextDetect;
    }

    float getPoseCompleteDurationP(){
        return m_poseCompleteDuration;
    }

    float getMaxPoseDetectTime(){
        return m_maxPoseDetectTime;
    }

    float getCheckTolerance(){
        return m_checkTolerance;
    }

    float getMinTimeBetweenNextDetect(){
        return m_minTimeBetweenNextDetect;
    }

private:
    float m_poseCompleteDuration;
    float m_maxPoseDetectTime;
    float m_checkTolerance;
    float m_minTimeBetweenNextDetect;
};


#endif //SKELETONDEMO_POSTURECUSTOMPARAM_H
