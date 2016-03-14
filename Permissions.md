#Why does ClickOnce for Chrome require such broad access permissions?

# Why does ClickOnce for Chrome require such broad permissions? #

Q: "Hi, I was just about to download a chrome extension of yours call ClickOnce. Then I noticed that it requires access to all my computers data and browsing info. Is that really necessary and what is that information used for?"

A: Unfortunately this is the nature of the ClickOnce technology.  When you click on a .application link the browser downloads, installs and runs an application on your computer.

Since that application runs outside of the browser it isn't managed by the browser's security sandbox. So, by extension, if the browser plugin is able to launch such an application it requires the same broad permissions.

It is important to remember that you should only run a ClickOnce application from a trusted source.