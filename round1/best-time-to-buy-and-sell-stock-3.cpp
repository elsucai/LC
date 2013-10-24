class Solution {
public:

	int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(prices.empty())
			return 0;
		int n = prices.size();
		
		int* mp_left = new int[n+1];
		int* mp_right = new int[n+1];
		
		int min = INT_MAX;
		int max = 0;
		int cur_max;
		
		for(int i = 0; i < n+1; i++)
			mp_left[i] = mp_right[i] = 0;
		
		for(int i = 0; i < n; i++){
			if(prices[i] < min)
				min = prices[i];
			cur_max = prices[i] - min;
			if(max < cur_max){
				max = cur_max;
			}
			mp_left[i] = max;
		}
		
		max = 0;
		int rmax = INT_MIN;
		for(int i = n-1; i >= 0; i--){
			if(prices[i] > rmax)
				rmax = prices[i];
			cur_max = rmax - prices[i];
			if(cur_max > max)
				max = cur_max;
			mp_right[i] = max;
		}

		max = 0;
		for(int i = 0; i < n; i++){
			cur_max = mp_left[i] + mp_right[i+1];
			if(cur_max > max)
				max = cur_max;
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
