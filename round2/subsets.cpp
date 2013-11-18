class Solution {
public:

	void helper(vector<int> &S, int s, int e, vector<vector<int> >& ret, vector<int> &one_set){
		if(s > e){
			ret.push_back(one_set);
			return;
		}
		one_set.push_back(S[s]);
		helper(S, s+1, e, ret, one_set);
		one_set.pop_back();
		helper(S, s+1, e, ret, one_set);
	}

    vector<vector<int> > subsets(vector<int> &S) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
		vector<vector<int> > ret;
		vector<int> one_set;
		if(S.empty()){
			ret.push_back(one_set);
			return ret;
		}
		sort(S.begin(), S.end());
		helper(S, 0, S.size()-1, ret, one_set);
		return ret;
    }
};
