#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include "get_options.h"

struct programsettings 
{
   int smoothingfactor;
   int auth_enabled;
};

struct programsettings* getProgrammOptions()
{
    system("python framework/readxml.py --xml-file options.xml --result-file result.exe --tag progoptions");
    int fd = open("result.exe", O_RDONLY);
    void* result = malloc(sizeof(programsettings));
    read(fd, result, sizeof(programsettings));
    close(fd);
    return (programsettings*)result;
}

int getsmoothingfactor()
{
    struct programsettings* opt = getProgrammOptions();
    return opt->smoothingfactor;
}

int getAuth_en()
{
    struct programsettings* opt = getProgrammOptions();
    return opt->auth_enabled;
}

char* getPassWord(char* user)
{
    char* buffer = (char*)malloc(strlen("python framework/readxml.py --xml-file options.xml --result-file result.exe --tag  ") + strlen(user));
    sprintf(buffer, "python framework/readxml.py --xml-file options.xml --result-file result.exe --tag %s", user);
    system(buffer);
    struct stat s;
    stat("result.exe", &s);
    char* result = (char*)malloc(s.st_size + 1);
    int fd = open("result.exe", O_RDONLY);
    read(fd, result, s.st_size);
    result[s.st_size] = 0;
    close(fd);
    return result;
}

char* getPlugIn()
{
    system("python framework/readxml.py --xml-file options.xml --result-file result.exe --tag plugin");
    struct stat s;
    stat("result.exe", &s);
    char* result = (char*)malloc(s.st_size + 1);
    int fd = open("result.exe", O_RDONLY);
    read(fd, result, s.st_size);
    result[s.st_size] = 0;
    close(fd);
    return result;
}

int md5compare(const char* a, const char* b)
{
    char* buffer = (char*)malloc(strlen("python framework/md5cmp.py ") + strlen(a) + strlen(b) + 10);
    sprintf(buffer, "python framework/md5cmp.py %s %s", a, b);
    int result = system(buffer);
    free(buffer);
    return result;
}