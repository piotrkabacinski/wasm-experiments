#include <fstream>
#include <iostream>
#include <emscripten.h>

#include "lib/zip.h"

using namespace std;

EM_JS(void, call_getZip, (), {
    getZip();
});

string getFileName(int *buffer, int length)
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

    void readFile(int *buffer, int length)
    {
        string fileName = getFileName(buffer, length);

        ifstream file;
        file.open("/" + fileName);

        filebuf *fbuf = file.rdbuf();
        size_t size = fbuf->pubseekoff(0, file.end, file.in);

        if (!file.is_open())
        {
            cout << "Failed to open file" << endl;
        }
        else
        {
            struct zip_t *zip = zip_open("foo.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');

            zip_entry_open(zip, fileName.c_str());
            {
                // zip_entry_write(zip, fbuf, size);
                const char *buf = "Some data here...\0";
                zip_entry_write(zip, buf, strlen(buf));
            }
            zip_entry_close(zip);
            zip_close(zip);

            call_getZip();
        }

        file.close();
    }
}
