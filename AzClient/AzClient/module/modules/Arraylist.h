#pragma once

#include "../Module.h"
#include "../ModuleManager.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class Arraylist : public Module {
public:
	Arraylist() : Module::Module("Arraylist", "Visuals", "") {
		this->isEnabled = true;
	};
	void onRender();
};