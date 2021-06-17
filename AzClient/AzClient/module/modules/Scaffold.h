#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"
#include "../../sdk/GameMode.h"
#include "../../sdk/ItemStack.h"

class Scaffold : public Module {
public:
	Scaffold() : Module::Module("Scaffold", "World", "") {
		this->isEnabled = false;
	};
	void onGmTick();
};