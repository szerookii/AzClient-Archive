#pragma once

#include <cfloat>

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../module/ModuleManager.h"
#include "../../sdk/GameMode.h"

class GameModeHook : public Hook {
public:
	void install();
};

typedef void(__stdcall* GameMode_tick)(GameMode*);
GameMode_tick _GameMode_tick;

void hGameMode_tick(GameMode* _this) {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (_this != nullptr && player != nullptr) {
		if (player == _this->Player) {
			gData.setGameMode(_this);

			for (auto module : moduleMgr.modules) {
				if (module->isEnabled)
					module->onGmTick();
			}
		}
	}

	_GameMode_tick(_this);
}

typedef void(__stdcall* GameMode_destroyBlock)(GameMode*, class Vec3_i*, unsigned char, bool*);
GameMode_destroyBlock _GameMode_destroyBlock;

void hGameMode_destroyBlock(GameMode* _this, class Vec3_i* param_1, unsigned char param_2, bool* param_3) {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (_this != nullptr && player != nullptr) {
		if (player == _this->Player) {
			for (auto module : moduleMgr.modules) {
				if (module->isEnabled)
					module->onStartDestroyBlock(param_1, param_2, param_3);
			}
		}
	}

	_GameMode_destroyBlock(_this, param_1, param_2, param_3);
}

typedef float(__stdcall* GameMode_getPickRange)(GameMode*, __int64*, bool);
GameMode_getPickRange _GameMode_getPickRange;

float hGameMode_getPickRange(GameMode* _this, __int64* idk1, bool idk2) {
	auto reach = moduleMgr.getModuleByName("ExtendedBlockReach");

	if (reach != nullptr && reach->isEnabled) {
		return 20.f;
	}

	return _GameMode_getPickRange(_this, idk1, idk2);
}

void GameModeHook::install() {
	uintptr_t sigAddr = Utils::FindSig(xorstr_("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 8B FA 48 8B 89 ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 10 48 8B 8B"));
	
	if (!sigAddr) return;
	int offset = *reinterpret_cast<int*>(sigAddr + 3);
	uintptr_t** vtable = reinterpret_cast<uintptr_t**>(sigAddr + offset + 7);

	this->hookAddr("GameMode::startDestroyBlock", (void*)vtable[1], &hGameMode_destroyBlock, (LPVOID*)&_GameMode_destroyBlock);
	this->hookAddr("GameMode::tick", (void*)vtable[10], &hGameMode_tick, (LPVOID*)&_GameMode_tick);
	this->hookAddr("GameMode::getPickRange", (void*)vtable[11], &hGameMode_getPickRange, (LPVOID*)&_GameMode_getPickRange);
}