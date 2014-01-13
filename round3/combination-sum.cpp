class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &cand, vector<int> &freq, vector<int> &one, int target, int s, int e){
		if(target == 0){
			ret.push_back(one);
			return;
		}
		if(s > e || target < 0)
			return;
		for(int i = 1; i <= freq[s]; i++)
			one.push_back(cand[s]);
		for(int i = freq[s]; i>= 1; i--){
			helper(ret, cand, freq, one, target-i*cand[s], s+1, e);
			one.pop_back();
		}
		helper(ret, cand, freq, one, target, s+1, e);
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > ret;
		set<int> s;
		set<int>::iterator it;
		vector<int> cand;
		vector<int> freq;
		for(int i = 0; i < candidates.size(); i++)
			s.insert(candidates[i]);

		for(it = s.begin(); it != s.end(); it++)
			cand.push_back(*it);
		for(int i = 0; i < cand.size(); i++){
			freq.push_back(target/cand[i]);
		}

		vector<int> one_solution;
		helper(ret, cand, freq, one_solution, target, 0, cand.size()-1);
		return ret;
    }
};
