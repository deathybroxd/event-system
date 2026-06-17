/* EventBus.h */
#ifndef EVENTBUS_H
#define EVENTBUS_H
#include "ISubscriber.h"
#include "Event.h"
#include <map>
#include <vector>
#include <memory>
#include <algorithm>

class EventBus {
public:
    // constructor/destructor not needed
    EventBus() = default;

    ~EventBus() = default;

    // Subscribe
    // takes an event type and a weak ptr to a subscriber and pushes back into the vector in m_subscribers
    void Subscribe(const std::string& eventType, std::weak_ptr<ISubscriber> subscriber);

    // Publish
    // takes ownership of an event and notifies all subscribers for that specific event type.
    // takes a unique ptr because only one singular object owns the unique ptr
    void Publish(std::unique_ptr<Event> event);

private:
    // main data structure
    // maps an event type std string as a key to a vector of weak ptrs to subscribers
    std::map<std::string, std::vector<std::weak_ptr<ISubscriber>>> m_subscribers;
};
#endif