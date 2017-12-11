#ifndef __FishingJoy__ScheduleCountDown__
#define __FishingJoy__ScheduleCountDown__
#include "cocos2d.h"
#include "ScheduleCounterProtocol.h"

class ScheduleCountDown : public cocos2d::CCNode
{
public:
    static ScheduleCountDown* create(ScheduleCounterDelegate* target, int perimeter = 99, bool loop = true);
    bool init(ScheduleCounterDelegate* target, int perimeter = 60, bool loop = true);
    CC_SYNTHESIZE(bool, _loop, Loop);
protected:
    ScheduleCounterDelegate* _target;
    //当前时间
    int _curTime;
    //最大时间
    int _maxTime;
   void schedulePerSecond();
};

#endif
