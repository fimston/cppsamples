#ifndef TOURNAMENT_OBSERVER_HPP
#define TOURNAMENT_OBSERVER_HPP

#include <boost/signals2.hpp>
#include <functional>
#include <_Types.hpp>

namespace hv_proj
{
	class TournamentObserver
	{
	typedef uint32_t TournamentType;
	public:
		void OnTournamentFinished(TournamentType);
		void SubscribeTournamentFinished(std::function<void(TournamentType)> && callback);
		
	public:
		static TournamentObserver & GetInstance()
		{
			static TournamentObserver instance_;
			return instance_;
		}

	private:
		TournamentObserver();
	
	private:
		boost::signals2::signal< void(TournamentType) > on_tournament_finished_;
	};
}
#endif
