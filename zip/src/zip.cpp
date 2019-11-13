#include <fstream>
#include <iostream>

#include "lib/zip.h"

using namespace std;

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

        ifstream ifs;
        ifs.open("/" + fileName);

        filebuf *fbuf = ifs.rdbuf();
        size_t size = fbuf->pubseekoff(0, ifs.end, ifs.in);

        if (!ifs.is_open())
        {
            cout << "Failed to open file" << endl;
        }
        else
        {
            cout << "Opened" << endl;

            struct zip_t *zip = zip_open("foo.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');

            zip_entry_open(zip, fileName.c_str());
            {
                zip_entry_write(zip, fbuf, size);
            }
            zip_entry_close(zip);

            cout << zip_entry_size(zip) << endl;
            cout << "Pointer:" << &zip << endl;
        }

        ifs.close();
    }
}
