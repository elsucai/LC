class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &one, vector<int> &num, int s, int e){
		if(s > e){
			ret.push_back(one);
			return;
		}
		for(int i = s; i <= e; i++){
			swap(num[s], num[i]);
			one.push_back(num[s]);
			helper(ret, one, num, s+1, e);
			one.pop_back();
			swap(num[s], num[i]);
		}
	}

    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > ret;
		vector<int> one;
		helper(ret, one, num, 0, num.size()-1);
		return ret;
    }
};
