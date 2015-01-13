/*
 * File:   PlayerFactory.hpp
 * Author: Bakulin Efim
 *
 * Created on June 8, 2012, 6:10 PM
 */

#ifndef MODCOMBAT_INCLUDE_PLAYER_PLAYERFACTORY_HPP
#define	MODCOMBAT_INCLUDE_PLAYER_PLAYERFACTORY_HPP
#include <map>
#include <mutex>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include "Client.hpp"
#include "ModCombat/include/forward_typedefs.hpp"
#include "ModCombat/include/players/Player.hpp"


namespace hv_proj
{
	class PlayerBuilder;
	class PlayerFactory
	{
	public:
		static PlayerFactory & GetInstance();

	public:
		PlayerPtr CreatePlayer( UserId user_id, PlayerTypes player_type );
		PlayerPtr CreateTournamentFighter( UserId user_id, uint8_t tnm_type );
		ViewerPtr CreateViewer( ClientPtr client );

	private:
		PlayerFactory();
		void Init();
		void RegisterBuilder(int, PlayerBuilder*);

	private:
		static PlayerFactory *self_;
		static std::mutex mutex_;

	private:
		std::map< int, std::unique_ptr<PlayerBuilder> > builders_;
		
	};
}
#endif
