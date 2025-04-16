#pragma once

#include <Config.h>

class WndClass;

class Application final
{
public:
	explicit Application(System::THInstance instance);

	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

	Application(Application&&) noexcept = delete;
	Application& operator=(Application&&) noexcept = delete;


	System::TInt Exec(const System::TText args) & noexcept;

	~Application();
private:
	WndClass* wndClass_{nullptr};
};

