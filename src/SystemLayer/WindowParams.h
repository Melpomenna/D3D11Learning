#pragma once

#include <Config.h>

struct WindowParams final
{
	WindowParams() = default;

	WindowParams(System::THInstance pInstance, System::TConstText sClassName) noexcept;

	WindowParams(const WindowParams& other) = delete;
	WindowParams& operator=(const WindowParams& other) = delete;

	WindowParams& operator=(WindowParams&& other) noexcept;
	WindowParams(WindowParams&& other) noexcept;

	~WindowParams() = default;

	ATTR_WINDOWS_ONLY System::THInstance instance{ nullptr };
	ATTR_WINDOWS_ONLY System::TConstText className{ nullptr };
};														   
