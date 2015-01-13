#ifndef MODCOMBAT_INCLUDE_PLAYER_BUILDERS__MORFPLAYERBUILDER_HPP
#define	MODCOMBAT_INCLUDE_PLAYER_BUILDERS__MORFPLAYERBUILDER_HPP

#include "ModCombat/include/player_builders/PlayerBuilder.hpp"
#include "ModCombat/include/players/PlayerSharedData.hpp"

namespace hv_proj
{
	template<typename T, PlayerTypes player_type> class MorfPlayerBuilder : public PlayerBuilder
	{
	public:
		MorfPlayerBuilder(T* builderPtr) : builderPtr_(builderPtr)
		{
		}

		virtual PlayerPtr CreatePlayer( UserId );

	private:
		std::unique_ptr<T> builderPtr_;
	};
}

#endif // MODCOMBAT_INCLUDE_PLAYER_BUILDERS__MORFPLAYERBUILDER_HPP
