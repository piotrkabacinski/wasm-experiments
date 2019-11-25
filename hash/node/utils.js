function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}

function randomString(length) {
  let result = "";
  const characters =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
  const charactersLength = characters.length;
  for (let i = 0; i < length; i++) {
    result += characters.charAt(Math.floor(Math.random() * charactersLength));
  }
  return result;
}

function countBlocks(array, block = 10) {
  const blocks = array.length / block;

  if (blocks % 1 !== 0) {
    return Number(blocks.toFixed()) + 1;
  }

  return blocks;
}

function spliced(array, block = 10) {
  const blocks = countBlocks(array, block);

  const spliced = {};

  for (let i = 0; i < blocks; i++) {
    spliced[i] = array.splice(0, block);
  }

  return spliced;
}

module.exports = {
  randomString,
  getRandomInt,
  countBlocks,
  spliced
};
