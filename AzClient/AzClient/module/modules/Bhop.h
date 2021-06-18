#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class Bhop : public Module {
public:
	Bhop() : Module::Module("Bhop", "Movement", "") {
		this->isEnabled = false;
	};
	void onGmTick();
};