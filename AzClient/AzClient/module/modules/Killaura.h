#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"
#include "../../sdk/MultiPlayerLevel.h"

class Killaura : public Module {
public:
	Killaura() : Module::Module("Killaura", "Combat", "", 0x46) {
		this->isEnabled = false;
	};
	void onGmTick();

	int tick = 0;
};