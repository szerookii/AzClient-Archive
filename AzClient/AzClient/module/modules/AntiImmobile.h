#pragma once

#include "../Module.h"

class AntiImmobile : public Module {
public:
	AntiImmobile() : Module::Module("AntiImmobile", "Player", "") {
		this->isEnabled = false;
	};
};