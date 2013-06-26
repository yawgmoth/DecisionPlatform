
#ifndef INITCODE
#define INITCODE
#endif

#ifndef PLUGINCODE
#define PLUGINCODE
#endif

#ifndef AUTHPLUGIN
#define AUTHPLUGIN
#endif

#ifndef SHUTDOWN_PLUGIN
#define SHUTDOWN_PLUGIN
#endif

int init_plugin()
{
   INITCODE
}

int authPlugin(char* user)
{
   AUTHPLUGIN
}

int plugincode()
{
    PLUGINCODE
}

int shutdown()
{
   SHUTDOWN_PLUGIN
}

int main(int argc, char* argv[])
{
    int result = -1;
    init_plugin();
    if (argc < 2 || authPlugin(argv[1]))
    {
        result = plugincode();
    }
    shutdown();
    if (result) return 1;
    return 0;
}