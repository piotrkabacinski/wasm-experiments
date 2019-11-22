const express = require("express");
const sha256 = require("sha256");
const Module = require("../hash.out");

const app = express();

const divide = 1000000;
const [, , message, iterations] = process.argv;

let wasmStart;

(() => {
  const sha256Start = process.hrtime();
  const hashedValue = sha256(message);

  console.log(
    "sha256:",
    hashedValue,
    `${process.hrtime(sha256Start)[1] / divide}ms`
  );
})();

global.hashed = (pointer, length) => {
  let hashedValue = "";

  for (let i = 0; i < length; i++) {
    const char = Module.getValue(pointer + i, "i8");
    hashedValue += String.fromCharCode(char);
  }

  console.log(
    "wasm:",
    hashedValue,
    `${process.hrtime(wasmStart)[1] / divide}ms`
  );
};

const main = () => {
  Module.onRuntimeInitialized = () => {
    const encoded = [];

    for (let i = 0; i < message.length; i++) {
      encoded.push(message.charCodeAt(i));
    }

    const decoded = new Uint32Array(encoded);

    const buffer = Module._malloc(decoded.length * decoded.BYTES_PER_ELEMENT);

    Module.HEAP32.set(decoded, buffer >> 2);

    wasmStart = process.hrtime();

    Module.ccall("hash", ["number", "number"], "void", [
      buffer,
      decoded.length
    ]);

    Module._free(buffer);
  };
};

app.listen(3000, main);
