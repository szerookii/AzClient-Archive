#pragma once

#include <cstdint>

class MultiPlayerLevel {
public:
	char pad_0008[88]; //0x0000
	uint64_t listStart; //0x0058
	uint64_t listEnd; //0x0066
	char pad_0060[32]; //0x006E

public:

	inline class Actor* get(size_t idx) {
		if (idx >= getListSize())
			return 0;
		return *reinterpret_cast<class Actor**>(listStart + (idx * sizeof(uintptr_t)));
	};

	inline size_t getListSize() {
		return (listEnd - listStart) / sizeof(uintptr_t);
	};
};