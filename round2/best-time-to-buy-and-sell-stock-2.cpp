class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int size = prices.size();
		int s,e;
		int profit = 0;
		for(s = 0, e = 1; e < size;){
			while(e < size && prices[e] >= prices[e-1])
				e++;
			e--;
			profit += prices[e] - prices[s];
			s = e+1;
			e = s+1;
			
		}
		return profit;
    }
};