#include "ModuleManager.h"

#include "modules/AirJump.h"
#include "modules/AutoSprint.h"
#include "modules/Killaura.h"
#include "modules/Step.h"

ModuleManager moduleMgr;

void ModuleManager::init() {
	modules.push_back(new AirJump());
	modules.push_back(new AutoSprint());
	modules.push_back(new Killaura());
	modules.push_back(new Step());

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