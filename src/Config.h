#pragma once

#define VUNUSED(x) (void)x
#if defined(UNUSED)
#undef UNUSED
#define UNUSED [[maybe_unused]]
#endif


#define VLIKELY(x) __builtin_expect(!!(x), 1)
#define VUNLIKELY(x) __builtin_expect(!!(x), 0)

#if defined(__cplusplus)
#define CXX_LIKELY_ATTRIBUTE [[likely]]
#define CXX_UNLIKELY_ATTRIBUTE [[unlikely]]
#else
#define CXX_LIKELY_ATTRIBUTE
#define CXX_UNLIKELY_ATTRIBUTE
#endif

#define ATTR_WINDOWS_ONLY
#define ATTR_LINUX_ONLY
#define ATTR_MACOS_ONLY

#ifdef _WIN32

#define SYSTEM_WINDOWS 1
#define SYSTEM_MACOS 0
#define SYSTEM_LINUX 0

#define SYSTEM_NAMESPACE Windows
#define SYSTEM_NAMESPACE_BEGIN namespace SYSTEM_NAMESPACE {
#define SYSTEM_NAMESPACE_END }

#if defined TEXT
#undef TEXT

#if defined(UNICODE) && UNICODE
#define TEXT(__str) __TEXT(__str)
#else
#define TEXT(__str) __str
#endif
#endif

#define DEBUG_ENTRY() DebugBreak()

SYSTEM_NAMESPACE_BEGIN
	using THInstance = HINSTANCE;
	using TWndClass = WNDCLASSEX;
	using TWnd = HWND;
	using TInt = int;
	using TLong = LONG;
	using TLLong = long long int;
	using TFloat = float;
	using TDouble = double;
	using TUInt = UINT;
	using TULong = DWORD;
#if defined(UNICODE) && UNICODE
	using TChar = WCHAR;
#else
	using TChar = CHAR;
#endif
    using TText = TChar*;
	using TConstText = const TChar*;
SYSTEM_NAMESPACE_END

#define In_Arg _In_
#define	In_Opt_Arg _In_opt_

#define Out_Arg _Out_
#define Out_Opt_Arg _Out_opt_

#else
#error "Unsupported platform"
#endif

#define USING_SYSTEM_NAMESPACE using namespace SYSTEM_NAMESPACE

#define DEFAULT_MIN_WIN_SIZE 600

namespace System = SYSTEM_NAMESPACE;