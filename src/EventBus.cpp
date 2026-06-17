/* EventBus.cpp */
#include "EventBus.h"

// Subscribe
// takes an event type and a weak ptr to a subscriber and pushes back into the vector in m_subscribers
void EventBus::Subscribe(const std::string& eventType, std::weak_ptr<ISubscriber> subscriber) {
    m_subscribers[eventType].push_back(subscriber);
}

// Publish
// takes ownership of an event and notifies all subscribers for that specific event type.
// takes a unique ptr because only one singular object owns the unique ptr
void EventBus::Publish(std::unique_ptr<Event> event) {
    // if a key returns end, it is a non-existant key, meaning the vector at that event is empty, immediately return
    if(m_subscribers.find(event->GetType()) == m_subscribers.end()) {
        return;
    }

    // pull the vector from m_subscribers of the event type
    std::vector<std::weak_ptr<ISubscriber>>& eventSubs = m_subscribers[event->GetType()];

    // if the converted weakptr->sharedptr to the subscribers is not null, run oneven
    for(size_t i = 0; i < eventSubs.size(); ++i) {
        std::shared_ptr<ISubscriber> sharedPtr = eventSubs.at(i).lock(); // .lock() converts weak ptrs into shared ptrs
        if(sharedPtr != nullptr) {
            sharedPtr->OnEvent(*event);
        }
        
    }
    
    // prune weak ptrs
    eventSubs.erase(
        // std::remove_if takes in a range, and a lambda to know what to delete
        std::remove_if(eventSubs.begin(), eventSubs.end(), 
        // lambda that returns if a weakptr has expired
        [](const std::weak_ptr<ISubscriber>& weakPtr) {return weakPtr.expired();}
    ), eventSubs.end());
}