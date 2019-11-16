#!/bin/bash

# -03:
# https://emscripten.org/docs/optimizing/Optimizing-Code.html

# -fno-rtti -fno-exceptions:
# https://emscripten.org/_sources/docs/optimizing/Optimizing-Code.txt:
# "C++ run-time type info support (dynamic casts, etc.) adds overhead that is sometimes not needed.
# For example, in Box2D neither rtti nor exceptions are needed, and if you build the source files with `-fno-rtti -fno-exceptions`
# then it shrinks the output by 15% (!)"

# -s DISABLE_EXCEPTION_CATCHING=1:
# https://emscripten.org/docs/optimizing/Optimizing-Code.html#c-exceptions

emcc ./src/hash.cpp ./src/sha256/sha256.cpp \
-s WASM=1 \
-O3 \
-fno-rtti -fno-exceptions \
-s DISABLE_EXCEPTION_CATCHING=1 \
-s EXPORTED_FUNCTIONS='["_malloc", "_hash", "_free"]' \
-s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall', 'getValue']" \
-o hash.out.js \
-std=c++14 \
