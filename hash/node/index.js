const express = require("express");
const sha256 = require("sha256");

const app = express();

app.listen(3000, () => {
  console.log("It's alive!");
});
