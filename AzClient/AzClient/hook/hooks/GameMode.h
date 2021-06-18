#pragma once

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../module/ModuleManager.h"
#include "../../sdk/GameMode.h"

class GameModeHook : public Hook {
public:
	void install();
};

typedef void(__stdcall* GmTick)(GameMode*);
GmTick _GmTick;

void GmTick_callback(GameMode* _this) {
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

	_GmTick(_this);
}

typedef void(__stdcall* GmStartDestroyBlock)(GameMode*, class Vec3_i*, unsigned char, bool*);
GmStartDestroyBlock _GmStartDestroyBlock;

void GmStartDestroyBlock_callback(GameMode* _this, class Vec3_i* param_1, unsigned char param_2, bool* param_3) {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (_this != nullptr && player != nullptr) {
		if (player == _this->Player) {
			for (auto module : moduleMgr.modules) {
				if (module->isEnabled)
					module->onStartDestroyBlock(param_1, param_2, param_3);
			}
		}
	}

	_GmStartDestroyBlock(_this, param_1, param_2, param_3);
}

void GameModeHook::install() {
	uintptr_t sigAddr = Utils::FindSig(xorstr_("48 8D 05 ? ? ? ? 48 8B D9 48 89 01 8B FA 48 8B 89 ? ? ? ? 48 85 C9 74 ? 48 8B 01 BA ? ? ? ? FF 10 48 8B 8B"));
	
	if (!sigAddr) return;
	int offset = *reinterpret_cast<int*>(sigAddr + 3);
	uintptr_t** vtable = reinterpret_cast<uintptr_t**>(sigAddr + offset + 7);

	this->hookAddr("GameMode::tick", (void*)vtable[10], &GmTick_callback, reinterpret_cast<LPVOID*>(&_GmTick));
	this->hookAddr("GameMode::startDestroyBlock", (void*)vtable[1], &GmStartDestroyBlock_callback, reinterpret_cast<LPVOID*>(&_GmStartDestroyBlock));
}