#include "Killaura.h"

void Killaura::onGmTick() {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();

	if (player != nullptr && ++this->tick == 10) {
		MultiPlayerLevel* level = gData.getClientInstance()->LocalPlayer()->getMultiPlayerLevel();

		if (level != nullptr) {
			Vec3 myPos = *player->getPos();
			size_t entListSize = level->getListSize();

			if (entListSize > 0 && entListSize <= 5000) {
				for (size_t i = 0; i < entListSize; i++) {
					Actor* currEnt = level->get(i);
					float distance = currEnt->getPos()->distance(myPos);

					if (currEnt != nullptr && currEnt != player && distance <= 5.f) {
						player->lookAt(currEnt, 100, 100);
						gData.getGameMode()->attack(currEnt);
						player->swing();
					}
				}
			}
		}

		this->tick = 0;
	}
}