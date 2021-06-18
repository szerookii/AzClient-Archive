#pragma once

#include "../Module.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class Instabreak : public Module {
public:
	Instabreak() : Module::Module("Instabreak", "World", "") {
		this->isEnabled = false;
	};
	void onStartDestroyBlock(class Vec3_i* param_1, unsigned char param_2, bool* param_3);
};