# Hello, WASM!

Welcome to [WebAssembly](https://webassembly.org/) experiments repo where I'm going to store my humble projects in this technology.

## Installation

For now output WASM files are included in the repository. If you would like to play with source C/C++ files, you need to install [emscripten](https://emscripten.org/) complier first.

For more details, go to [emscripten docs](https://emscripten.org/docs/getting_started/downloads.html).

```bash
$ git clone https://github.com/emscripten-core/emsdk.git
$ ./emsdk/emsdk install latest
$ ./emsdk/emsdk activate latest

# Update certificate if need:
$ open /Applications/Python\ 3.7/Install\ Certificates.command

# Setup local envs and you're ready to go:
$ source ../emsdk/emsdk_env.sh --build=Release
```

## Build and compile

For now here's one simple project `hash`, which main goal is to use existing C++ [sha256 library](http://www.zedwood.com/article/cpp-sha256-function). All it does it converts string to hashed value processed by WASM.

```bash
$ make
```

...and launch local server from `./hash` directory.

## Licence

MIT
