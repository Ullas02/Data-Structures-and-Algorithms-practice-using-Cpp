#include <iostream>
#include <vector>

using namespace std;

int buyAndSell(vector<int> &prices)
{
    int maxProfit = 0, bestBuy = prices[0];
    int size = prices.size();

    for (int i = 1; i < size; i++)
    {
        if (prices[i] > bestBuy)
        {
            maxProfit = max(maxProfit, (prices[i] - bestBuy));
        }

        bestBuy = min(bestBuy, prices[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> stock_prices = {7, 1, 5, 3, 6, 4};
    int res = buyAndSell(stock_prices);
    cout << res << endl;
    return 0;
}