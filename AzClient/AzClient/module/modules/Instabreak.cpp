#include "Instabreak.h"

void Instabreak::onStartDestroyBlock(class Vec3_i* param_1, unsigned char param_2, bool* param_3) {
	if (gData.getGameMode() != nullptr) {
		gData.getGameMode()->destroyBlock(param_1, param_2);
	}
}