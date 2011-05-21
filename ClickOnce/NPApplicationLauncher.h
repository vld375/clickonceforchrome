#pragma once
#include "NPScriptableObject.h"
#include <map>

class NPApplicationLauncher : public NPScriptableObject<NPApplicationLauncher>
{
public:
    NPApplicationLauncher(NPP instance);
    virtual ~NPApplicationLauncher(void);

    bool HasMethod(NPIdentifier method);
    bool Invoke(NPIdentifier method, const NPVariant* args, uint32_t argc, NPVariant* result);
    
private:

    NPIdentifier launchIdentifier;
};

