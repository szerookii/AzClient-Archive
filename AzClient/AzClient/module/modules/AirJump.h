#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class AirJump : public Module {
public:
	AirJump() : Module::Module("AirJump", "Movement", "Allows you to jump in the air") {
		this->isEnabled = true;
	};
	void onLoop();
};