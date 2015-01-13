#ifndef LOCATION_OBSERVER_HPP
#define LOCATION_OBSERVER_HPP

#include <boost/signals2.hpp>
#include <functional>
#include "Location.hpp"
#include <_Types.hpp>

namespace hv_proj
{
	class LocationObserver
	{

	public:
		void OnLocationChanged(UserId user_id, const Location &);

		void SubscribeLocationChanged(std::function<void(UserId, const Location &)> && callback);
		
	public:
		static LocationObserver & GetInstance()
		{
			static LocationObserver instance_;
			return instance_;
		}

	private:
		LocationObserver();
	
	private:
		boost::signals2::signal< void(UserId, const Location&) > on_user_location_changed_;

	};
}
#endif
