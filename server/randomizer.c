#include <string.h>

extern "C" {

int callfunc_(int* fp1, int* fp2)
{
    static int c = 0;
    int (*fp)();
    memcpy((char*)&fp, (char*)fp1, 4);
    if (sizeof(void*) > 4)
    {
        memcpy(((char*)&fp)+4, (char*)fp2, 4);
    }
    return fp();
}

}