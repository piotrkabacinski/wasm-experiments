#include <fstream>
#include <iostream>
// #include <emscripten.h>

using namespace std;

extern "C"
{
    ifstream file;

    void readFile()
    {
        cout << "readFile() called" << endl;

        ifstream ifs;
        ifs.open("/fileName");

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
