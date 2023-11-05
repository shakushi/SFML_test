#include "stdafx.h"
#include "AppMain.h"

int main()
{
    AppMain::CreateInstance();
    AppMain::Instance()->Init();
    while (AppMain::Instance()->Update() > 0) {
        // loop
    }
    AppMain::ReleaseInstance();
    return 0;
}