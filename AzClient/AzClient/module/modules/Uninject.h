#pragma once

#include "../Module.h"
#include "../../utils/Utils.h"

class Uninject : public Module {
public:
	Uninject() : Module::Module("Uninject", "Misc", "") {
		this->isEnabled = false;
	};
	void onEnable();
};