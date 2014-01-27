class Solution {
public:
	bool helper(string &a, int as, int ae, string &b, int bs, int be){
		int i;
		if(ae-as != be-bs)
			return false;
		if(as == ae)
			return (a[as] == b[bs]);
		// check freq
		unordered_map<char, int> hm;
		for(i = as; i <= ae; i++)
			hm[a[i]]++;
		for(i = bs; i <= be; i++){
			if(hm.find(b[i]) == hm.end())
				return false;
			if(hm[b[i]] <= 0)
				return false;
			hm[b[i]]--;
		}
		for(i = as; i < ae; i++){
			if(helper(a, as, i, b, bs, bs+i-as) && helper(a, i+1, ae, b, bs+i-as+1, be))
				return true;
			if(helper(a, as, i, b, be+as-i, be) && helper(a, i+1, ae, b, bs, be+as-i-1))
				return true;
		}
		return false;
	}

    bool isScramble(string s1, string s2) {
		if(s1.empty())
			return s2.empty();
		if(s2.empty())
			return s1.empty();
		int n = s1.size();
		return helper(s1, 0, n-1, s2, 0, n-1);
	}
};
