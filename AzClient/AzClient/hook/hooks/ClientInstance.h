#pragma once

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../sdk/ClientInstance.h"

class ClientInstanceHook : public Hook {
public:
	void install();
};

typedef void(__stdcall* ClientInstance_tick)(ClientInstance* _this, void* a1);
ClientInstance_tick _ClientInstance_tick;

void tick_callback(ClientInstance* _this, void* a1) {
	gData.setClientInstance(_this);

	_ClientInstance_tick(_this, a1);
}

void ClientInstanceHook::install() {
	this->hookSig("ClientInstance::tick", "48 89 5C 24 ?? 48 89 74 24 ?? 57 48 83 EC ?? 48 8B F9 48 8B 01", &tick_callback, reinterpret_cast<LPVOID*>(&_ClientInstance_tick));
}
