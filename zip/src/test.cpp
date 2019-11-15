// g++ -x c ./lib/zip.c  -x c++ test.cpp

#include <fstream>
#include <iostream>

#include "lib/zip.h"

using namespace std;

int main()
{
    struct zip_t *zip = zip_open("foo.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');

    zip_entry_open(zip, "test_files/hello.txt");
    {
        const char *buf = "Some data here...\0";
        zip_entry_write(zip, buf, strlen(buf));
    }
    zip_entry_close(zip);
    zip_close(zip);

    return 0;
}
