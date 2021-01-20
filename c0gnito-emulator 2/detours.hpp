#ifndef _DETOURS_HPP_
#define _DETOURS_HPP_

#include <Windows.h>

namespace detours
{
	auto Detour(void* address, void* target) -> void
	{
		unsigned char jmp[12] = 
		{
				0x48, 0xb8, // ; mov rax, addr
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0x0,
				0xff, 0xe0 // ; jmp rax
		};

		DWORD old_protection = 0;

		// Setup the jmp to our target addr
		memcpy(jmp + 0x2, &target, sizeof(target));

		// Change memory protection
		VirtualProtect(address, sizeof(jmp),
			PAGE_READWRITE, &old_protection);

		// Write the jmp to our target to address of the function
		memcpy(address, jmp, sizeof(jmp));

		VirtualProtect(address, sizeof(jmp),
			old_protection, &old_protection);
	}
}

#endif // !_DETOURS_HPP_