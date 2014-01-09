class Solution {
public:
	bool helper(string &s1, int i1, int j1, string &s2, int i2, int j2){
		if(i1 == j1)
			return s1[i1] == s2[i2];

		// check if char freq is the same
		unordered_map<char, int> hm;
		for(int i = i1; i <= j1; i++){
			hm[s1[i]]++;
		}
		for(int i = i2; i <= j2; i++){
			if(hm.find(s2[i]) == hm.end() || hm[s2[i]] == 0)
				return false;
			hm[s2[i]]--;
		}

		int e;
		bool ll, rr, lr, rl;
		int lsize, rsize;
		for(e = i1; e < j1; e++){
			lsize = e-i1+1;
			rsize = j1-e;
			ll = helper(s1, i1, i1+lsize-1, s2, i2, i2+lsize-1);
			if(ll){
				rr = helper(s1, e+1, j1, s2, i2+lsize, j2);
				if(ll && rr){
					return true;
				}
			}
			else{
				lr = helper(s1, i1, e, s2, 1+j2-lsize, j2);
				if(lr){
					rl = helper(s1, e+1, j1, s2, i2, i2+rsize-1);
					if(lr && rl){
						return true;
					}
				}
			}
		}
		return false;
	}

    bool isScramble(string s1, string s2) {
		if(s1.empty())
			return s2.empty();
		if(s1.size() != s2.size())
			return false;
		if(s1.size() == 1)
			return s1[0] == s2[0];

		int size = s1.size();
		return helper(s1, 0, size-1, s2, 0, size-1);
	}
};
