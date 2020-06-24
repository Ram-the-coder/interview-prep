/* Solution 1 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        
        int min_price = prices[0], max_profit = 0;
        
        for(int i=1; i<prices.size(); ++i) {
            max_profit = max(max_profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }
        
        return max_profit;
    }
};

/* Solution 2 - Using Maximum Subarray - Kadane's Algorithm */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int cur_max = 0, max_so_far = 0;

        for(int i = 1; i < prices.size(); i++) {
            cur_max = max(0, cur_max += prices[i] - prices[i-1]);
            max_so_far = max(cur_max, max_so_far);
        }
        return max_so_far;
    }
};