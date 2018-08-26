#ifndef _MODELEQUIPPACKET_H
#define _MODELEQUIPPACKET_H

#include <Network/GamePacketNew.h>
#include "Actor/Player.h"
#include "Forwards.h"

namespace Core {
namespace Network {
namespace Packets {
namespace Server {

/**
* @brief The update model packet.
*/
class ModelEquipPacket :
   public ZoneChannelPacket< FFXIVIpcModelEquip >
{
public:
   ModelEquipPacket( Entity::Player& player ) :
      ZoneChannelPacket< FFXIVIpcModelEquip >( player.getId(), player.getId() )
   {
      initialize( player );
   };

private:
   void initialize( Entity::Player& player )
   {
      m_data.mainWeapon = player.getModelMainWeapon();
      m_data.offWeapon = player.getModelSubWeapon();
      m_data.models[0] = player.getModelForSlot( Common::GearSetSlot::Head );
      m_data.models[1] = player.getModelForSlot( Common::GearSetSlot::Body );
      m_data.models[2] = player.getModelForSlot( Common::GearSetSlot::Hands );
      m_data.models[3] = player.getModelForSlot( Common::GearSetSlot::Legs );
      m_data.models[4] = player.getModelForSlot( Common::GearSetSlot::Feet );
   };
};

}
}
}
}

#endif /*_MODELEQUIPPACKET_H*/
