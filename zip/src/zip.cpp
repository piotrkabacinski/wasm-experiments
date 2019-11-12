#include <fstream>
#include <iostream>
// #include <emscripten.h>

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

        cout << "/" + fileName << endl;

        if (!ifs.is_open())
        {
            cout << "Failed to open" << endl;
        }
        else
        {
            cout << "Opened" << endl;
        }

        ifs.close();
    }
}
