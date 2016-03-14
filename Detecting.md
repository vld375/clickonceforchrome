**NEW** way of detecting if the _ClickOnce for Chrome_ extension is installed:

```
// a simple global variable is available, if the extension is installed
if (typeof CLICKONCE_EXTENSION_IS_INSTALLED != 'undefined') 
{
  // do stuff
}
```



**WARNING:** These old methods do NOT work anymore:

```
function IsClickOnceMimeSupported()
{
   return navigator.mimeTypes["application/x-ms-application"] != null;
}

function IsClickOnceForChromePresent()
{
    var plugin = navigator.mimeTypes["application/x-ms-application"];
    return plugin.enabledPlugin.filename == "npclickonce.dll";
}
```