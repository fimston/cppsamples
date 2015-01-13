/*
 * Author: Bakulin Efim
 *
 */

#include "ModCombat/include/player_builders/BlitzTnmPlayerBuilder.hpp"
#include "ModCombat/include/players/human/BlitzTournamentPlayer.hpp"
#include <boost/make_shared.hpp>

namespace hv_proj
{
	PlayerPtr BlitzTnmPlayerBuilder::CreatePlayer( UserId user_id )
	{
		auto player = boost::make_shared<BlitzTournamentPlayer>(user_id);
		player -> Initializer();
		return player;
	}
}

