#include "HookManager.h"
#include "../../include/MinHook.h"

#include "hooks/Actor.h"
#include "hooks/ClientInstance.h"
#include "hooks/ChatScreenController.h"
#include "hooks/GameMode.h"
#include "hooks/Keyboard.h"
#include "hooks/Other.h"
#include "hooks/RenderContext.h"

HookManager hookMgr;

void HookManager::init() {
	if (MH_Initialize() != MH_OK) {
		return;
	}

	hooks.push_back(new ActorHook());
	hooks.push_back(new ClientInstanceHook());
	hooks.push_back(new ChatScreenControllerHook());
	hooks.push_back(new GameModeHook());
	hooks.push_back(new KeyboardHook());
	hooks.push_back(new OtherHook());
	hooks.push_back(new RenderContextHook());

	for (int i = 0; i < hooks.size(); i++) {
		hooks.at(i)->install();
	}
}