#pragma once

#include <Config.h>
#include <SystemLayer/WindowParams.h>

class WndClassImpl
{
public:
	explicit WndClassImpl(WindowParams&& params);

	WndClassImpl(const WndClassImpl&);
	WndClassImpl(WndClassImpl&&) noexcept;

	WndClassImpl& operator=(const WndClassImpl&);
	WndClassImpl& operator=(WndClassImpl&&) noexcept;

	~WndClassImpl();

	System::TWndClass GetNativeHandle() noexcept;
	System::TWnd GetWndHandle() noexcept;
private:
	System::TWndClass wndClass_{ 0 };
	System::TWnd wnd_{nullptr};
};

