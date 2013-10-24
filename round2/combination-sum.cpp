class Solution {
public:
	void insert(vector<vector<int> > &ret, vector<int> &c, vector<int> &flag, int e){
		vector<int> tmp;
		for(int i = 0; i <= e; i++){
			for(int n = 1; n <= flag[i]; n++){
				tmp.push_back(c[i]);
			}
		}
		ret.push_back(tmp);
	}
	
	void helper(vector<vector<int> > &ret, vector<int> &c, vector<int> &freq, vector<int> &flag, int target, int s, int e){
		if(target == 0){
			insert(ret, c, flag, e);
			return;
		}
		if(s > e || target < 0)
			return;
		
		//set flag[s]
		for(int i = freq[s]; i >= 0; i--){
			flag[s] = i;
			helper(ret, c, freq, flag, target-i*c[s], s+1, e);
		}
	}
	
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        set<int> tmp;
		vector<vector<int> > ret;
		vector<int> c;
		vector<int> freq;
		
		for(int i = 0; i < candidates.size(); i++){
			if(candidates[i] != 0)
				tmp.insert(candidates[i]);
		}
		
		set<int>::iterator it;
		for(it = tmp.begin(); it != tmp.end(); it++)
			c.push_back(*it);
		
		// c is already sorted
		int size = c.size();
		for(int i = 0; i < size; i++)
			freq.push_back(target/c[i]);
		
		vector<int> flag(size, 0);
		
		helper(ret, c, freq, flag, target, 0, size-1);
		return ret;
    }
};