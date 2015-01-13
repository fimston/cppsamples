#include "observers/TournamentObserver.hpp"

namespace hv_proj
{
	void TournamentObserver::OnTournamentFinished(TournamentObserver::TournamentType tournament_type)
	{
		on_tournament_finished_(tournament_type);
	}

	void TournamentObserver::SubscribeTournamentFinished(std::function<void(TournamentObserver::TournamentType)> && callback)
	{
		on_tournament_finished_.connect(callback);
	}

	TournamentObserver::TournamentObserver()
	{
	}
}
