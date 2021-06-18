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
}