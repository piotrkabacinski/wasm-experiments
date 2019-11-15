#include <fstream>
#include <iostream>
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

    void read_file(int *filesData, int length)
    {
        // cout << length << endl;

        // struct zip_t *zip = zip_open("file.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');

        for (int i = 0; i < length; i++)
        {
            string file_name = get_file_name((int *)filesData[i], (int)filesData[i + 1]);

            cout << i << file_name << endl;

            // char *file_name = get_file_name(&filesData[i], filesData[++i]).c_str();
            // zip_entry_open(zip, file_name);
            // {
            //     zip_entry_fwrite(zip, file_name);
            // }
        }

        // zip_entry_close(zip);
        // zip_close(zip);

        // call_getZip();
        // file.close();

        // string file_name = get_file_name(buffer, length);
        // ifstream file("/" + file_name);

        // if (!file.is_open())
        // {
        //     cout << "Failed to open file" << endl;
        // }
        // else
        // {
        //     struct zip_t *zip = zip_open("file.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');

        //     zip_entry_open(zip, file_name.c_str());
        //     {
        //         zip_entry_fwrite(zip, file_name.c_str());
        //     }
        //     zip_entry_close(zip);
        //     zip_close(zip);

        //     call_getZip();
        // }

        // file.close();
    }
}
