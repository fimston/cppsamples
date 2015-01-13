/*
 * Author: Bakulin Efim
 *
 */

#include <boost/make_shared.hpp>
#include "ModCombat/include/player_builders/BotPlayerBuilder.hpp"
#include "ModCombat/include/players/bot/BotPlayer.hpp"

namespace hv_proj
{
	PlayerPtr BotPlayerBuilder::CreatePlayer( UserId user_id )
	{
		BotPlayerPtr player = boost::make_shared<BotPlayer>(user_id);
		player -> Initializer();
		return player;
	}
}

