#pragma once

#include "../Hook.h"
#include "../../data/GameData.h"
#include "../../sdk/ClientInstance.h"

class ActorHook : public Hook {
public:
	void install();
};

typedef void(__stdcall* Actor_ascendLadder)(Actor* _this);
Actor_ascendLadder _Actor_ascendLadder;

void hActor_ascendLadder(Actor* _this) {
	auto ladder = moduleMgr.getModuleByName("FastLadder");

	if (ladder != nullptr && ladder->isEnabled) {
		_this->velocity()->y = 0.6f;
		return;
	}

	_Actor_ascendLadder(_this);
}

typedef void(__stdcall* Actor_lerpMotion)(Actor* _this, Vec3);
Actor_lerpMotion _Actor_lerpMotion;

void hActor_lerpMotion(Actor* _this, Vec3 to) {
	auto kb = moduleMgr.getModuleByName("NoKB");

	if (kb != nullptr && kb->isEnabled) {
		return;
	}

	return _Actor_lerpMotion(_this, to);
}

typedef bool(__stdcall* Actor_isInWater)(Actor* _this);
Actor_isInWater _Actor_isInWater;

bool hActor_isInWater(Actor* _this) {
	auto airswim = moduleMgr.getModuleByName("AirSwim");

	if (airswim != nullptr && airswim->isEnabled) {
		return true;
	}

	return _Actor_isInWater(_this);
}

typedef float(__stdcall* Actor_getJumpPower)(Actor* _this);
Actor_getJumpPower _Actor_getJumpPower;

float hActor_getJumpPower(Actor* _this) {
	auto high = moduleMgr.getModuleByName("HighJump");

	if (high != nullptr && high->isEnabled) {
		return .7f;
	}

	return _Actor_getJumpPower(_this);
}

typedef bool(__stdcall* Actor_isImmobile)(Actor* _this);
Actor_isImmobile _Actor_isImmobile;

bool hActor_isImmobile(Actor* _this) {
	auto immobile = moduleMgr.getModuleByName("AntiImmobile");

	if (immobile != nullptr && immobile->isEnabled) {
		return false;
	}

	return _Actor_isImmobile(_this);
}

void ActorHook::install() {
	this->hookSig("LocalPlayer::ascendLadder", xorstr_("C7 81 ? ? ? ? ? ? ? ? C3 CC CC CC CC CC C7 81 ? ? ? ? ? ? ? ? C3 CC CC CC CC CC C7 81"), &hActor_ascendLadder, (LPVOID*)&_Actor_ascendLadder);
	this->hookSig("LocalPlayer::lerpMotion", xorstr_("8B 02 89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? 8B 42 ? 89 81 ? ? ? ? C3 CC CC CC CC CC 48 89 5C 24"), &hActor_lerpMotion, (LPVOID*)&_Actor_lerpMotion);
	this->hookSig("LocalPlayer::isInWater", xorstr_("0F B6 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 0F B6 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 6C 24"), &hActor_isInWater, (LPVOID*)&_Actor_isInWater);
	this->hookSig("LocalPlayer::getJumpPower", xorstr_("40 53 48 83 EC ? 80 79 ? ? 48 8B D9 74 ? 48 8B 41 ? 48 8D 54 24"), &hActor_getJumpPower, (LPVOID*)&_Actor_getJumpPower);
	this->hookSig("LocalPlayer::isImmobile", xorstr_("40 53 48 83 EC ? 48 8B D9 E8 ? ? ? ? 84 C0 75 ? 48 8B 03 48 8B CB"), &hActor_isImmobile, (LPVOID*)&_Actor_isImmobile);

} // LocalPlayer::isOnFire 83 b9 ? ? ? ? ? 7f ? 48 8b 91
