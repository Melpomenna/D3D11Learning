#include "Application.h"

#include <new>

#include <SystemLayer/WndClass.h>

Application::Application(System::THInstance instance)
{
	System::TConstText className = "WndApplicationClassName";
    WindowParams params(instance, className);
	wndClass_ = ::new(std::nothrow) WndClass(std::move(params));
}

System::TInt Application::Exec(const System::TText args) & noexcept {
	VUNUSED(args);
	System::TInt result{ 0 };

	return result;
}

Application::~Application()
{
	::delete wndClass_;
}
