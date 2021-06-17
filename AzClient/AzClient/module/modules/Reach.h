#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"
#include "../../sdk/MultiPlayerLevel.h"

class Reach : public Module {
public:
	Reach() : Module::Module("Reach", "Combat", "") {
		this->isEnabled = false;
	};
	void onEnable();
	void onDisable();
	void onGmTick();

	float reachValue = 3;
	float originalReach = 0;
	float* reachPtr = nullptr;
	unsigned long oldProtect = 0;
};