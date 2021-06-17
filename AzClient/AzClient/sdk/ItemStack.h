#pragma once

#include <cstdint>

#include "../utils/Utils.h"

class ItemStack {
private:
	uintptr_t** VTable;
public:
	class Item** item;

	int getId() {
		using GetId = int(__thiscall*)(ItemStack*);
		static GetId _GetId = reinterpret_cast<GetId>(Utils::FindSig("80 79 23 00 75 06 B8 ? ? ? ? C3"));
		return _GetId(this);
	}

	int getMaxStackSize() {
		using GetMaxStackSize = int(__thiscall*)(ItemStack*);
		static GetMaxStackSize _GetMaxStackSize = reinterpret_cast<GetMaxStackSize>(Utils::FindSig("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 70 33 FF 89 BC 24 ? ? ? ? 48 8B 41 08 48 85 C0"));
		return _GetMaxStackSize(this);
	}

	class Item* getItem() {
		using GetItem = Item * (__thiscall*)(ItemStack*);
		static GetItem _GetItem = reinterpret_cast<GetItem>(Utils::FindSig("48 8B 41 08 48 85 C0 74 04 48 8B 00 C3"));
		return _GetItem(this);
	}
};