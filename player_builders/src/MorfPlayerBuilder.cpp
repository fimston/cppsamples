#include <boost/make_shared.hpp>
#include "ModCombat/include/player_builders/MorfPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/BotPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/MonsterPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/GolemPlayerBuilder.hpp"
#include "ModCombat/include/players/MorfPlayer.hpp"
#include "ModCombat/include/controllers/GameController.hpp"

namespace hv_proj
{
	template<typename T, PlayerTypes player_type> PlayerPtr MorfPlayerBuilder<T, player_type>::CreatePlayer( UserId user_id )
	{
		if (GameController::GetInstance()->getDict()->IsMorfPlayer(user_id))
		{
			MorfPlayerPtr morf_player = boost::make_shared<MorfPlayer>(user_id, player_type);
			morf_player -> Initializer();

			return morf_player;
		}
		return builderPtr_ -> CreatePlayer(user_id);
	}

	template class MorfPlayerBuilder<BotPlayerBuilder, PLAYER_TYPE_BOT>;
	template class MorfPlayerBuilder<MonsterPlayerBuilder, PLAYER_TYPE_MON>;
	template class MorfPlayerBuilder<GolemPlayerBuilder, PLAYER_TYPE_GOLEM>;
}
