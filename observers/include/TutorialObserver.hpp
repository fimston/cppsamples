#ifndef TUTORIAL_OBSERVER_HPP
#define TUTORIAL_OBSERVER_HPP

#include <boost/signals2.hpp>
#include <functional>
#include <_Types.hpp>
#include "Client.hpp"

namespace hv_proj
{
	class TutorialObserver
	{

	public:
		void TutorialStarted(const ClientPtr &);
		void TutorialFinished(const ClientPtr &);

		void SubscribeTutorialStarted(std::function<void(const ClientPtr&)> && callback);
		void SubscribeTutorialFinished(std::function<void(const ClientPtr&)> && callback);
		
	public:
		static TutorialObserver & GetInstance()
		{
			static TutorialObserver instance_;
			return instance_;
		}

	private:
		TutorialObserver();
	
	private:
		boost::signals2::signal< void(const ClientPtr&) > on_started_;
		boost::signals2::signal< void(const ClientPtr&) > on_finished_;

	};
}
#endif
