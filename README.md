# Hello, WASM! 👋

Welcome to [Web Assembly](https://webassembly.org/) experiments repo with my humble test projects in this technology.

## 🐙 Setup

Output WASM files are included in the repository. If you would like to play with source C/C++ files you need to install [Emscripten](https://emscripten.org/) complier first.

For more details, go to [Emscripten docs](https://emscripten.org/docs/getting_started/downloads.html).

```bash
$ git clone https://github.com/emscripten-core/emsdk.git
$ ./emsdk/emsdk install latest
$ ./emsdk/emsdk activate latest

# Update certificate if need:
$ open /Applications/Python\ 3.7/Install\ Certificates.command

# Setup local envs and you're ready to go:
$ source ../emsdk/emsdk_env.sh --build=Release
```

```bash
# Compile all projects:
$ make

# Compile specific one:
$ make sha256
$ make createZip
```

...and launch local server in selected project's directory.

## Projects ✨

1. "sha256"

Convert input value to [sha256 hash](https://en.wikipedia.org/wiki/SHA-2) using C++ [library](http://www.zedwood.com/article/cpp-sha256-function).

2. "ZIP creator"

Create ZIP package (using C [Zip library](https://github.com/kuba--/zip)) with provided files via browser's File API.

## Licence

MIT
