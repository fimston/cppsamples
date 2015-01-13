/*
 * File:   BattleFactory.cpp
 * Author: Bakulin Efim
 *
 * Created on June 9, 2012, 9:15 AM
 */

#include <boost/make_shared.hpp>
#include "ModCombat/include/battle/Battle.hpp"
#include "ModCombat/include/factories/BattleFactory.hpp"
#include "ModCombat/include/factories/PlayerFactory.hpp"
#include "ModCombat/include/battle/singleplayer/ArenaBattle.hpp"
#include "ModCombat/include/battle/singleplayer/MonsterBattle.hpp"
#include "ModCombat/include/battle/singleplayer/TournamentBattle.hpp"
#include "ModCombat/include/battle/singleplayer/BlitzTournamentBattle.hpp"
#include "ModCombat/include/controllers/GameController.hpp"
#include "ModCombat/include/battle/multiplayer/ClanBattle.hpp"
#include "ModCombat/include/battle/singleplayer/TutorialBattle.hpp"
#include "ModCombat/include/battle/singleplayer/DuelBattle.hpp"
#include "ModCombat/include/players/MorfPlayer.hpp"
namespace hv_proj
{
	void BattleFactory::EvaluateFirstTurn(PlayerPtr & player1, PlayerPtr & player2)
	{
		//Игрок ходит первым, если у него больше удача.
		//В противном случае ход определяется (псевдо)случайным образом
		if	(player2 -> Skills().Luck() > player1 -> Skills().Luck())
		{
			std::swap(player1, player2);
		}
		else
		{
			if (player2 -> Skills().Luck() == player1 -> Skills().Luck())
			{
				RandomizePlayers(player1, player2);
			}
		}
	}

	void BattleFactory::RandomizePlayers(PlayerPtr & player1, PlayerPtr & player2)
	{
		if (Random(100) > 50)
			std::swap(player1, player2);

	}

	BattlePtr const BattleFactory::CreateDuelBattle(UserId player1_id, UserId player2_id)
	{
		PlayerPtr player1 = PlayerFactory::GetInstance().CreatePlayer( player1_id, PLAYER_TYPE_MAN);
		PlayerPtr player2 = PlayerFactory::GetInstance().CreatePlayer( player2_id, PLAYER_TYPE_MAN);
		EvaluateFirstTurn(player1, player2);
		TeamControllerPtr team = boost::make_shared<TeamController>(player1, player2);
		BattlePtr battle = boost::make_shared<DuelBattle>(std::move(team));
		battle -> StartBattle();
		return battle;
	}

	BattlePtr const BattleFactory::CreateArenaBattle(UserId player1_id, PlayerTypes player1_type, UserId player2_id, PlayerTypes player2_type)
	{
		PlayerPtr player1 = PlayerFactory::GetInstance().CreatePlayer( player1_id, player1_type );
		PlayerPtr player2 = PlayerFactory::GetInstance().CreatePlayer( player2_id, player2_type );
		if ((PLAYER_TYPE_BOT == player1_type)||(PLAYER_TYPE_BOT == player1_type))
			RandomizePlayers(player1, player2);
		else
			EvaluateFirstTurn(player1, player2);
		TeamControllerPtr team = boost::make_shared<TeamController>(player1, player2);
		BattlePtr battle = boost::make_shared<ArenaBattle>(std::move(team));
		battle -> StartBattle();
		return battle;
	}

