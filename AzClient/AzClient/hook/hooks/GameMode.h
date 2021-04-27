#pragma once

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../module/ModuleManager.h"
#include "../../sdk/GameMode.h"

class GameModeHook : public Hook {
public:
	void install();
};

typedef void(__stdcall* GmTick)(GameMode* GM);
GmTick _GmTick;

void GmTick_callback(GameMode* GM) {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (GM != nullptr && player != nullptr) {
		if (player == GM->Player) {
			gData.setGameMode(GM);

			for (auto Module : moduleMgr.modules) {
				if (Module->isEnabled)
					Module->onGmTick();
			}
		}
	}

	_GmTick(GM);
}

void GameModeHook::install() {
	this->hookSig("GameMode::tick", "40 53 48 83 EC 20 48 8B D9 48 8B 89 ? ? ? ? 48 8B 01 FF 50 18", &GmTick_callback, reinterpret_cast<LPVOID*>(&_GmTick));

	//Utils::DebugLogOutput(Utils::ptrToStr((uintptr_t)gData.getClientInstance()->LocalPlayer()));
}