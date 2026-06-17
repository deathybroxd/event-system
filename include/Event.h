/* Event.h */

#ifndef EVENT_H
#define EVENT_H
#include <string>
#include <ctime>

class Event {
public:
    // constructor
    Event(std::string type, std::string payload);

    ~Event() = default;

    // getters
    const std::string& GetType() const;

    const std::string& GetPayload() const;

    const std::string& GetTimestamp() const;

private:
    std::string m_type;
    std::string m_payload;
    std::string m_timestamp;
};
#endif