#include "AirJump.h"

void AirJump::onLoop() {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (player != nullptr) {
		player->onGround = true;
	}
}