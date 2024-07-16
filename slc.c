//
// slc.c
// © 2024 by Igor Levicki. All Rights Reserved.
//
// Compile:
// cl /nologo /c /O2 /Ob1 slc.c
//
// Link:
// link /nologo /DLL /ENTRY:DllMain /DEF:slc.def /MACHINE:X64 /SUBSYSTEM:WINDOWS /NODEFAULTLIB /NOEXP /NOIMPLIB /DEBUG:NONE /EMITPOGOPHASEINFO /MERGE:.rdata=.text slc.obj kernel32.lib
//

#include <windows.h>

HRESULT __stdcall SLGetWindowsInformationDWORD(LPCWSTR ValueName, LPDWORD Value)
{

	if (lstrcmpiW(L"Shell-InBoxGames-FreeCell-EnableGame", ValueName) == 0) {
		*Value = 1;
	} else if (lstrcmpiW(L"Shell-InBoxGames-Minesweeper-EnableGame", ValueName) == 0) {
		*Value = 1;
	} else {
		*Value = 0;
	}

	return S_OK;
}

DWORD __stdcall DllMain(HINSTANCE hModule, DWORD dwReason, DWORD dwReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
	}
	
	return TRUE;
}
