#include "Bhop.h"

static float speed = 0.325f;

void Bhop::onGmTick() {
	LocalPlayer* player = gData.getClientInstance()->LocalPlayer();
	GameSettingsInput* input = gData.getClientInstance()->getGameSettingsInput();

	if (player == nullptr || input == nullptr || !gData.getClientInstance()->MinecraftGame()->canUseKeys())
		return;

	float calcYaw = player->bodyRot()->y;

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
		auto velocity = player->velocity();
		player->lerpMotion(new Vec3(cos((calcYaw) * (PI / 180.0f)) * speed, player->onGround ? 0.42 : velocity->y, sin((calcYaw) * (PI / 180.0f)) * speed));
	}
}