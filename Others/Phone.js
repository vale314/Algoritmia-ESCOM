/**
 * @param {string} digits
 * @return {string[]}
 */

var phone = {
  1: [],
  2: ["a", "b", "c"],
  3: ["d", "e", "f"],
  4: ["g", "h", "i"],
  5: ["j", "k", "l"],
  6: ["m", "n", "o"],
  7: ["p", "q", "r", "s"],
  8: ["t", "u", "v"],
  9: ["w", "x", "y", "z"],
};

var letterCombinations = function (digits) {
  const result = [];

  const walk = (i, prefix) => {
    // console.log(i, prefix)

    // cuando i sea igual al tam de nuestros digitos pues lo metemos XD
    if (i > digits.length - 1) {
      result.push(prefix);
      return;
    }

    // el digito en el que va esta recursion
    const digit = digits[i];

    // el telefono en el digitio x, mapea todos los digitos
    phone[digit].map((char) => {
      //llama recursivamente y camina al siguiente digito, y concatena lo que llevamos con el caracter actual
      walk(i + 1, prefix + char);
    });
  };

  // Si es mayor los digitos a 0
  if (digits.length > 0) {
    walk(0, "");
  }

  //enviamos nuestro resultado XD
  return result;
};
