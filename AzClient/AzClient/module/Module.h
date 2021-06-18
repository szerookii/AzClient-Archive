#pragma once

#include "../utils/Utils.h"
#include "../sdk/GameMode.h"
#include "../data/GameData.h"

class Module {
public:
	std::string name, category, description;
	uint64_t key;

	bool isEnabled = false, wasEnabled = false;
	Module(std::string name, std::string category, std::string description, uint64_t key = NULL);

	virtual void onLoop() {};
	virtual void onTick() {};
	virtual void onEnable() {};
	virtual void onDisable() {};

	virtual void onRender() {};
	virtual void onGmTick() {};
	virtual void onStartDestroyBlock(class Vec3_i* param_1, unsigned char param_2, bool* param_3) {};
	virtual void onKey(uint64_t key, bool isDown, bool* cancel) {};
};