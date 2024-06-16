#pragma once
#include "stdafx.h"
#include <xuiapp.h>

class Application : public CXuiModule {
protected:
    // Override RegisterXuiClasses so that CMyApp can register classes.
    virtual HRESULT RegisterXuiClasses();

    // Override UnregisterXuiClasses so that CMyApp can unregister classes. 
    virtual HRESULT UnregisterXuiClasses();

    // Override ProcessInput so that CMyApp can trap the return-to-Launcher input chord.
    virtual HRESULT ProcessInput();

    // Override RunFrame so that CMyApp can trap the user-defined event.
    virtual void    RunFrame();

public:

};

extern Application pApplication;