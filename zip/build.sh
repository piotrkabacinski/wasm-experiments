#!/bin/bash

# -std=c++11 \

emcc ./src/zip.cpp ./src/lib/zip.c \
-s WASM=1 \
-O3 \
-s FORCE_FILESYSTEM=1 \
-s ALLOW_MEMORY_GROWTH=1 \
-fno-rtti -fno-exceptions \
-s DISABLE_EXCEPTION_CATCHING=1 \
-s EXPORTED_FUNCTIONS='["_create_zip"]' \
-s EXTRA_EXPORTED_RUNTIME_METHODS="['ccall', 'getValue']" \
-o zip.out.js \
