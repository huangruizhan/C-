#ifndef __FishingJoy__ScheduleCounterProtocol__
#define __FishingJoy__ScheduleCounterProtocol__
typedef void (__stdcall* setScheduleNumber)(void);
class ScheduleCounterDelegate
{
public:
    /**
     *	@brief	    Required
     */
    virtual void __stdcall scheduleTimeUp() = 0;
    /**
     *	@brief	    Optional
     *
     *	@param 	number 	需要设置的数字
     */
    virtual void __stdcall setScheduleNumber(int number){return;};
};

#endif
