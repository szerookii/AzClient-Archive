#include<Windows.h>

#include "include/MinHook.h"

#if defined _M_X64
#pragma comment(lib, "MinHook.x64.lib")
#endif

#include "AzClient/hook/HookManager.h"
#include "AzClient/module/ModuleManager.h"
#include "AzClient/data/GameData.h"
#include "AzClient/utils/Utils.h"

void Init(LPVOID lpParam) {
    Utils::hModule = (HMODULE)lpParam;

    Utils::DeletePath("AzClient/logs.txt");
    Utils::DebugLogOutput("Injected...");

    Utils::running = true;

    hookMgr.init();
    moduleMgr.init();

     MH_DisableHook(MH_ALL_HOOKS);

    Sleep(200);

    MH_Uninitialize();

    Sleep(100);

    Utils::DebugLogOutput("Ejecting...");

    FreeLibraryAndExitThread(Utils::hModule, 0);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

