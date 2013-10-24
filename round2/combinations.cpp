class Solution {
public:
	void push_one(vector<vector<int> > &ret, vector<bool> &flag, int e){
		vector<int> tmp;
		for(int i = 0; i <= e; i++){
			if(flag[i])
				tmp.push_back(i+1);
		}
		ret.push_back(tmp);
	}
	
	void helper(vector<vector<int> > &ret, vector<bool> &flag, int s, int e, int k){

		if(k == 0){
			push_one(ret, flag, e);
			return;
		}
		
		if(s > e)
			return;
		
		// try to set flag[s]
		flag[s] = true;
		helper(ret, flag, s+1, e, k-1);
		// unset flag[s]
		flag[s] = false;
		helper(ret, flag, s+1, e, k);
	}
	
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
		if(n <= 0 || k <= 0 || k > n)
			return ret;
		vector<bool> flag(n, false);
		
		helper(ret, flag, 0, n-1, k);
		
		return ret;
    }
};