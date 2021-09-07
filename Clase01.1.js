var maxProfit = function (prices) {
  let min = Number.MAX_SAFE_INTEGER;
  let profit = 0;

  for (let i = 0; i < prices.length; i++) {
    console.log("min: " + min);
    min = Math.min(prices[i], min);
    console.log("prices[i]: " + prices[i] + " min: " + min);
    profit = Math.max(profit, prices[i] - min);
    console.log("profit: " + profit);

    console.log("\n");
  }

  return profit;
};

let variable = [7, 1, 5, 3, 6, 4];

console.log(maxProfit(variable));
