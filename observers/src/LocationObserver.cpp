#include "observers/LocationObserver.hpp"
namespace hv_proj
{
	void LocationObserver::OnLocationChanged(UserId user_id, const Location & location)
	{
		on_user_location_changed_(user_id, location);
	}

	void LocationObserver::SubscribeLocationChanged(std::function<void(UserId, const Location &)> && callback)
	{
		on_user_location_changed_.connect(callback);
	}

	LocationObserver::LocationObserver()
	{
	}
}

