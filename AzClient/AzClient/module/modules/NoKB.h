#pragma once

#include "../Module.h"

class NoKB : public Module {
public:
	NoKB() : Module::Module("NoKB", "Combat", "") {
		this->isEnabled = false;
	};
};