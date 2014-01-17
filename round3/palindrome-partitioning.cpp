class Solution {
public:
	void helper(vector<vector<string> > &ret, vector<vector<bool> > &D, vector<string> &one, string &s, int i, int j){
		if(i > j){
			ret.push_back(one);
			return;
		}
		for(int x = i; x <= j; x++){
			if(D[i][x]){
				one.push_back(s.substr(i, x-i+1));
				helper(ret, D, one, s, x+1, j);
				one.pop_back();
			}
		}
	}

    vector<vector<string>> partition(string s) {
		vector<vector<string> > ret;
		if(s.size() <= 1){
			ret.push_back(vector<string>(1, s));
			return ret;
		}
		int n = s.size();
		vector<string> one;
		vector<vector<bool> > D(n, vector<bool>(n, true));
		int i, j;
		for(i = n-2; i >= 0; i--){
			for(j = n-1; j > i; j--){
				D[i][j] = s[i] == s[j] ? D[i+1][j-1] : false;
			}
		}

		helper(ret, D, one, s, 0, n-1);
		return ret;
    }
};
