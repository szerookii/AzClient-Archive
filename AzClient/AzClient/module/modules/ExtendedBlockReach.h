#pragma once

#include "../Module.h"

class ExtendedBlockReach : public Module {
public:
	ExtendedBlockReach() : Module::Module("ExtendedBlockReach", "Player", "") {
		this->isEnabled = false;
	};
};