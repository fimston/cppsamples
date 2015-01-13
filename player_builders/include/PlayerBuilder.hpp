/*
 * Author: Bakulin Efim
 *
 * Created on June 8, 2012, 6:10 PM
 */

#ifndef MODCOMBAT_INCLUDE_PLAYER_BUILDERS__PLAYERBUILDER_HPP
#define	MODCOMBAT_INCLUDE_PLAYER_BUILDERS__PLAYERBUILDER_HPP
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include "ModCombat/include/forward_typedefs.hpp"

namespace hv_proj
{
	class PlayerBuilder
	{
	public:
		virtual PlayerPtr CreatePlayer( UserId ) = 0;
	};
}
#endif
