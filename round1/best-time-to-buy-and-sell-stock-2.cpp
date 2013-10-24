#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

	int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		// try greedy approach
		
		if(prices.empty())
			return 0;
		int n = prices.size();
		int max = 0;
		int s, e;
		for(s = 0 ; s < n; ){
			while(s+1 < n && prices[s] >= prices[s+1])
				s++;
			for(e = s+1; e < n && prices[e] > prices[e-1]; e++)
				;
			if(e-1 < n && s < n)
				max += prices[e-1] - prices[s];
			s = e;
		}

		return max;
	}	
};

/*
int main(){
	Solution s;
	vector<int> p;
	p.push_back(1);
	cout<<s.maxProfit(p)<<endl;
	return 0;
}
*/
