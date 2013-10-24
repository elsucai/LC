class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		int longest = 0;
		int size = s.size();
		vector<bool> hs(256, false);

		int begin, end;
		int curlen = 0;
		for(begin = end = 0; end < size; end++){
			if(!hs[s[end]]){
				hs[s[end]] = true;
			}
			else{
				curlen = end - begin;
				if(longest < curlen)
					longest = curlen;
				while(s[begin] != s[end]){
					hs[s[begin]] = false;
					begin++;
				}
				begin++;
			}
		}
		curlen = end-begin;
		if(longest < curlen)
			longest = curlen;

		return longest;
    }
};
