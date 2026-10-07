class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = std::numeric_limits<int>::max();
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < lowest) {
                //update the lowest price so far
                lowest = prices[i];
            }
            //potential profit if selling today
            int profit = prices[i] - lowest;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }

        return maxProfit;
    }
};
