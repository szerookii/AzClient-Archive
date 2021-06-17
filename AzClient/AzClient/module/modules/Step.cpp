#include "Step.h"

void Step::onGmTick() {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (player != nullptr) {
		player->stepHeight = 2.f;
	}
}