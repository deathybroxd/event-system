/* Logger.h 
- inherits from ISubscriber.h
- prints all events
*/
#ifndef LOGGER_H
#define LOGGER_H
#include "ISubscriber.h"

class Logger : public ISubscriber {
public:
    Logger() = default;

    // virtual destructor - handled by ISubscriber
    virtual ~Logger() = default;
    
    // logger OnEvent just prints all the information from the event given
    void OnEvent(const Event& event) override;

};
#endif