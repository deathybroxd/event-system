/* AlertSystem.cpp */

#include "subscribers/AlertSystem.h"

void AlertSystem::OnEvent(const Event& event) {
    std::cout << "[ALERT]" << event.GetType() << " | " << event.GetPayload() << " | " << event.GetTimestamp() << std::endl;
}
