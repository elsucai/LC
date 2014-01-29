class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &one, vector<int> &a, int s, int e){
		if(s > e){
			ret.push_back(one);
			return;
		}
		one.push_back(a[s]);
		helper(ret, one, a, s+1, e);
		one.pop_back();
		helper(ret, one, a, s+1, e);
	}

    vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > ret;
		vector<int> one;
		if(S.empty()){
			ret.push_back(one);
			return ret;
		}

		sort(S.begin(), S.end());
		helper(ret, one, S, 0, S.size()-1);
		return ret;
    }
};
