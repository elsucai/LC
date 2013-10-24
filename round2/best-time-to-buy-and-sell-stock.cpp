class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		
		if(prices.empty())
			return 0;
		int size = prices.size();

		int leftmin = INT_MAX;
		int curprofit;
		int maxprofit = INT_MIN;

		for(int i = 0; i < size; i++){
			if(leftmin > prices[i])
				leftmin = prices[i];
			curprofit = prices[i] - leftmin;
			if(maxprofit < curprofit)
				maxprofit = curprofit;
		}
		return maxprofit;
    }
};
