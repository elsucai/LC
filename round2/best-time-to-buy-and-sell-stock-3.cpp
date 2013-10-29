class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(prices.empty())
			return 0;
		int size = prices.size();
		vector<int> best_sell_now(size, 0);
		vector<int> max_profit_starting_now(size, 0);
		int left_min = INT_MAX;
		int right_max = -1;
		int max_profit = 0;
		int cur_max_profit = 0;
		int global_right_max_profit = 0;
		
		for(int i = 0; i < size; i++){
			left_min = min(left_min, prices[i]);
			best_sell_now[i] = prices[i] - left_min;
		}
		
		for(int i = size-1; i >= 0; i--){
			right_max = max(right_max, prices[i]);
			cur_max_profit = right_max - prices[i];
			global_right_max_profit = max(global_right_max_profit, cur_max_profit);
			max_profit_starting_now[i] = global_right_max_profit;
		}
		
		global_right_max_profit = 0;
		for(int i = 0; i < size-1; i++){
			cur_max_profit = best_sell_now[i] + max_profit_starting_now[i+1];
			global_right_max_profit = max(global_right_max_profit, cur_max_profit);
		}
		cur_max_profit = best_sell_now[size-1];
		global_right_max_profit = max(global_right_max_profit, cur_max_profit);
		return global_right_max_profit;
    }
};