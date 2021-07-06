#pragma once

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../sdk/AppPlatform.h"
#include "../../sdk/ClientInstance.h"
#include "../../sdk/LoopbackPacketSender.h"
#include "../../sdk/Packet.h"

class OtherHook : public Hook {
public:
	void install();
};

typedef int(__stdcall* AppPlatform_getGameEdition)(__int64 _this);
AppPlatform_getGameEdition _AppPlatform_getGameEdition;

int hAppPlatform_getGameEdition(__int64 _this) {
	auto edition = moduleMgr.getModuleByName("EditionFaker");

	if (edition != nullptr && edition->isEnabled) {
		return Editions::iOS;
	}

	return _AppPlatform_getGameEdition(_this);
}

typedef void(__stdcall* LoopbackPacketSender_sendToServer)(LoopbackPacketSender* _this, Packet* packet);
LoopbackPacketSender_sendToServer _LoopbackPacketSender_sendToServer;

void hLoopbackPacketSender_sendToServer(LoopbackPacketSender* _this, Packet* packet) {
	bool cancel = false;

	for (auto module : moduleMgr.modules) {
		if (module->isEnabled)
			module->onPacketSend(packet, &cancel);
	}

	if (cancel == true)
		return;

	return _LoopbackPacketSender_sendToServer(_this, packet);
}

void OtherHook::install() {
	this->hookSig("AppPlatform::getGameEdition", xorstr_("8B 91 ?? ?? ?? ?? 85 D2 74 1C 83 EA 01"), &hAppPlatform_getGameEdition, (LPVOID*)&_AppPlatform_getGameEdition);
	this->hookSig("LoopbackPacketSender::sendToServer", xorstr_("48 8B 41 10 4C 8B 09 4C 8B 40 ? 41 80 B8 ? ? ? ? ? 74 04 49 FF 61 30"), &hLoopbackPacketSender_sendToServer, (LPVOID*)&_LoopbackPacketSender_sendToServer);
}
