#ifndef __FishingJoy__ScheduleCounterProtocol__
#define __FishingJoy__ScheduleCounterProtocol__
typedef void (__stdcall* setScheduleNumber)(void);
class ScheduleCounterDelegate
{
public:
    virtual void __stdcall scheduleTimeUp() = 0;
    virtual void __stdcall setScheduleNumber(int number){return;};
};

#endif
