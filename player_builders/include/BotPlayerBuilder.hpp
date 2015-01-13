/*
 * Author: Bakulin Efim
 *
 * Created on June 8, 2012, 6:10 PM
 */

#ifndef MODCOMBAT_INCLUDE_PLAYER_BUILDERS__BOTPLAYERBUILDER_HPP
#define	MODCOMBAT_INCLUDE_PLAYER_BUILDERS__BOTPLAYERBUILDER_HPP
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include "ModCombat/include/player_builders/PlayerBuilder.hpp"

namespace hv_proj
{
	class BotPlayerBuilder: public PlayerBuilder
	{
	public:
		virtual PlayerPtr CreatePlayer( UserId );
	};
}
#endif
