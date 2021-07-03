#pragma once

#include "../Module.h"

class EditionFaker : public Module {
public:
	EditionFaker() : Module::Module("EditionFaker", "Misc", "") {
		this->isEnabled = true;
	};
};