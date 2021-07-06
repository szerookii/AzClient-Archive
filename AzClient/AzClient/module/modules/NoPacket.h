#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class NoPacket : public Module {
public:
	NoPacket() : Module::Module("NoPacket", "Misc", "") {
		this->isEnabled = false;
	};
	void onPacketSend(Packet* packet, bool* cancel);
};