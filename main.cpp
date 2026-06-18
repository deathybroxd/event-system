#include "EventBus.h"
#include "subscribers/Logger.h"
#include "subscribers/MetricsTracker.h"
#include "subscribers/AlertSystem.h"

int main() {
    EventBus eventBus;
    // alert version is scoped out so it outputs as intended
    {
        std::shared_ptr<AlertSystem> alerts = std::make_shared<AlertSystem>();
        eventBus.Subscribe("user_connected", std::weak_ptr<ISubscriber>(alerts));
        eventBus.Subscribe("user_packet", std::weak_ptr<ISubscriber>(alerts));
        eventBus.Subscribe("user_shutdown", std::weak_ptr<ISubscriber>(alerts));

        eventBus.Publish(std::make_unique<Event>("user_connected", "Alice joined"));
        eventBus.Publish(std::make_unique<Event>("user_packet", "ping"));
        eventBus.Publish(std::make_unique<Event>("user_shutdown", "graceful exit"));
    }

    std::shared_ptr<Logger> logger = std::make_shared<Logger>();
    std::shared_ptr<MetricsTracker> tracker = std::make_shared<MetricsTracker>();

    eventBus.Subscribe("user_connected", std::weak_ptr<ISubscriber>(logger));
    eventBus.Subscribe("user_connected", std::weak_ptr<ISubscriber>(tracker));

    eventBus.Subscribe("user_packet", std::weak_ptr<ISubscriber>(logger));
    eventBus.Subscribe("user_packet", std::weak_ptr<ISubscriber>(tracker));

    eventBus.Subscribe("user_shutdown", std::weak_ptr<ISubscriber>(logger));
    eventBus.Subscribe("user_shutdown", std::weak_ptr<ISubscriber>(tracker));

    eventBus.Publish(std::make_unique<Event>("user_connected", "Bob joined"));
    eventBus.Publish(std::make_unique<Event>("user_packet", "ping"));
    eventBus.Publish(std::make_unique<Event>("user_shutdown", "computer crashed playing fortnite"));
    eventBus.Publish(std::make_unique<Event>("user_connected", "Gerald joined"));
    eventBus.Publish(std::make_unique<Event>("user_packet", "ping"));
    eventBus.Publish(std::make_unique<Event>("user_shutdown", "power went out"));

    tracker->PrintSummary();


    return 0;
}
