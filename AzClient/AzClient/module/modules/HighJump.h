#pragma once

#include "../Module.h"

class HighJump : public Module {
public:
	HighJump() : Module::Module("HighJump", "Movement", "") {
		this->isEnabled = false;
	};
};