class Solution {
public:
    int maxProfit(vector<int> &prices) {
		// greedy algo.
		int profit = 0;
		int s, e;
		int size = prices.size();
		if(size <= 1)
			return 0;
		for(s = 0, e = s+1; e < size; ){
			// find next sell
			while(e < size && prices[e] >= prices[e-1])
				e++;
			//[s, e-1]
			profit += prices[e-1]-prices[s];
			s = e;
			e = e+1;
		}
		return profit;
    }
};
