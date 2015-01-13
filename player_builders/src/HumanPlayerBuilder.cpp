/*
 * Author: Bakulin Efim
 *
 */

#include <boost/make_shared.hpp>
#include "ModCombat/include/player_builders/HumanPlayerBuilder.hpp"
#include "ModCombat/include/factories/PlayerFactory.hpp"
#include "ModCombat/include/players/human/HumanPlayer.hpp"
#include "ModCombat/include/players/bot/BotPlayer.hpp"

namespace hv_proj
{
	PlayerPtr HumanPlayerBuilder::CreatePlayer( UserId user_id )
	{
		HumanPlayerPtr player = boost::make_shared<HumanPlayer>(user_id);
		player -> Initializer();
		if (player -> PetId())
		{
			auto pet = PlayerFactory::GetInstance().CreatePlayer(player -> PetId(), PLAYER_TYPE_BOT);
			player -> SetPet(boost::dynamic_pointer_cast<BotPlayer>(pet));
		}
		return player;
	}
}

