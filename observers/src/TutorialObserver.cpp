#include "observers/TutorialObserver.hpp"
namespace hv_proj
{
	void TutorialObserver::TutorialStarted(const ClientPtr & user)
	{
		on_started_(user);
	}

	void TutorialObserver::SubscribeTutorialStarted(std::function<void(const ClientPtr &)> && callback)
	{
		on_started_.connect(callback);
	}

	void TutorialObserver::TutorialFinished(const ClientPtr & user)
	{
		on_finished_(user);
	}

	void TutorialObserver::SubscribeTutorialFinished(std::function<void(const ClientPtr &)> && callback)
	{
		on_finished_.connect(callback);
	}

	TutorialObserver::TutorialObserver()
	{
	}
}

