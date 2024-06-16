#include "stdafx.h"
#include "Application/Application.h"

void __cdecl main() {
	if (FAILED(pApplication.Init(XuiD3DXTextureLoader))) {
		OutputDebugStringA("Failed to Initialize Application\n");
		return;
	}

	OutputDebugStringA("Running\n");

	pApplication.Run();

	pApplication.Uninit();
}