	BattlePtr const BattleFactory::CreateMonsterBattle(UserId player_id, UserId monster_id, UserId isle_owner_id)
	{
		PlayerPtr player1 = PlayerFactory::GetInstance().CreatePlayer( player_id, PLAYER_TYPE_MAN );
		PlayerPtr player2 = PlayerFactory::GetInstance().CreatePlayer( monster_id, PLAYER_TYPE_MON );
		FirstTurnAlgorithms first_turn_alg = FirstTurnAlgorithms::RANDOM_TURN;
		if (boost::dynamic_pointer_cast<MonsterPlayer>(player2))
			first_turn_alg = boost::dynamic_pointer_cast<MonsterPlayer>(player2) -> FirstTurnAlgorithm();
		else
			first_turn_alg = boost::dynamic_pointer_cast<MorfPlayer>(player2) -> FirstTurnAlgorithm();

		switch(first_turn_alg)
		{
			case FirstTurnAlgorithms::ALWAYS_FIRST_TURN:
			{
				std::swap(player1, player2);
				break;
			}
			case FirstTurnAlgorithms::ALWAYS_SECOND_TURN:
				break;
			case FirstTurnAlgorithms::USE_LUCK:
			{
				EvaluateFirstTurn(player1, player2);
				break;
			}
			case FirstTurnAlgorithms::RANDOM_TURN:
			{
				RandomizePlayers(player1, player2);
				break;
			}
		}
		TeamControllerPtr team = boost::make_shared<TeamController>(player1, player2);
		BattlePtr battle = boost::make_shared<MonsterBattle>(std::move(team), isle_owner_id);
		battle -> StartBattle();
		return battle;
	}

	BattlePtr const BattleFactory::CreateTournamentBattle(UserId player1_id, UserId player2_id, uint32_t tournament_type)
	{
		PlayerPtr player1 = PlayerFactory::GetInstance().CreateTournamentFighter( player1_id, tournament_type );
		PlayerPtr player2 = PlayerFactory::GetInstance().CreateTournamentFighter( player2_id, tournament_type );
		RandomizePlayers(player1, player2);
		TeamControllerPtr team = boost::make_shared<TeamController>(player1, player2);
		BattlePtr battle = boost::make_shared<TournamentBattle>(std::move(team), tournament_type);
		battle -> StartBattle();
		return battle;
	}


	BattlePtr const BattleFactory::CreateBlitzTournamentBattle(UserId player1_id, UserId player2_id)
	{
		PlayerPtr player1 = PlayerFactory::GetInstance().CreatePlayer( player1_id, PLAYER_TYPE_BLITZ_TNM );
		PlayerPtr player2 = PlayerFactory::GetInstance().CreatePlayer( player2_id, PLAYER_TYPE_BLITZ_TNM );
		RandomizePlayers(player1, player2);
		TeamControllerPtr team = boost::make_shared<TeamController>(player1, player2);
		BlitzTournamentBattlePtr battle = boost::make_shared<BlitzTournamentBattle>(std::move(team));
		return battle;
	}

	BattlePtr const BattleFactory::CreateClanBattle(
                        UserId attacker_golem_id,
                        UserId defender_golem_id,
                        uint32_t war_id,
                        uint32_t battle_timeout)
	{
		GolemPlayerPtr attacker_golem = boost::dynamic_pointer_cast<GolemPlayer>(PlayerFactory::GetInstance().CreatePlayer(attacker_golem_id, PLAYER_TYPE_GOLEM));
		GolemPlayerPtr defender_golem = boost::dynamic_pointer_cast<GolemPlayer>(PlayerFactory::GetInstance().CreatePlayer(defender_golem_id, PLAYER_TYPE_GOLEM));
		ClanId attacker_clan_id = attacker_golem -> GetClanId();
		ClanId defender_clan_id = defender_golem -> GetClanId();
		EvaluateFirstTurn((PlayerPtr &)attacker_golem, (PlayerPtr &)defender_golem);
		BattlePtr battle = boost::make_shared<ClanBattle>(attacker_golem, defender_golem, attacker_clan_id, defender_clan_id, battle_timeout, war_id);
		battle -> StartBattle();
		return battle;
	}

	BattlePtr const BattleFactory::CreateTutorialBattle( UserId player_id, UserId monster_id )
	{
		PlayerPtr player1 = PlayerFactory::GetInstance().CreatePlayer( player_id, PLAYER_TYPE_TUTORIAL );
		PlayerPtr player2 = PlayerFactory::GetInstance().CreatePlayer( monster_id, PLAYER_TYPE_MON );
		TeamControllerPtr team = boost::make_shared<TeamController>(player1, player2);
		BattlePtr battle = boost::make_shared<TutorialBattle>(std::move(team));
		return battle;
	}

	BattleFactory::BattleFactory()
	{
	}

	BattleFactory::~BattleFactory()
	{
	}

}
