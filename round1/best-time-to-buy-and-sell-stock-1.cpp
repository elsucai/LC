class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		int max = INT_MIN;
		int min = INT_MAX;
		int cur_profit;

		if(prices.empty())
			return 0;
		for(int i = 0; i < prices.size(); i++){
			//update curmin
			min = prices.at(i) < min ? prices.at(i) : min;
			cur_profit = prices.at(i) - min;
			max = cur_profit > max ? cur_profit : max;
		}

		return max;
    }
};
