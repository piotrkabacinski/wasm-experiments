#include <fstream>
#include <iostream>
#include <emscripten.h>

#include "lib/zip.h"

using namespace std;

EM_JS(void, call_getZip, (ifstream pFile, size_t length), {
    getZip(pFile, length);
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
            cout << "File opened!" << endl;
            call_getZip(file, size);

            struct zip_t *zip = zip_open("foo.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');

            zip_entry_open(zip, fileName.c_str());
            {
                zip_entry_write(zip, fbuf, size);
            }
            zip_entry_close(zip);
            zip_close(zip);

            // cout << zip_entry_size(zip) << endl;
            // cout << "Pointer:" << &zip << endl;

            ifstream zipFile;
            zipFile.open("foo.zip");

            if (zipFile.is_open())
            {
                cout << "Zip file exists!" << endl;

                filebuf *zipFileBuf = zipFile.rdbuf();
                size_t zipFileSize = zipFileBuf->pubseekoff(0, file.end, file.in);

                // call_getZip(zipFileBuf, zipFileSize);
                // call_getZip(zip, zipFileSize);
            }
            else
            {
                cout << "Problems with zip file" << endl;
            }

            zipFile.close();
        }

        file.close();
    }
}
