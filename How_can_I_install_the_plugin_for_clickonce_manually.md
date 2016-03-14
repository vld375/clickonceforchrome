# How can I install the plugin for clickonce manually? #

Reported by avi.barnea, Dec 8, 2011
Hi,

How can I install the plugin for clickonce manually?

Thanks,
AviB

### Comment 1 by developer, Dec 8, 2011 ###
In downloads is an example registry file which can be used to register NPClickOnce.dll with Chrome/Firefox/Safari.  Copy NPClickOnce.dll from the chrome installer package to a location on your hard drive then set the path to that location.
```
[HKEY_CURRENT_USER\Software\MozillaPlugins\@digitalsorcery.net/ClickOnceForChrome;1.2]
"Description"="Clickonce for Google Chrome"
"ProductName"="Clickonce for Google Chrome"
"Vendor"="N/A"
"Version"="1.2"
"Path"="YOUR PATH TO NPClickOnce.dll"
```

### Comment 2 by avi.barnea, Dec 8, 2011 via email ###
thanks for the quick response, I'll give it a try

### Comment 3 by avi.barnea, Dec 8, 2011 via email ###
do I need to see an entry for the plugin in the Chrome browser
Tools\Extensions ? cause there is none.


### Comment 4 by avi.barnea, Dec 8, 2011 via email ###
btw, I used the reg file as is but I noticed that when I launch the Chrome
browser the directory under ..\Extensions has been deleted.
should I place the dll elsewhere?

Thanks


### Comment 5 by developer, Dec 8, 2011 ###
If you install it this way you should see it listed in chrome://plugins/ but not under extensions.  Since all of the functionality is in the plugin this should work fine.  The extension is only there to make the web install experience simpler.

Depending on what you want this for it might be easier to use a .crx packge which would install the plugin by double clicking or dragging and dropping on chrome.  The sources for that sort of package are in source control.  Download the sources then use chrome://extensions -> developer mode -> pack extension.

### Comment 6 by developer, Dec 8, 2011 ###
You should probably place the dll somewhere outside of the chrome install path just in case.  \program files (x86)\clickonceforchrome\ would work pretty well