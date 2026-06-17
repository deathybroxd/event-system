/* 
ISubscriber.h 
Subscriber Interface
- Pure abstract class
- NO driver file
*/
#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H
#include "Event.h"

class ISubscriber {
public:
    // virtual destructor
    virtual ~ISubscriber() = default; // same as brace{} initialization

    // pure virtual OnEvent
    virtual void OnEvent(const Event&) = 0;

};



#endif