#!/bin/bash

# -std=c++11 \

emcc ./src/zip.cpp ./src/lib/zip.c \
-s WASM=1 \
-O3 \
-s FORCE_FILESYSTEM=1 \
-fno-rtti -fno-exceptions \
-s DISABLE_EXCEPTION_CATCHING=1 \
-s EXPORTED_FUNCTIONS='["_readFile"]' \
-s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall']" \
-o zip.out.js \
