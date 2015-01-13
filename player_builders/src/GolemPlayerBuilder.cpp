/*
 * Author: Bakulin Efim
 *
 */

#include <boost/make_shared.hpp>
#include "ModCombat/include/player_builders/GolemPlayerBuilder.hpp"
#include "ModCombat/include/players/bot/GolemPlayer.hpp"

namespace hv_proj
{
	PlayerPtr GolemPlayerBuilder::CreatePlayer( UserId user_id )
	{
		GolemPlayerPtr player = boost::make_shared<GolemPlayer>(user_id);
		player -> Initializer();
		return player;
	}
}

