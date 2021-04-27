#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class Step : public Module {
public:
	Step() : Module::Module("Step", "Movement", "") {
		this->isEnabled = true;
	};
	void onLoop();
};