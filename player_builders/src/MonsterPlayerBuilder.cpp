/*
 * Author: Bakulin Efim
 *
 */

#include <boost/make_shared.hpp>
#include "ModCombat/include/player_builders/MonsterPlayerBuilder.hpp"
#include "ModCombat/include/players/bot/BotPlayer.hpp"

namespace hv_proj
{
	PlayerPtr MonsterPlayerBuilder::CreatePlayer( UserId user_id )
	{
		MonsterPlayerPtr player = boost::make_shared<MonsterPlayer>(user_id);
		player -> Initializer();
		return player;
	}
}

