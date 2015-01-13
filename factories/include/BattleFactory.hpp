/*
 * File:   BattleFactory.hpp
 * Author: Bakulin Efim
 *
 * Created on June 9, 2012, 9:15 AM
 */

#ifndef BATTLEFACTORY_HPP
#define	BATTLEFACTORY_HPP
#include "ModCombat/include/forward_typedefs.hpp"
#include <boost/noncopyable.hpp>
#include "ModCombat/include/players/Player.hpp"
namespace hv_proj
{
	class Battle;

	class BattleFactory: public boost::noncopyable
	{
	public:
		static void RandomizePlayers(PlayerPtr & player1, PlayerPtr & player2);
		static void EvaluateFirstTurn(PlayerPtr & player1, PlayerPtr & player2);
		static BattlePtr const CreateArenaBattle( UserId player1_id, PlayerTypes player1_type,
						UserId player2_id, PlayerTypes player2_type);
		static BattlePtr const CreateMonsterBattle( UserId player_id, UserId monster_id, UserId isle_owner_id);
		static BattlePtr const CreateTournamentBattle ( UserId player1_id, UserId player2_id,
										uint32_t tournament_type);

		static BattlePtr const CreateDuelBattle ( UserId player1_id, UserId player2_id );
		static BattlePtr const CreateBlitzTournamentBattle ( UserId player1_id, UserId player2_id);
		static BattlePtr const CreateClanBattle(
                        UserId attacker_golem_id,
                        UserId defender_golem_id,
                        uint32_t war_id,
                        uint32_t battle_timeout);

		static BattlePtr const CreateTutorialBattle( UserId player_id, UserId monster_id );
	public:
		virtual ~BattleFactory( );
	private:
		BattleFactory( );

	};
}
#endif
