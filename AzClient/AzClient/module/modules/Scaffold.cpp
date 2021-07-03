#include "Scaffold.h"

void Scaffold::onGmTick() {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();
	GameMode* gm = gData.getGameMode();

	if (player == nullptr || gm == nullptr)
		return;

	//if (player->getCarriedItem()->getItem)

	Vec3 currentPos = player->position;
	Vec3_i blockPos = Vec3_i(currentPos.x, currentPos.y - 1.f, currentPos.z);
	
	int side = 0;

	float playerYaw = player->bodyRot()->y;

	if (playerYaw < -45 && playerYaw > -135)
		side = 5;
	else if (playerYaw > 45 && playerYaw < 135)
		side = 4;
	else if ((playerYaw <= 0 && playerYaw >= -45) || (playerYaw >= 0 && playerYaw <= 45))
		side = 3;
	else if (playerYaw >= 135 && playerYaw <= 180 || (playerYaw >= -180 && playerYaw <= -135))
		side = 2;

	switch (side) {

	case 5:
		if (floor(currentPos.x + 0.3f) == floor(currentPos.x + 1.0f)) {
			gm->buildBlock(&blockPos, 5);
		}

		if (floor(currentPos.z - 0.25f) == floor(currentPos.z - 1.0f)) {
			gm->buildBlock(&blockPos, 2); //Left
		}
		else if (floor(currentPos.z + 0.25f) == floor(currentPos.z + 1.0f)) {
			gm->buildBlock(&blockPos, 3); //Right
		}
		break;

	case 4: //West
		if (floor(currentPos.x - 0.3f) == floor(currentPos.x - 1.0f)) {
			gm->buildBlock(&blockPos, 4);
		}

		if (floor(currentPos.z + 0.25f) == floor(currentPos.z + 1.0f)) {
			gm->buildBlock(&blockPos, 3); //Left
		}
		else if (floor(currentPos.z - 0.25f) == floor(currentPos.z - 1.0f)) {
			gm->buildBlock(&blockPos, 2); //Right
		}
		break;

	case 3: //South
		if (floor(currentPos.z + 0.3f) == floor(currentPos.z + 1.0f)) {
			gm->buildBlock(&blockPos, 3);
		}

		if (floor(currentPos.x + 0.25f) == floor(currentPos.x + 1.0f)) {
			gm->buildBlock(&blockPos, 5); //Left
		}
		else if (floor(currentPos.x - 0.25f) == floor(currentPos.x - 1.0f)) {
			gm->buildBlock(&blockPos, 4); //Right
		}
		break;

	case 2: //North
		if (floor(currentPos.z - 0.3f) == floor(currentPos.z - 1.0f)) {
			gm->buildBlock(&blockPos, 2);
		}

		if (floor(currentPos.x - 0.25f) == floor(currentPos.x - 1.0f)) {
			gm->buildBlock(&blockPos, 4); //Left
		}
		else if (floor(currentPos.x + 0.25f) == floor(currentPos.x + 1.0f)) {
			gm->buildBlock(&blockPos, 5); //Right
		}
		break;

	}
}