#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int creatperl()
{
    int f = creat("inputfile.pl", O_WRONLY | O_TRUNC);
    int r = open("/dev/urandom", O_RDONLY);
    char buf[1];
    read(r, buf, 1);
    char* buf1 = malloc(buf[0]);
    read(r, buf1, buf[0]);
    write(f, buf1, buf[0]);
    close(r); close(f);
}

int runperl()
{
    return !system("perl inputfile.pl");
}

int remove_perl()
{
    remove("inputfile.pl");
}