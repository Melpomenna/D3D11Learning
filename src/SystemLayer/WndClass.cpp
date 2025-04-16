#include "WndClass.h"

#include <new>

#if SYSTEM_WINDOWS
#include <SystemLayer/Windows/WndClassImpl.h>
#else
#error "Unsupported platform"
#endif

WndClass::WndClass(WindowParams&& params)
{
	impl_ = ::new(std::nothrow)	WndClassImpl(std::move(params));
}

WndClass::WndClass(const WndClass& other)
{
	impl_ = ::new(std::nothrow) WndClassImpl(*other.impl_);
}

WndClass::WndClass(WndClass&& other) noexcept
{
	impl_ = other.impl_;
	other.impl_ = nullptr;
}

WndClass& WndClass::operator=(const WndClass& other)
{
	if (this == &other)
		return *this;

	WndClassImpl* tmp = ::new(std::nothrow) WndClassImpl(*other.impl_);
	if (tmp)
	{
		::delete impl_;
		impl_ = tmp;
	}

	return *this;
}

WndClass& WndClass::operator=(WndClass&& other) noexcept
{
	if (this == &other)
		return *this;

	::delete impl_;
	impl_ = other.impl_;
	other.impl_ = nullptr;

	return *this;
}

WndClass::~WndClass()
{
	::delete impl_;
}

System::TWndClass WndClass::GetNativeHandle() noexcept
{
	return impl_->GetNativeHandle();
}

System::TWnd WndClass::GetWndHandle() noexcept
{
	return impl_->GetWndHandle();
}
