#include "observers/LoginObserver.hpp"
namespace hv_proj
{
	void LoginObserver::OnLogin(const ClientPtr & user)
	{
		on_user_login_(user);
	}

	void LoginObserver::SubscribeOnLogin(std::function<void(const ClientPtr &)> && callback)
	{
		on_user_login_.connect(callback);
	}

	void LoginObserver::OnInitialized(const ClientPtr & user)
	{
		on_user_initialized_(user);
	}

	void LoginObserver::SubscribeOnInitialized(std::function<void(const ClientPtr &)> && callback)
	{
		on_user_initialized_.connect(callback);
	}

	LoginObserver::LoginObserver()
	{
	}
}

