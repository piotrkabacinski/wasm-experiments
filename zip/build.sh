#!/bin/bash

emcc ./src/hash.cpp ./src/sha256/sha256.cpp \
-s WASM=1 \
-O3 \
-s FORCE_FILESYSTEM=1
-fno-rtti -fno-exceptions \
-s DISABLE_EXCEPTION_CATCHING=1 \
-s EXPORTED_FUNCTIONS='["_malloc", "_sum", "_free"]' \
-s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap', 'getValue']" \
-o hash.out.js \
-std=c++14 \