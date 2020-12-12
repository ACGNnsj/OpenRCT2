/*****************************************************************************
 * Copyright (c) 2014-2020 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "PlayerSetGroupAction.h"

#include "../network/network.h"

void PlayerSetGroupAction::Serialise(DataSerialiser& stream)
{
    GameAction::Serialise(stream);

    stream << DS_TAG(_playerId) << DS_TAG(_groupId);
}
GameActions::Result::Ptr PlayerSetGroupAction::Query() const
{
    return network_set_player_group(GetPlayer(), _playerId, _groupId, false);
}

GameActions::Result::Ptr PlayerSetGroupAction::Execute() const
{
    return network_set_player_group(GetPlayer(), _playerId, _groupId, true);
}