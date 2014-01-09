class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &one_set, vector<int> &val, vector<int> &freq, int s, int e){
		if(s > e){
			ret.push_back(one_set);
			return;
		}
		int cur_val = val[s];

		for(int n = freq[s]; n >= 1; n--){
			one_set.push_back(cur_val);
		}

		for(int n = freq[s]; n >= 1; n--){
			helper(ret, one_set, val, freq, s+1, e);
			one_set.pop_back();
		}
		helper(ret, one_set, val, freq, s+1, e);
	}

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
	
		vector<vector<int> >ret;
		// a freq table
		map<int, int> hm;
		vector<int> val;
		vector<int> freq;
		
		if(S.empty()){
			ret.push_back(vector<int> ());
			return ret;
		}
		
		for(int i = 0; i < S.size(); i++)
			hm[S[i]]++;
		
		// fill the freq table
		map<int, int>::iterator it;

		for(it = hm.begin(); it != hm.end(); it++){
			val.push_back(it->first);
			freq.push_back(it->second);
		}
		vector<int> one_set;
		helper(ret, one_set, val, freq, 0, val.size()-1);
		return ret;
    }
};
