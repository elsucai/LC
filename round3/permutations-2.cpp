class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &one, vector<int> &num, int s, int e){
		if(s > e){
			ret.push_back(one);
			return;
		}
		unordered_set<int> processed;
		
		for(int i = s; i <= e; i++){
			if(processed.find(num[i]) != processed.end())
				continue;
			processed.insert(num[i]);
			swap(num[s], num[i]);
			one.push_back(num[s]);
			helper(ret, one, num, s+1, e);
			one.pop_back();
			swap(num[s], num[i]);
		}
	}

    vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > ret;
		vector<int> one;
		helper(ret, one, num, 0, num.size()-1);
		return ret;
    }
};
