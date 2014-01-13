class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &one, vector<int> &cand, vector<int> &freq, int target, int s, int e){
		if(target == 0){
			ret.push_back(one);
			return;
		}
		if(s > e)
			return;
		int val = cand[s];
		for(int i = 1; i <= freq[s]; i++)
			one.push_back(val);
		for(int i = freq[s]; i >= 1; i--){
			helper(ret, one, cand, freq, target-i*val, s+1, e);
			one.pop_back();
		}
		helper(ret, one, cand, freq, target, s+1, e);
	}

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > ret;
		map<int, int> hm;
		map<int, int>::iterator it;

		vector<int> cand;
		vector<int> freq;

		for(int i = 0; i < num.size(); i++)
			hm[num[i]]++;
	
		for(it = hm.begin(); it != hm.end(); it++){
			cand.push_back(it->first);
			freq.push_back(it->second);
		}

		vector<int> one;
		helper(ret, one, cand, freq, target, 0, freq.size()-1);
		return ret;
    } 
};
