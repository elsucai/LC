class Solution {
public:
    int maxProfit(vector<int> &prices) {
		int size = prices.size();
		if(size <= 1)
			return 0;
		int min_fromleft = INT_MAX;
		int max_fromright = INT_MIN;
		int globalmax_p = INT_MIN;
		int cur_p;
		vector<int> first_profit(size+1, 0);     
		vector<int> max_second_profit(size+1, 0);
		for(int i = 0; i < size; i++){
			min_fromleft = min(min_fromleft, prices[i]);
			first_profit[i] = prices[i]-min_fromleft;
		}
		for(int i = size-1; i >= 0; i--){
			max_fromright = max(max_fromright, prices[i]);
			cur_p = max_fromright - prices[i];
			if(globalmax_p < cur_p){
				globalmax_p = cur_p;
			}
			max_second_profit[i] = globalmax_p;
		}

		globalmax_p = INT_MIN;
		for(int i = 0; i < size; i++){
			cur_p = first_profit[i]+max_second_profit[i+1];
			globalmax_p = max(globalmax_p, cur_p);
		}
		return globalmax_p;
    }
};
