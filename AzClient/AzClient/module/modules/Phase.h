#pragma once

#include "../Module.h"

class Phase : public Module {
public:
	Phase() : Module::Module("Phase", "Player", "") {
		this->isEnabled = false;
	};

	void onDisable();
	void onGmTick();
};