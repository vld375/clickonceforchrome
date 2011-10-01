#include "StdAfx.h"
#include "NPApplicationLauncher.h"
#include "NPClickOnce.h"


NPApplicationLauncher::NPApplicationLauncher(NPP instance)
    : NPScriptableObject<NPApplicationLauncher>(instance)
{
    launchIdentifier = GetStringIdentifier("launchClickOnce");
    versionString = GetStringIdentifier("version");
}

NPApplicationLauncher::~NPApplicationLauncher(void)
{
}


// If this logic ever needs to get significantly more complex
// it will probably make sense to create a map<NPIdentifier, method>
bool NPApplicationLauncher::HasMethod(NPIdentifier method)
{
    return (method == launchIdentifier);
}

bool NPApplicationLauncher::Invoke(NPIdentifier method, const NPVariant* args, uint32_t argc, NPVariant* result)
{
    if (method == launchIdentifier &&
        argc == 1 &&
        NPVARIANT_IS_STRING(args[0]))
    {
        NPString url = NPVARIANT_TO_STRING(args[0]);
        // ISSUE 7 - NPString might not be NULL terminated
        // copy the string to ensure null termination.
        url = NPStrDup(url);
        SafeLaunchClickOnceApp(_npp, url.UTF8Characters);
        NPFreeString(url);
        return true;
    }
    return false;
}

bool NPApplicationLauncher::HasProperty(NPIdentifier name)
{
    return name == versionString;
}

bool NPApplicationLauncher::GetProperty(NPIdentifier name, NPVariant* result)
{
    if (name == versionString && result != NULL)
    {
        char version[] = "1.2.1";
        NPString value = NPStrDup("1.2", ARRAYSIZE(version));
        STRINGN_TO_NPVARIANT(value.UTF8Characters, value.UTF8Length, *result);
        return true;
    }
    result = NULL;
    return false;
}
