// $ node index.js 100
const sha256 = require("sha256");
const Module = require("../hash.out");
const fs = require("fs");
const { randomString, getRandomInt, spliced } = require("./utils");

const DIVIDE = 1000000;
const [, , iterations = "1"] = process.argv;

const times = {
  sha256: [],
  wasm: []
};

const calculateAverage = input =>
  parseFloat(input.reduce((acc, value) => acc + value) / input.length).toFixed(
    5
  );

let wasmStart;

const sha256test = message => {
  const start = process.hrtime();
  const hashedValue = sha256(message);

  times.sha256.push(process.hrtime(start)[1] / DIVIDE);
};

global.hashed = (pointer, length) => {
  times.wasm.push(process.hrtime(wasmStart)[1] / DIVIDE);
  //   let hashedValue = "";
  //   for (let i = 0; i < length; i++) {
  //     const char = Module.getValue(pointer + i, "i8");
  //     hashedValue += String.fromCharCode(char);
  //   }

  //   console.log(hashed);
};

const wasmTest = message => {
  const encoded = [];

  for (let i = 0; i < message.length; i++) {
    encoded.push(message.charCodeAt(i));
  }

  const decoded = new Uint32Array(encoded);

  const buffer = Module._malloc(decoded.length * decoded.BYTES_PER_ELEMENT);

  Module.HEAP32.set(decoded, buffer >> 2);

  wasmStart = process.hrtime();

  Module.ccall("hash", ["number", "number"], "void", [buffer, decoded.length]);

  Module._free(buffer);
};

Module.onRuntimeInitialized = () => {
  for (let i = 0; i < Number(iterations); i++) {
    const message = randomString(getRandomInt(5, 20));

    sha256test(message);
    wasmTest(message);
  }

  console.log(
    "sha256:",
    calculateAverage(times.sha256),
    "\n",
    "wasm:",
    calculateAverage(times.wasm)
  );

  fs.appendFile(
    `results_sha256.json`,
    JSON.stringify({ sha256: spliced(times.sha256, 1000) }),
    err => {
      if (err) throw err;
      console.log("Detailed sha256 results saved 🎉");
    }
  );

  fs.appendFile(
    `results_wasm.json`,
    JSON.stringify({ wasm: spliced(times.wasm, 1000) }),
    err => {
      if (err) throw err;
      console.log("Detailed wasm results saved 🎉");
    }
  );
};
