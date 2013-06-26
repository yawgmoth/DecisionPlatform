
#define INITCODE return creatperl();
extern int creatperl();

#define PLUGINCODE return runperl();
extern int runperl();

#define SHUTDOWN_PLUGIN return remove_perl();
extern int remove_perl();

#include "plugin_code.h"