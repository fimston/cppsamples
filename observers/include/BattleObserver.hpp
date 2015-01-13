#ifndef BATTLE_OBSERVER_HPP
#define BATTLE_OBSERVER_HPP

#include <boost/signals2.hpp>
#include <functional>
#include <_Types.hpp>

namespace hv_proj
{
	class BattleObserver
	{

	public:
		typedef std::function< void(UserId, uint64_t) > BattleEnteredCallback;
		typedef std::function< void(UserId) > BattleLeftCallback;
		typedef std::function< void(UserId) > BattleRequestedCallback;
	public:
		void OnUserEnteredBattle(UserId user_id, uint64_t battle_id);
		void OnUserRequestedBattle(UserId user_id);
		void OnUserLeftBattle(UserId user_id);

		void SubscribeBattleEntered(BattleEnteredCallback && callback);
		void SubscribeBattleLeft(BattleLeftCallback && callback);
		void SubscribeBattleRequested(BattleRequestedCallback && callback);

	public:
		static BattleObserver & GetInstance()
		{
			static BattleObserver instance_;
			return instance_;
		}

	private:
		BattleObserver();
	
	private:
		boost::signals2::signal< void(UserId, int64_t) > on_enter_battle_;
		boost::signals2::signal< void(UserId) > on_leave_battle_;
		boost::signals2::signal< void(UserId) > on_request_battle_;

	};
}
#endif
