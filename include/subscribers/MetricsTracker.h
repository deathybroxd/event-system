/* 
MetricsTracker.h 
- inherits from ISubscriber.h
- tracks metrics
*/

#ifndef METRICSTRACKER_H
#define METRICSTRACKER_H
#include "ISubscriber.h"
#include <map>

class MetricsTracker : public ISubscriber {
public:
    // constructor
    MetricsTracker() = default;

    // virtual destructor
    virtual ~MetricsTracker() = default;

    // MetricsTracker OnEvent()
    // increments the count for the specific event type
    void OnEvent(const Event& event) override;

    // prints all event types and their counts
    void PrintSummary() const;

private:
    // tracks an event and the amount of times it occurred
    std::map<std::string, int> m_eventCounts;
};


#endif