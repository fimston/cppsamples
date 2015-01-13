#ifndef _BALANCE_OBSERVER_HPP_INCLUDED_
#define _BALANCE_OBSERVER_HPP_INCLUDED_

#include <boost/signals2.hpp>
#include <functional>
#include <_Types.hpp>
#include "core/Client.hpp"

namespace hv_proj
{
	class BalanceObserver
	{

	public:
		void OnUserGameBalanceChanged( core::ClientPtr pClient, double user_game_balance_changed );

		void SubscribeUserGameBalanceChanged( std::function<void(core::ClientPtr, double)> && callback );

		void OnUserEnergyChanged( core::ClientPtr pClient, int user_energy_changed, int backtimer );

		void SubscribeUserEnergyChanged( std::function<void(core::ClientPtr, int, int)> && callback );

		void OnUserRealBalanceChanged( core::ClientPtr pClient, double user_real_balance_changed );

		void SubscribeUserRealBalanceChanged( std::function<void(core::ClientPtr, double)> && callback );

	public:
		static BalanceObserver & GetInstance()
		{
			static BalanceObserver instance_;
			return instance_;
		}

	private:
		BalanceObserver();

	private:
		boost::signals2::signal< void(core::ClientPtr, double) > on_user_game_balance_changed_;
		boost::signals2::signal< void(core::ClientPtr, int, int) > on_user_energy_changed_;
		boost::signals2::signal< void(core::ClientPtr, double) > on_user_real_balance_changed_;
	};
}

#endif // _BALANCE_OBSERVER_HPP_INCLUDED_
