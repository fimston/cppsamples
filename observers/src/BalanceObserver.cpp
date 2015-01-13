#include "observers/BalanceObserver.hpp"

namespace hv_proj
{
	using namespace core;

	void BalanceObserver::OnUserGameBalanceChanged( ClientPtr pClient, double user_game_balance_changed )
	{
		on_user_game_balance_changed_(pClient, user_game_balance_changed);
	}

	void BalanceObserver::SubscribeUserGameBalanceChanged( std::function<void(ClientPtr, double)> && callback )
	{
		on_user_game_balance_changed_.connect(callback);
	}

	void BalanceObserver::OnUserEnergyChanged( ClientPtr pClient, int user_energy_changed, int backtimer )
	{
		on_user_energy_changed_(pClient, user_energy_changed, backtimer);
	}

	void BalanceObserver::SubscribeUserEnergyChanged( std::function<void(ClientPtr, int, int)> && callback )
	{
		on_user_energy_changed_.connect(callback);
	}

	void BalanceObserver::OnUserRealBalanceChanged( ClientPtr pClient, double user_real_balance_changed )
	{
		on_user_real_balance_changed_(pClient, user_real_balance_changed);
	}

	void BalanceObserver::SubscribeUserRealBalanceChanged( std::function<void(ClientPtr, double)> && callback )
	{
		on_user_real_balance_changed_.connect(callback);
	}

	BalanceObserver::BalanceObserver()
	{
	}
}
