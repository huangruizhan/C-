#ifndef __FishingJoy__ScheduleCountDown__
#define __FishingJoy__ScheduleCountDown__
#include "cocos2d.h"
#include "ScheduleCounterProtocol.h"

class ScheduleCountDown : public cocos2d::CCNode
{
public:
    /*
     	@brief
     
     	@param 	target 	ʵ��ScheduleCounterDelegate����
        @param 	perimeter 	����ʱ������
     	@param 	loop 	�Ƿ�ѭ����
     
     	@return
    */ 
    static ScheduleCountDown* create(ScheduleCounterDelegate* target, int perimeter = 99, bool loop = true);
    bool init(ScheduleCounterDelegate* target, int perimeter = 60, bool loop = true);
    CC_SYNTHESIZE(bool, _loop, Loop);
protected:
    ScheduleCounterDelegate* _target;
    //��ǰʱ��
    int _curTime;
    //���ʱ��
    int _maxTime;
   void schedulePerSecond();
};

#endif