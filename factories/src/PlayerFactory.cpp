/*
 * File:   PlayerFactory.cpp
 * Author: Bakulin Efim
 *
 * Created on June 9, 2012, 9:15 AM
 */

#include <boost/make_shared.hpp>
#include "ModCombat/include/player_builders/PlayerBuilder.hpp"
#include "ModCombat/include/player_builders/HumanPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/BotPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/MonsterPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/GolemPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/TutorialPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/BlitzTnmPlayerBuilder.hpp"
#include "ModCombat/include/player_builders/MorfPlayerBuilder.hpp"
#include "ModCombat/include/players/human/TournamentPlayer.hpp"
#include "ModCombat/include/factories/PlayerFactory.hpp"
#include "ModCombat/include/players/MorfPlayer.hpp"


namespace hv_proj
{

	PlayerFactory * PlayerFactory::self_ = NULL;
	std::mutex PlayerFactory::mutex_;

	void PlayerFactory::Init()
	{
		RegisterBuilder(PLAYER_TYPE_MAN, new HumanPlayerBuilder);
		RegisterBuilder(PLAYER_TYPE_BOT, new MorfPlayerBuilder<BotPlayerBuilder, PLAYER_TYPE_BOT>(new BotPlayerBuilder));
		RegisterBuilder(PLAYER_TYPE_MON, new MorfPlayerBuilder<MonsterPlayerBuilder, PLAYER_TYPE_MON>(new MonsterPlayerBuilder));
		RegisterBuilder(PLAYER_TYPE_GOLEM, new MorfPlayerBuilder<GolemPlayerBuilder, PLAYER_TYPE_GOLEM>(new GolemPlayerBuilder));
		RegisterBuilder(PLAYER_TYPE_BLITZ_TNM, new BlitzTnmPlayerBuilder);
		RegisterBuilder(PLAYER_TYPE_TUTORIAL, new TutorialPlayerBuilder);
	}

	void PlayerFactory::RegisterBuilder(int type, PlayerBuilder* builder)
	{
		builders_[type] = std::unique_ptr<PlayerBuilder>(builder);
	}

	PlayerPtr PlayerFactory::CreatePlayer(UserId user_id, PlayerTypes player_type)
	{

		auto it = builders_.find(player_type);
		if (it == builders_.end())
			throw core::FormattedException("Unsupported player type %1%", player_type);

		return it -> second -> CreatePlayer(user_id);
	}

	PlayerPtr PlayerFactory::CreateTournamentFighter(UserId user_id, uint8_t tnm_type)
	{
		PlayerPtr player = boost::make_shared<TournamentPlayer>(user_id, tnm_type);
		player -> Initializer();
		return player;
	}

	ViewerPtr PlayerFactory::CreateViewer(ClientPtr client)
	{
		ViewerPtr viewer = boost::make_shared<Viewer>(PlayerStatus::VIEWER);
		viewer -> SetSocket(client -> SockGet());
		return viewer;
	}

	PlayerFactory & PlayerFactory::GetInstance()
	{
		if (!self_)
		{
			std::lock_guard<std::mutex> locker(mutex_);
			if (!self_)
			{
				self_ = new PlayerFactory;
				self_ -> Init();
			}
		}
		return *self_;
	}

	PlayerFactory::PlayerFactory()
	{
	}
}
