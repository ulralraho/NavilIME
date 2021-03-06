// dllmain.cpp : Defines the entry point for the DLL application.
#include "Global.h"


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		gHandleDllInstance = hModule;

		if (!InitializeCriticalSectionAndSpinCount(&gCriticalSection, 0)) {
			return FALSE;
		}

		DebugLogFile(L"%s\n", L"DLL attached");
		gNavilIME.HangulNew();

		break;

    case DLL_THREAD_ATTACH:
		break;
    case DLL_THREAD_DETACH:
		break;
    case DLL_PROCESS_DETACH:
		DebugLogFile(L"%s\n", L"DLL dettached");
		DeleteCriticalSection(&gCriticalSection);
        break;
    }
    return TRUE;
}

