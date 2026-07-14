int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;
    int cheapest_buy = -1;

    for (int i = 0; i < pricesSize; i++) {
        if (cheapest_buy == -1 || cheapest_buy > prices[i])
            cheapest_buy = prices[i];
        else
            continue;

        for (int j = i + 1; j < pricesSize; j++) {
            int profit = prices[j] - prices[i];
            if (profit > max_profit)
                max_profit = profit;
        }
    }

    return max_profit;
}
