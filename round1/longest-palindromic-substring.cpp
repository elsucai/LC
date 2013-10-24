class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		string ret = "";
		if(s.empty())
			return ret;

		int max = 0;
		int start, end, len;

		int size = s.size();

		int i, j, c;
		// center is a single letter
		for(c = 0; c < size; c++){
			i = c-1;
			j = c+1;
			while(i >= 0 && j < size && s[i] == s[j]){
				i--;
				j++;
			}
			len = j-i-1;
			if(max < len){
				max = len;
				start = i+1;
				end = j-1;
			}
		}

		// center has two letters, c is the left one
		for(c = 0; c < size-1; c++){
			if(s[c] != s[c+1])
				continue;
			i = c-1;
			j = c+2;
			
			while(i >= 0 && j < size && s[i] == s[j]){
				i--;
				j++;
			}
			len = j-i-1;
			if(max < len){
				max = len;
				start = i+1;
				end = j-1;
			}
		}

		ret = s.substr(start, end-start+1);
		return ret;
    }
};
