#include "Bhop.h"

void Bhop::onGmTick() {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();
	GameSettingsInput* input = gData.getClientInstance()->getGameSettingsInput();

	if (player == nullptr || input == nullptr || !gData.getClientInstance()->MinecraftGame()->canUseKeys())
		return;

	float calcYaw = player->bodyRot.y;

	bool pressedForward = Utils::isKeyDown(*input->forwardKey);
	bool pressedBackKey = Utils::isKeyDown(*input->backKey);
	bool pressedLeftKey = Utils::isKeyDown(*input->leftKey);
	bool pressedRightKey = Utils::isKeyDown(*input->rightKey);

	if (pressedForward) {
		if (!pressedLeftKey && !pressedRightKey) {
			calcYaw += 90.0f;
		}
		else if (pressedLeftKey) {
			calcYaw += 45.0f;
		}
		else if (pressedRightKey) {
			calcYaw += 135.0f;
		}
	}
	else if (pressedBackKey) {
		if (!pressedLeftKey && !pressedRightKey) {
			calcYaw -= 90.0f;
		}
		else if (pressedLeftKey) {
			calcYaw -= 45.0f;
		}
		else if (pressedRightKey) {
			calcYaw -= 135.0f;
		}
	}
	else if (!pressedForward && !pressedBackKey) {
		if (pressedRightKey) {
			calcYaw += 180.0f;
		}
	}

	if (pressedForward | pressedBackKey | pressedLeftKey | pressedRightKey) {
		player->velocity.x = cos((calcYaw) * (PI / 180.0f)) * 2.f;
		player->velocity.z = sin((calcYaw) * (PI / 180.0f)) * 2.f;

		if (player->onGround) {
			/*if (!player->isJumping())
				player->jumpFromGround();*/
		}
	}
}