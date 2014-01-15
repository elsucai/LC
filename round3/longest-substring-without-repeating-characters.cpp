class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.size() <= 1)
			return s.size();
		int size = s.size();
		int i, j, maxlen;
		maxlen = i = j = 0;
		unordered_set<char> hs;

		for(i = j = 0; j < size; ){
			if(hs.find(s[j]) == hs.end()){
				hs.insert(s[j]);
				j++;
			}
			else{
				maxlen = max(j-i, maxlen);
				while(s[i] != s[j]){
					hs.erase(s[i]);
					i++;
				}
				i++;
				j++;
			}
		}
		maxlen = max(j-i, maxlen);
		return maxlen;
    }
};
