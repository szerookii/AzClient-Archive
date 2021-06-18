#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class Aimbot : public Module {
public:
	Aimbot() : Module::Module("Aimbot", "Combat", "") {
		this->isEnabled = false;
	};
	void onGmTick();
};