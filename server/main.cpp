#define forever while(1)
#include "framework/get_options.h"
#include "framework/pluginhandling.h"
#include <iostream>
#include "serverserver.h"
#include "Communicator.h"

DecisionMaker* DecisionMaker::dm = NULL;

int main(int argc, char* argv[])
{
    DecisionMaker::init(getsmoothingfactor());
    int (*fp)() = get_plugin(getPlugIn());
    DecisionMaker::instance()->fp = fp;
    Server s;
    forever
    {
        Communicator comm(fp, getAuth_en(), s.runonce());
        comm.onemessage();
    }
    return 0;
}
