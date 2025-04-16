#include "WndClassImpl.h"

WndClassImpl::WndClassImpl(WindowParams&& params)
{
    wndClass_.cbSize = sizeof(System::TWndClass);
    wndClass_.hInstance = params.instance;
    wndClass_.style = CS_OWNDC;
    wndClass_.lpfnWndProc = DefWindowProc;
    wndClass_.lpszClassName = params.className;      
    wndClass_.cbClsExtra = 0;
    wndClass_.cbWndExtra = 0;
    wndClass_.hCursor = nullptr;
    wndClass_.hIcon = nullptr;
    wndClass_.hbrBackground = nullptr;
    wndClass_.lpszMenuName = nullptr;

    RegisterClassEx(&wndClass_);

    wnd_ = CreateWindowEx(0, wndClass_.lpszClassName, TEXT("Undefined"),
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, 0, 0,
        DEFAULT_MIN_WIN_SIZE, DEFAULT_MIN_WIN_SIZE, nullptr, nullptr, wndClass_.hInstance, nullptr);
}

WndClassImpl::WndClassImpl(const WndClassImpl& other)
{
    memcpy(&wndClass_, &other.wndClass_, sizeof(System::TWndClass));
}

WndClassImpl::WndClassImpl(WndClassImpl&& other) noexcept
{
    memcpy(&wndClass_, &other.wndClass_, sizeof(System::TWndClass));
    memset(&other.wndClass_,0, sizeof(System::TWndClass));
}

WndClassImpl& WndClassImpl::operator=(const WndClassImpl& other)
{
    if (this == &other)
        return *this;

    memcpy(&wndClass_, &other.wndClass_, sizeof(System::TWndClass));

    return *this;
}

WndClassImpl& WndClassImpl::operator=(WndClassImpl&& other) noexcept
{
    if (this == &other)
        return *this;
    memcpy(&wndClass_, &other.wndClass_, sizeof(System::TWndClass));
    memset(&other.wndClass_, 0, sizeof(System::TWndClass));

    return *this;
}

WndClassImpl::~WndClassImpl()
{
    UnregisterClass(wndClass_.lpszClassName,wndClass_.hInstance);
    DestroyWindow(wnd_);
    wnd_ = nullptr;
}

System::TWndClass WndClassImpl::GetNativeHandle() noexcept
{
    return wndClass_;
}

System::TWnd WndClassImpl::GetWndHandle() noexcept
{
    return wnd_;
}