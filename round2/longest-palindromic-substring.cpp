class Solution {
public:
	string cur_longest(string &s, int center){
		// odd string
		string longest = "";
		int i, j;
		int size = s.size();
		for(i = center-1, j = center+1; i >=0 && j < size; ){
			if(s[i] != s[j])
				break;
			i--;
			j++;
		}
		if(j-i-1 > longest.size())
			longest = s.substr(i+1, j-i-1);
		// even string
		for(i = center, j = center+1; i >= 0 && j < size;){
			if(s[i] != s[j])
				break;
			i--;
			j++;
		}
		if(j-i-1 > longest.size())
			longest = s.substr(i+1, j-i-1);
		return longest;
	}

    string longestPalindrome(string s) {
		if(s.size() <= 1)
			return s;
		
		string ret = "";
		string cur;
		for(int i = 0; i < s.size(); i++){
			cur = cur_longest(s, i);
			if(cur.size() > ret.size()){
				ret = cur;
			}
		}
		return ret;
    }
};
