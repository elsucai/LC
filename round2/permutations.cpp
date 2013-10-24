class Solution {
public:
	void helper(vector<vector<int> > &ret, vector<int> &num, int s, int e){
		if(s == e){
			ret.push_back(num);
			return;
		}
		for(int i = s; i <= e; i++){
			swap(num[s], num[i]);
			helper(ret, num, s+1, e);
			swap(num[s], num[i]);
		}
	}
	
    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
		helper(ret, num, 0, num.size()-1);
		return ret;
    }
};