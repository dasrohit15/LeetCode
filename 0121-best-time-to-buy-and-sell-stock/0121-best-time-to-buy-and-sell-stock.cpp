class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_profit = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i++){
            if(prices[i] < min_profit){
                min_profit = prices[i];
            }
            else{
                max_profit = max(max_profit, prices[i] - min_profit);
            }
        }
        return max_profit;
        
    }
};