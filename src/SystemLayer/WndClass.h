#pragma once

#include <Config.h>
#include <SystemLayer/WindowParams.h>

class WndClassImpl;

class WndClass	final
{								
public:
	explicit WndClass(WindowParams&& params);

	WndClass(const WndClass&);
	WndClass(WndClass&&) noexcept;

	WndClass& operator=(const WndClass&);
	WndClass& operator=(WndClass&&) noexcept;

	~WndClass();

	System::TWndClass GetNativeHandle() noexcept;
	System::TWnd GetWndHandle() noexcept;

public:
	WndClassImpl* impl_{nullptr};
};

