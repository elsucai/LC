class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &num, int a, int b, int target, int s, int e){
		int cursum;
		vector<int> tmp;
		for(; s < e; ){
			cursum = num[s] + num[e];
			if(cursum == target){
				tmp.clear();
				tmp.push_back(a);
				tmp.push_back(b);
				tmp.push_back(num[s]);
				tmp.push_back(num[e]);
				ret.push_back(tmp);
				s++;
				while(s < e && num[s] == num[s-1])
					s++;
				e--;
				while(e > s && num[e] == num[e+1])
					e--;
			}
			else if(cursum < target){
				s++;
				while(s < e && num[s] == num[s-1])
					s++;
			}
			else{
				e--;
				while(e > s && num[e] == num[e+1])
					e--;
			}
		}
	}

    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > ret;
		int n = num.size();
		if(n < 4)
			return ret;
		int a, b;
		sort(num.begin(), num.end());
		for(a = 0; a <= n-4; ){
			for(b = a+1; b <= n-3; ){
				helper(ret, num, num[a], num[b], target-num[a]-num[b], b+1, n-1);
				// advance b
				b++;
				while(b <= n-3 && num[b] == num[b-1])
					b++;
			}
			// advance a
			a++;
			while(a <= n-4 && num[a] == num[a-1])
				a++;
		}
		return ret;
    }
};
