#include "AirJump.h"

void AirJump::onGmTick() {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (player != nullptr) {
		player->onGround = true;
	}
}