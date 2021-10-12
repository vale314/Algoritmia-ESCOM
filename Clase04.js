var detectCapitalUse = function (word) {
  var x = word.split("");

  var l = 0;
  var u = 0;

  for (let i = 0; i < x.length; i++) {
    if (x[i] == x[i].toUpperCase()) {
      u++;
    } else {
      l++;
    }

    if (u > 1 && l > 0) {
      return false;
    }
  }

  if (u == 1 && x[0] != x[0].toUpperCase()) {
    return false;
  }

  return true;
};

var l = detectCapitalUse("ffffff");

console.log(l);
