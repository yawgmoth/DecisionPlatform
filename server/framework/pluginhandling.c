#include "string.h"
#include <stdlib.h>
#include <stdio.h>

int xkcd_plugin()
{
    system("sh -c 'cd plugins/xkcdplugin; make'");
    return system("plugins/xkcdplugin/plugin.exe");
}

int perl_plugin()
{
    system("sh -c 'cd plugins/perlplugin; make'");
    return system("plugins/perlplugin/plugin.exe");
}

int (*get_plugin(char* name))(void)
{
    if (!strcmp(name, "xkcd"))
    {
        return xkcd_plugin;
    }
    else if (!strcmp(name, "perl"))
    {
        return perl_plugin;
    }
    return NULL;
}
