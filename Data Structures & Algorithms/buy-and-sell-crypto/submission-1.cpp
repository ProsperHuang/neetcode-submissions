class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = 10000;
        int max_profit = 0;
        for (int i = 0; i<prices.size(); i++){
            if (prices[i]<lowest){
                lowest = prices[i];
            }
            else{
                if (prices[i] - lowest > max_profit){
                    max_profit = prices[i] - lowest;
                }
            }
        }
        return max_profit;
    }
};
