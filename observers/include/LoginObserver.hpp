#ifndef LOGIN_OBSERVER_HPP
#define LOGIN_OBSERVER_HPP

#include <boost/signals2.hpp>
#include <functional>
#include <_Types.hpp>
#include "Client.hpp"

namespace hv_proj
{
	class LoginObserver
	{

	public:
		void OnLogin(const ClientPtr &);
		void OnInitialized(const ClientPtr &);

		void SubscribeOnLogin(std::function<void(const ClientPtr&)> && callback);
		void SubscribeOnInitialized(std::function<void(const ClientPtr&)> && callback);
		
	public:
		static LoginObserver & GetInstance()
		{
			static LoginObserver instance_;
			return instance_;
		}

	private:
		LoginObserver();
	
	private:
		boost::signals2::signal< void(const ClientPtr&) > on_user_login_;
		boost::signals2::signal< void(const ClientPtr&) > on_user_initialized_;

	};
}
#endif
