#include <Config.h>


#include <Application.h>

USING_SYSTEM_NAMESPACE;

int APIENTRY WinMain(UNUSED In_Arg THInstance hInstance,
	UNUSED In_Opt_Arg THInstance hPrevInstance,
	UNUSED In_Arg TText lpCmdLine,
	UNUSED In_Arg TInt nCmdShow)
{
	
// TODO: Use Wrapper for memory state
#if SYSTEM_WINDOWS && !NDEBUG
	CMemoryState end{};	
	CMemoryState diff;
	CMemoryState start{};
	start.Checkpoint();
#endif
   Application app(hInstance);
   TInt result = app.Exec(nullptr);  

#if SYSTEM_WINDOWS && !NDEBUG
   end.Checkpoint();
   if (diff.Difference(start, end))
   {
	   diff.DumpAllObjectsSince();
	   diff.DumpStatistics();
   }
#endif
   return result;
}