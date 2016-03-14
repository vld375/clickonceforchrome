# Avoiding page refresh when launching .application #

The new version of ClickOnce (2.0.7+) no longer has the page refresh bug,
so both of these methods will give you smooth application launching:
  * `<a>` element with the `href` attribute pointing to the `.application` file
  * Programatically: `window.location = 'http://test.com/example.application'`

.


---


.


# OLD INSTRUCTIONS. NO LONGER NEEDED. #

> ~~By default when ClickOnce for Google Chrome™ handles a navigation to a .aplication file the browser fully "navigates" and then goes back the launching page.  This causes a full page refresh which is often OK but for ajax enabled sites can be a problem.  There are two workarounds that site owners can do to navigate without this refresh.~~

**Solutions**

> ~~**#1** Use javascript to create an embedded version of the plugin and use that to launch the application.  This can be done for a specific link or for the whole page at once using this script.~~

```
<script type="text/javascript">
    // To automatically redirect all .application links to the scriptable plugin hook the document click function
    document.onclick = function(e)
    {
        e = e || window.event;
        var element = e.target || e.srcElement;

        if (element.tagName == 'A' && element.pathname.match(/\.application$/))
        {
            var embed = document.createElement('embed');
            embed.setAttribute('type', 'application/x-ms-application');
            embed.setAttribute('width', 0);
            embed.setAttribute('height', 0);
            // Have to add the embed to the document for it
            // to actually instantiate.
            document.body.appendChild(embed);
            embed.launchClickOnce(element.href);
            // Don't remove the embed right away b/c it can
            // cancel the download of the .application.
            return false;
        }
    }
</script>
```

> ~~t**#2** Using a hidden IFrame and appending &cofc\_goback=false to the url parameters.  This simply skips the navigation back to the original page leaving whatever window or frame in an unpaintable state.  Definitely don't do this in a visible iframe or window as the results will be a bit unpredictable.~~