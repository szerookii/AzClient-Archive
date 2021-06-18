#include "Reach.h"

void Reach::onEnable() { // From Horion but it is my signature :d
	static uintptr_t sigOffset = 0x0;

	if (sigOffset == 0x0) {
		sigOffset = Utils::FindSig(xorstr_("F3 0F 59 ? ? ? ? ? 80 BE"));

		if (sigOffset != 0x0) {
			int offset = *reinterpret_cast<int*>((sigOffset + 4));
			reachPtr = reinterpret_cast<float*>(sigOffset + offset + 8);

			originalReach = *reachPtr;
		}
	}

	VirtualProtect(reachPtr, sizeof(float), PAGE_EXECUTE_READWRITE, &oldProtect);
}

void Reach::onDisable() {
	*reachPtr = originalReach;

	if (reachPtr != 0)
		VirtualProtect(reachPtr, sizeof(float), oldProtect, &oldProtect);
}

void Reach::onGmTick() {
	if (reachPtr != 0) {
		*reachPtr = 5.f;
	}
}