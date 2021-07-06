#include "Phase.h"

void Phase::onDisable() {
	auto player = gData.getClientInstance()->LocalPlayer();

	if (player == nullptr)
		return;

	player->getAABB()->upper.y += 1.8f;
}

void Phase::onGmTick() {
	auto player = gData.getClientInstance()->LocalPlayer();

	if (player == nullptr)
		return;

	player->getAABB()->upper.y = player->getAABB()->lower.y;
}