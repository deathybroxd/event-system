/*
AlertSystem.h
- inherits from ISubscriber
*/

#ifndef ALERTSYSTEM_H
#define ALERTSYSTEM_H
#include "ISubscriber.h"

class AlertSystem : public ISubscriber {
public:
    // constructor
    AlertSystem() = default;

    // virtual destructor
    virtual ~AlertSystem() = default;

    void OnEvent(const Event& event) override;
};
#endif