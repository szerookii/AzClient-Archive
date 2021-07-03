#pragma once

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../sdk/AppPlatform.h"
#include "../../sdk/ClientInstance.h"

class OtherHook : public Hook {
public:
	void install();
};

typedef int(__stdcall* AppPlatform_getGameEdition)(__int64 _this);
AppPlatform_getGameEdition _AppPlatform_getGameEdition;

int AppPlatform_getGameEdition_callback(__int64 _this) {
	auto edition = moduleMgr.getModuleByName("EditionFaker");

	if (edition != nullptr && edition->isEnabled) {
		return Editions::iOS;
	}

	return _AppPlatform_getGameEdition(_this);
}

void OtherHook::install() {
	this->hookSig("AppPlatform::getGameEdition", xorstr_("8B 91 ?? ?? ?? ?? 85 D2 74 1C 83 EA 01"), &AppPlatform_getGameEdition_callback, (LPVOID*)&_AppPlatform_getGameEdition);
}
