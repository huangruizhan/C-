#ifndef __FishingJoy__PanelLayer__
#define __FishingJoy__PanelLayer__
#include "cocos2d.h"
#include "GoldCounterLayer.h"
#include "ScheduleCounterProtocol.h"
class PanelLayer : public cocos2d::CCLayer ,public ScheduleCounterDelegate
{
public:
    CREATE_FUNC(PanelLayer);
    bool init();
    CC_SYNTHESIZE_READONLY(GoldCounterLayer*, _goldCounterLayer, GoldCounterLayer);    
    void __stdcall scheduleTimeUp();
    void __stdcall setScheduleNumber(int number);
protected:
    void pause(cocos2d::CCObject* pSender);
    cocos2d::CCLabelTTF* _scheduleLabel;
};

#endif 
