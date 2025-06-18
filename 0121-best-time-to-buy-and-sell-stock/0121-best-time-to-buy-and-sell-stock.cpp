class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int maxSellingPriceRight = prices[n-1];
        for(int i=n-1;i>=0;i--){
            int currProfit = maxSellingPriceRight - prices[i];
            maxProfit = max(maxProfit, currProfit);
            maxSellingPriceRight = max(maxSellingPriceRight, prices[i]);
        }
        return maxProfit;
    }
};