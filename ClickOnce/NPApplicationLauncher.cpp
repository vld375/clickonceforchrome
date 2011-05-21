#include "StdAfx.h"
#include "NPApplicationLauncher.h"
#include "NPClickOnce.h"


NPApplicationLauncher::NPApplicationLauncher(NPP instance)
    : NPScriptableObject<NPApplicationLauncher>(instance)
{
    launchIdentifier = GetStringIdentifier("launchApplication");
}

NPApplicationLauncher::~NPApplicationLauncher(void)
{
}

bool NPApplicationLauncher::HasMethod(NPIdentifier method)
{
    if (method == this->launchIdentifier)
    {
        return true;
    }
    return false;
}

bool NPApplicationLauncher::Invoke(NPIdentifier method, const NPVariant* args, uint32_t argc, NPVariant* result)
{
    if (method == launchIdentifier &&
        argc == 1 &&
        NPVARIANT_IS_STRING(args[0]))
    {
        NPString url = NPVARIANT_TO_STRING(args[0]);
        LaunchClickOnceApp(url.UTF8Characters);
        return true;
    }
    return false;
}