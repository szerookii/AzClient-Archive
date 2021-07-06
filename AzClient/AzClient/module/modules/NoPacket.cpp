#include "NoPacket.h"

void NoPacket::onPacketSend(Packet* packet, bool* cancel) {
	Utils::DebugLogOutput("Cancelling a packet lol");

	*cancel = true;
}