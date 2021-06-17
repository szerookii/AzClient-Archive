#pragma once

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../module/ModuleManager.h"

class KeyboardHook : public Hook {
public:
	void install();
};

typedef void(WINAPI* AVKeyItem)(uint64_t key, bool isDown);
AVKeyItem _AVKeyItem;

void KeyItem_callback(uint64_t key, bool isDown) {
	Utils::KeyMapping[key] = isDown;

	if (key == VK_RSHIFT) {
		Utils::running = false;
		return;
	}

	for (auto module : moduleMgr.modules) {
		if (isDown) {
			if ((int)key == (int)module->key) {
				module->isEnabled = !module->isEnabled;

				if (module->isEnabled)
					module->onEnable();
				else
					module->onDisable();
			}
		}

		if (module->isEnabled) {
			bool cancel = false;
			module->onKey(key, isDown, &cancel);

			if (cancel) {
				return;
			}
		}
	}
	
	_AVKeyItem(key, isDown);
}

void KeyboardHook::install() {
	this->hookSig("AVKeyItem", "48 89 5C 24 ?? ?? 48 83 EC ?? 8B 05 ?? ?? ?? ?? 8B DA", &KeyItem_callback, reinterpret_cast<LPVOID*>(&_AVKeyItem));
}