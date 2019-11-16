#include <fstream>
#include <iostream>
#include <unistd.h>
#include <emscripten.h>

// https://github.com/kuba--/zip
#include "lib/zip.h"

using namespace std;

EM_JS(void, call_getZip, (), {
    getZip();
});

string get_file_name(int *buffer, int length)
{
    string name;

    for (int i = 0; i < length; i++)
    {
        name += char(buffer[i]);
    }

    return name;
}

extern "C"
{
    ifstream file;

    void read_file(int *filesData, int length, int compression_level)
    {
        int i = 0;

        struct zip_t *zip = zip_open("file.zip", compression_level, 'w');

        while (i < length)
        {
            string file_name = get_file_name((int *)filesData[i], filesData[i + 1]);

            zip_entry_open(zip, file_name.c_str());
            {
                zip_entry_fwrite(zip, file_name.c_str());
            }

            zip_entry_close(zip);
            unlink(file_name.c_str());

            i = i + 2;
        }

        zip_close(zip);

        call_getZip();
        file.close();
    }
}
