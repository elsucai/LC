class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int max_p = 0;
		int min_sofar = INT_MAX;
		int cur_profit;

		for(int i = 0; i < prices.size(); i++){
			min_sofar = min(min_sofar, prices[i]);
			cur_profit = prices[i] - min_sofar;
			if(max_p < cur_profit){
				max_p = cur_profit;
			}
		}
		return max_p;
    }
};
