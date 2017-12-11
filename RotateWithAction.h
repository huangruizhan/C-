#ifndef __FishingJoy__RotateWithAction__
#define __FishingJoy__RotateWithAction__
#include "cocos2d.h"
class RotateWithAction : public cocos2d::CCActionInterval  
{  
public:  
    CCObject* copyWithZone(cocos2d::CCZone* pZone);  
    ~RotateWithAction();  
    static RotateWithAction* create(CCActionInterval * action);  
    virtual void startWithTarget(cocos2d::CCNode* pTarget);  
    bool initWithAction(CCActionInterval* pAction);  
    bool isDone();  
    void step(float dt);  
 
protected:  
    void RotateWithAction::setInnerAction(CCActionInterval* pAction);  
 
    cocos2d::CCNode* pInnerTarget;  
    CCActionInterval* pInnerAction;  
 
};  
#endif
