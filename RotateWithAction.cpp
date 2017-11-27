#include "RotateWithAction.h"
#include "StaticData.h"
USING_NS_CC;

RotateWithAction::~RotateWithAction()  
{  
    CC_SAFE_RELEASE(pInnerAction);  
}  
 
RotateWithAction* RotateWithAction::create(CCActionInterval* pAction)  
{  
    RotateWithAction* action = new RotateWithAction();  
    if (action && action->initWithAction(pAction))  
    {  
        action->autorelease();  
        return action;  
    }  
    CC_SAFE_DELETE(action);  
    return NULL;  
}  
 
bool RotateWithAction::initWithAction(CCActionInterval* pAction)  
{  
    pAction->retain();  
    pInnerAction = pAction;  
    return true;  
}  
 
void RotateWithAction::startWithTarget(CCNode* pTarget)  
{  
    pInnerTarget = pTarget;  
    CCAction::startWithTarget(pTarget);  
    pInnerAction->startWithTarget(pTarget);  
}  
 
bool RotateWithAction::isDone()  
{  
    return pInnerAction->isDone();  
}  
 
void RotateWithAction::step(float dt)  
{  
    CCPoint prePos = pInnerTarget->getPosition();  
    pInnerAction->step(dt);  
    CCPoint curPos = pInnerTarget->getPosition();  
 
    float tan = -(curPos.y - prePos.y) / (curPos.x - prePos.x);  
    float degree = atan(tan);  
    degree = degree / 3.14159f * 180;  
    if(curPos.x>prePos.x){
    pInnerTarget->setRotation(degree);  
	}
	else{
	pInnerTarget->setRotation(degree+180); 
	}

}  
 
void RotateWithAction::setInnerAction(CCActionInterval* pAction)  
{  
    if (pInnerAction != pAction)  
    {  
        CC_SAFE_RELEASE(pInnerAction);  
        pInnerAction = pAction;  
        CC_SAFE_RETAIN(pInnerAction);  
    }  
}  
 
CCObject* RotateWithAction::copyWithZone(CCZone* pZone)  
{  
    CCZone* pNewZone = NULL;  
    RotateWithAction* pCopy = NULL;  
    if(pZone && pZone->m_pCopyObject)   
    {  
        pCopy = (RotateWithAction*)(pZone->m_pCopyObject);  
    }  
    else  
    {  
        pCopy = new RotateWithAction();  
        pZone = pNewZone = new CCZone(pCopy);  
    }  
 
    CCActionInterval::copyWithZone(pZone);  
 
    pCopy->initWithAction(dynamic_cast<CCActionInterval*> 
        (pInnerAction->copy()->autorelease()));  
 
    CC_SAFE_DELETE(pNewZone);  
    return pCopy;  
}  