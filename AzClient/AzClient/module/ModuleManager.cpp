#include "ModuleManager.h"

#include "modules/Aimbot.h"
#include "modules/AntiImmobile.h"
#include "modules/AirJump.h"
#include "modules/AirSwim.h"
#include "modules/Arraylist.h"
#include "modules/AutoSprint.h"
#include "modules/Bhop.h"
#include "modules/EditionFaker.h"
#include "modules/ExtendedBlockReach.h"
#include "modules/FastLadder.h"
#include "modules/HighJump.h"
#include "modules/Instabreak.h"
#include "modules/Killaura.h"
#include "modules/NoKB.h"
#include "modules/Reach.h"
#include "modules/Scaffold.h"
#include "modules/Step.h"
#include "modules/TabGUI.h"
#include "modules/Uninject.h"

ModuleManager moduleMgr;

void ModuleManager::init() {
	modules.push_back(new Aimbot());
	modules.push_back(new AntiImmobile());
	modules.push_back(new AirJump());
	modules.push_back(new AirSwim());
	modules.push_back(new Arraylist());
	modules.push_back(new AutoSprint());
	modules.push_back(new Bhop());
	modules.push_back(new EditionFaker());
	//modules.push_back(new ExtendedBlockReach());
	modules.push_back(new FastLadder());
	modules.push_back(new HighJump());
	modules.push_back(new Instabreak());
	modules.push_back(new Killaura());
	modules.push_back(new NoKB());
	//modules.push_back(new Reach());
	modules.push_back(new Scaffold());
	modules.push_back(new Step());
	modules.push_back(new TabGUI());
	modules.push_back(new Uninject());

	for (int i = 0; i < modules.size(); i++) {
		bool exists = false;

		for (auto currCategory : categories) {
			if (currCategory == modules.at(i)->category)
				exists = true;
		}

		if (!exists) {
			categories.push_back(modules.at(i)->category);
		}
	}

	while(Utils::running) {
		for (int i = 0; i < modules.size(); i++) {
			modules.at(i)->onLoop();
		}
	}
}

class Module* ModuleManager::getModuleByName(std::string name) {
	for (auto Module : modules) {
		if (Module->name == name) {
			return Module;
		}
	}

	return nullptr;
}

std::vector<class Module*> ModuleManager::getModulesFromCategory(std::string Category) {
	bool exists = false;
	for (auto Curr : categories) {
		if (Curr == Category)
			exists = true;
	}

	if (exists) {
		std::vector<Module*> modulesArr;

		for (auto Module : modules) {
			if (Module->category == Category)
				modulesArr.push_back(Module);
		}

		return modulesArr;
	}
	else {
		return std::vector<Module*>();
	}
}