#include "observers/DuelObserver.hpp"

namespace hv_proj
{
	void DuelObserver::OnUserStateChanged(UserId user_id, int flags)
	{
		on_user_state_changed_(user_id, flags);
	}

	void DuelObserver::SubscribeUserStateChanged(std::function<void(UserId, int)> && callback)
	{
		on_user_state_changed_.connect(callback);
	}

	void DuelObserver::OnDuelDeclared(UserId attacker, UserId defender)
	{
		on_duel_declared_(attacker, defender);
	}

	void DuelObserver::SubscribeDuelDeclared(std::function<void(UserId, UserId)> && callback)
	{
		on_duel_declared_.connect(callback);
	}

	DuelObserver::DuelObserver()
	{
	}
}
