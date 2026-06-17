/* Event.cpp */
#include "Event.h"

// constructor
Event::Event(std::string type, std::string payload) {
    m_type = type;
    m_payload = payload;
    std::time_t currTime = std::time(nullptr);
    char buffer[80]; // this is directly from a C library thats why
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&currTime));
    m_timestamp = buffer;
}

//destructor
Event::~Event() = default;

// getters
const std::string& Event::GetType() const {
    return m_type;
}

const std::string& Event::GetPayload() const {
    return m_payload;
}

const std::string& Event::GetTimestamp() const {
    return m_timestamp;
}