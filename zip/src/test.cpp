// g++ -x c ./lib/zip.c  -x c++ test.cpp

#include <fstream>
#include <iostream>

#include "lib/zip.h"

using namespace std;

int main()
{
    ifstream file;

    string fileName = "test.txt";

    ifstream ifs;
    ifs.open("./" + fileName);

    filebuf *fbuf = ifs.rdbuf();
    size_t size = fbuf->pubseekoff(0, ifs.end, ifs.in);

    if (!ifs.is_open())
    {
        cout << "Failed to open file" << endl;
    }
    else
    {
        cout << "Opened" << endl;

        struct zip_t *zip = zip_open("foo2.zip", 1, 'w');

        zip_entry_open(zip, fileName.c_str());
        {
            // const char *buf = "Some data here...\0";
            // zip_entry_write(zip, buf, strlen(buf));
            zip_entry_write(zip, fbuf, size);
        }
        zip_entry_close(zip);

        cout << zip_entry_size(zip) << endl;
        cout << "Pointer:" << &zip << endl;

        ifstream zipFile;
        zipFile.open("foo.zip");

        if (ifs.is_open())
        {
            cout << "Zip file exists!" << endl;
        }
        else
        {
            cout << "Problems with zip file" << endl;
        }
    }

    ifs.close();

    return 0;
}
