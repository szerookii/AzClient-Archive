#pragma once

#include<Windows.h>

#include "../sdk/ClientInstance.h"
#include "../sdk/RakNetInstance.h"
#include "../sdk/GameMode.h"
#include "../sdk/GuiData.h"
#include "../sdk/HIDController.h"

class GameData {
private:
	ClientInstance* cachedInstance;
	HIDController* cachedHIDController;
	GameMode* cachedGameMode;
	RakNetInstance* cachedRakNetInstance;

public:
	void setClientInstance(ClientInstance* obj) {
		if (obj != nullptr) cachedInstance = obj;
	}

	ClientInstance* getClientInstance() {
		return cachedInstance;
	}


	void setHIDController(HIDController* obj) {
		if (obj != nullptr) cachedHIDController = obj;
	}

	HIDController** getHIDController() {
		return &cachedHIDController;
	}

	void setGameMode(GameMode* GM) {
		if (GM != nullptr) cachedGameMode = GM;
	}

	GameMode* getGameMode() {
		return cachedGameMode;
	}

	void setRakNetInstance(RakNetInstance* RI) {
		cachedRakNetInstance = RI;
	}

	RakNetInstance* getRakNetInstance() {
		return cachedRakNetInstance;
	}
};

extern GameData gData;