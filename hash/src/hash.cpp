#include <iostream>
#include <string>
#include <emscripten.h>

#include "./sha256/sha256.h"

using namespace std;

EM_JS(void, call_hashed, (const char *pHashed, int length), {
  hashed(pHashed, length);
});

extern "C"
{
  void sum(int *buffer, int length)
  {
    string message;

    for (int i = 0; i < length; i++)
    {
      const char *letter = new char(buffer[i]);
      message += letter;
    }

    string hashed = sha256(message);
    const char *chashed = hashed.c_str();

    call_hashed(&chashed[0], hashed.length());
  }
}
