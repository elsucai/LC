class Solution {
public:

	void helper(vector<int> &S, vector<bool> &flag, vector<vector<int> > &ret, int s, int e){
		if(s > e){
			// populate current subset to ret
			vector<int> tmp;
			for(int i = 0; i < flag.size(); i++){
				if(flag[i])
					tmp.push_back(S[i]);
			}
			ret.push_back(tmp);
			return;
		}
		// set current flag
		flag[s] = true;
		helper(S, flag, ret, s+1, e);
		// reset current flag
		flag[s] = false;
		helper(S, flag, ret, s+1, e);
	}


    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		vector<vector<int> > ret;
		if(S.empty()){
			vector<int> vain;
			ret.push_back(vain);
			return ret;
		}
		sort(S.begin(), S.end());
		vector<bool> flag(S.size(), false);
		helper(S, flag, ret, 0, S.size()-1);
		return ret;
    }
};
