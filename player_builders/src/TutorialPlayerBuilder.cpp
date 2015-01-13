/*
 * Author: Bakulin Efim
 *
 */

#include <boost/make_shared.hpp>
#include "ModCombat/include/player_builders/TutorialPlayerBuilder.hpp"
#include "ModCombat/include/players/human/TutorialPlayer.hpp"

namespace hv_proj
{
	PlayerPtr TutorialPlayerBuilder::CreatePlayer( UserId user_id )
	{
		TutorialPlayerPtr player = boost::make_shared<TutorialPlayer>(user_id);
		player -> Initializer();
		return player;
	}
}

