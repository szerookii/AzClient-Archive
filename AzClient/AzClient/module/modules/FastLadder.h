#pragma once

#include "../Module.h"

class FastLadder : public Module {
public:
	FastLadder() : Module::Module("FastLadder", "Movement", "") {
		this->isEnabled = false;
	};
};