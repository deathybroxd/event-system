/* MetricsTracker.cpp */
#include "subscribers/MetricsTracker.h"

// OnEvent - increments m_eventCounts' value
void MetricsTracker::OnEvent(const Event& event) {
    m_eventCounts[event.GetType()]++;
}

// print everything in m_eventCounts
void MetricsTracker::PrintSummary() const {
    for(const auto& event : m_eventCounts) {
        std::cout << event.first << " | " << event.second << std::endl;
    }
}