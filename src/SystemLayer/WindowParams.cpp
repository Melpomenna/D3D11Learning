#include "WindowParams.h"

WindowParams::WindowParams(System::THInstance pInstance, System::TConstText sClassName) noexcept	
	: instance(pInstance), className(sClassName)
{

}

WindowParams& WindowParams::operator=(WindowParams&& other)	noexcept
{
	if (this == &other)
		return *this;

	instance = other.instance;
	className = other.className;

	other.instance = nullptr;
	other.className = nullptr;

	return *this;
}

WindowParams::WindowParams(WindowParams&& other) noexcept
	: instance(other.instance), className(other.className)
{
	other.instance = nullptr;
	other.className = nullptr;
}
