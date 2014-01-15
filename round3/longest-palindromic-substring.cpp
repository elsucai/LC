class Solution {
public:
	string longestPalindrome(string s) {
		if(s.size() <= 1)
			return s;
		int center, i, j;
		int maxlen = 0;
		string ret;
		int n = s.size();
		int curlen;
		for(center = 0; center < n; center++){
			// odd string
			for(i = center-1, j = center+1; i >= 0 && j < n; i--, j++){
				if(s[i] != s[j])
					break;
			}
			// [i+1, j-1]
			curlen = j-1-i;
			if(maxlen < curlen){
				maxlen = curlen;
				ret = s.substr(i+1, curlen);
			}
		}

		// even string
		for(center = 0; center < n-1; center++){
			for(i = center, j = center+1; i >= 0 && j < n; i--, j++){
				if(s[i] != s[j])
					break;
			}
			// [i+1, j-1]
			if(i+1 < j-1){
				curlen = j-1-i;
				if(maxlen < curlen){
					maxlen = curlen;
					ret = s.substr(i+1, curlen);
				}
			}
		}

		return ret;
    }
};
