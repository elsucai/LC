class Solution {
public:
	void helper(vector<string> &ret, string &one, int rl, int rr, int s, int e){
		if(rl == 0 && rr == 0){
			ret.push_back(one);
			return;
		}
		if(s > e || rl < 0 || rr < 0 || rl > rr)
			return;
		one += "(";
		helper(ret, one, rl-1, rr, s+1, e);
		one = one.substr(0, one.size()-1);
		one += ")";
		helper(ret, one, rl, rr-1, s+1, e);
		one = one.substr(0, one.size()-1);
	}

    vector<string> generateParenthesis(int n) {
		vector<string> ret;
		if(n <= 0)
			return ret;
		int rl, rr;
		rl = rr = n;
		string one = "";
		helper(ret, one, rl, rr, 0, 2*n-1);
		return ret;
    }
};
