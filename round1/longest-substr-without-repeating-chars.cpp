class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		int ret;
		if(s.empty())
			return 0;
		int i, j, curlen;
		int size = s.size();

		int hash[256] = {0};

		int max = 0;
		for(i = j = 0; j < size; ){
			if(hash[s[j]] == 0){
				hash[s[j]]++;
				j++;
			}
			else{
				curlen = j-i;
				if(max < curlen)
					max = curlen;
				//update i
				while(s[i] != s[j]){
					hash[s[i]]--;
					i++;
				}
				i++;
				j++;
			}
		}
		curlen = j - i;
		if(max < curlen)
			max = curlen;

		return max;
	}
};
