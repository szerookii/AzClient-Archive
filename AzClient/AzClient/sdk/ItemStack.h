#pragma once

#include <cstdint>

#include "TextHolder.h"
#include "../utils/Utils.h"

class ItemStack {
private:
	uintptr_t** VTable;
public:
	class Item** item;

	int getId() {
		using getId = int(__thiscall*)(ItemStack*);
		static getId _getId = reinterpret_cast<getId>(Utils::FindSig(xorstr_("80 79 23 00 75 06 B8 ? ? ? ? C3")));
		return _getId(this);
	}

	int getMaxStackSize() {
		using getMaxStackSize = int(__thiscall*)(ItemStack*);
		static getMaxStackSize _getMaxStackSize = reinterpret_cast<getMaxStackSize>(Utils::FindSig(xorstr_("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 70 33 FF 89 BC 24 ? ? ? ? 48 8B 41 08 48 85 C0")));
		return _getMaxStackSize(this);
	}

	class Item* getItem() {
		using getItem = Item * (__thiscall*)(ItemStack*);
		static getItem _getItem = reinterpret_cast<getItem>(Utils::FindSig(xorstr_("48 8B 41 08 48 85 C0 74 04 48 8B 00 C3")));
		return _getItem(this);
	}

	void setCustomName(std::string name) {
		TextHolder* text = new TextHolder(name);
		using setName = void(__thiscall*)(ItemStack*, TextHolder*);
		static setName _setName = reinterpret_cast<setName>(Utils::FindSig(xorstr_("48 89 5C 24 ? 48 89 74 24 ? 55 57 41 56 48 8D 6C 24 ? 48 81 EC B0 00 00 00 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 4C 8B F2")));
		return _setName(this, text);
	}
};