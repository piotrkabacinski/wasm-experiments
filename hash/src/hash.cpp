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
  void hash(int *buffer, int length)
  {
    string message;

    for (int i = 0; i < length; i++)
    {
      message += char(buffer[i]);
    }

    string hashed = sha256(message);
    const char *chashed = hashed.c_str();

    call_hashed(&chashed[0], hashed.length());
  }
}
