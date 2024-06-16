#include "Application.h"

Application pApplication;

HRESULT Application::RegisterXuiClasses() {

    return S_OK;
}

HRESULT Application::UnregisterXuiClasses() {

    return S_OK;
}

HRESULT Application::ProcessInput()
{
    for (DWORD dwPort = 0; dwPort < XUSER_MAX_COUNT; ++dwPort) {
        XINPUT_STATE state = {
            0
        };
        if ((ERROR_SUCCESS == XInputGetState(dwPort, &state)) && (state.Gamepad.bLeftTrigger > 128) && (state.Gamepad.bRightTrigger > 128) && (state.Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER))
            XLaunchNewImage("", 0);
    }

    // Otherwise, allow XUI to process the input normally.
    XINPUT_KEYSTROKE keyStroke;
    if (ERROR_SUCCESS == XInputGetKeystroke(XUSER_INDEX_ANY, XINPUT_FLAG_ANYDEVICE, &keyStroke))
        XuiProcessInput(&keyStroke);

    return S_OK;
}


//----------------------------------------------------------------------------------
// Name: RunFrame
// Desc: Overrides CXuiModule::RunFrame() to additionally poll the event handlers.
//----------------------------------------------------------------------------------
void Application::RunFrame()
{
    OutputDebugString("Nigger");
    CXuiModule::RunFrame();
}