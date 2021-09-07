var maxProfit = function (prices) {
  let posMenor = 0;
  let menor = 0;

  for (let i = 0; i < prices.length; i++) {
    for (let j = i + 1; j < prices.length; j++) {
      if (prices[j] - prices[i] > menor) {
        menor = prices[j] - prices[i];
        posMenor = j + 1;
      }
    }
  }
  console.log(menor);
  return menor > 0 ? posMenor : 0;
};

let variable = [1, 2];

console.log(maxProfit(variable));
