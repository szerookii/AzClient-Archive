#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class AirSwim : public Module {
public:
	AirSwim() : Module::Module("AirSwim", "Movement", "") {
		this->isEnabled = false;
	};
};