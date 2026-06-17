#include "subscribers/Logger.h"

void Logger::OnEvent(const Event& event) {
    std::cout << event.GetType() << " | " << event.GetPayload() << " | " << event.GetTimestamp() << std::endl;
}