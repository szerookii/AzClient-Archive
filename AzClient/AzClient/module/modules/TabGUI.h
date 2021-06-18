#pragma once

#include "../Module.h"
#include "../ModuleManager.h"
#include "../../data/GameData.h"
#include "../../utils/Utils.h"
#include "../../sdk/LocalPlayer.h"

class TabGUI : public Module {
public:
	TabGUI() : Module::Module("TabGUI", "Visuals", "", VK_TAB) {
		this->isEnabled = true;
	};
	void onRender();
	void onKey(uint64_t key, bool isDown, bool* cancel);

private:
	int currentCategory = 0, currentModule = 0;
	bool selectedCategory = false, selectedModule = 0;
};