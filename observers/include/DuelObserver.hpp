#ifndef DUEL_OBSERVER_HPP
#define DUEL_OBSERVER_HPP

#include <boost/signals2.hpp>
#include <functional>
#include <_Types.hpp>

namespace hv_proj
{
	class DuelObserver
	{

	public:
		void OnUserStateChanged(UserId user_id, int flags);

		void SubscribeUserStateChanged(std::function<void(UserId, int)> && callback);
		
		void OnDuelDeclared(UserId, UserId);
		void SubscribeDuelDeclared(std::function<void(UserId, UserId)> && callback);
		
	public:
		static DuelObserver & GetInstance()
		{
			static DuelObserver instance_;
			return instance_;
		}

	private:
		DuelObserver();
	
	private:
		boost::signals2::signal< void(UserId, int) > on_user_state_changed_;
		boost::signals2::signal< void(UserId, UserId) > on_duel_declared_;

	};
}
#endif
