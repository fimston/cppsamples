#include "observers/BattleObserver.hpp"

namespace hv_proj
{
	BattleObserver::BattleObserver()
	{
	}

	void BattleObserver::SubscribeBattleEntered(BattleEnteredCallback && callback)
	{
		on_enter_battle_.connect(callback);
	}

	void BattleObserver::SubscribeBattleLeft(BattleLeftCallback && callback)
	{
		on_leave_battle_.connect(callback);
	}

	void BattleObserver::SubscribeBattleRequested(BattleLeftCallback && callback)
	{
		on_request_battle_.connect(callback);
	}

	void BattleObserver::OnUserRequestedBattle(UserId user_id)
	{
		on_request_battle_(user_id);
	}

	void BattleObserver::OnUserLeftBattle(UserId user_id)
	{
		on_leave_battle_(user_id);
	}

	void BattleObserver::OnUserEnteredBattle(UserId user_id, uint64_t battle_id)
	{
		on_enter_battle_(user_id, battle_id);
	}
}
