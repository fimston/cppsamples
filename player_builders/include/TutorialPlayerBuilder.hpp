/*
 * Author: Bakulin Efim
 *
 */

#ifndef MODCOMBAT_INCLUDE_PLAYER_BUILDERS__TUTORIALPLAYERBUILDER_HPP
#define	MODCOMBAT_INCLUDE_PLAYER_BUILDERS__TUTORIALPLAYERBUILDER_HPP
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include "ModCombat/include/player_builders/PlayerBuilder.hpp"

namespace hv_proj
{
	class TutorialPlayerBuilder: public PlayerBuilder
	{
	public:
		virtual PlayerPtr CreatePlayer( UserId );
	};
}
#endif
