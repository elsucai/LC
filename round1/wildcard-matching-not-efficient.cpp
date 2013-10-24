#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:

    bool isMatch(const char *s, const char *p) {
		// use DP
		if(s == NULL || p == NULL)
			return false;
		int m = strlen(s);
		vector<char> np;
		for(; *p != '\0'; p++){
			if(*p != '*')
				np.push_back(*p);
			else{
				for(; *p == '*'; p++)
					;
				p--;
				np.push_back(*p);
			}
		}
		int n = np.size();

		int i,j;
		vector<bool> next(n+1, false);
		vector<bool> pre(n+1, false);
		vector<bool> cache(n+1, false);
		cache[n] = true;
		next[n] = true;
		
		for(j = n-1; j >= 0; j--){
			if(np[j] == '*'){
				next[j] = next[j+1];
				cache[j] = cache[j] || next[j];
			}
		}

		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				//set dp[i][j]
				if(s[i] == np[j] || np[j] == '?'){
					pre[j] = next[j+1];
					cache[j] = cache[j] || pre[j];
				}
				else{
					if(np[j] != '*')
						pre[j] = false;
					else{
						// np[j] == '*'
						// if any of dp[i -- m][j+1] is true
						// then dp[i][j] is true
						if(cache[j+1]){
							pre[j] = true;
							cache[j] = true;
						}
						else
							pre[j] = false;
					}
				}
			}
			swap(pre, next);
			next[n] = false;
		}

		return next[0];
	}

	// didn't pass large test
	/*
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(s == NULL || p == NULL)
			return false;
		if(*p == '\0')
			return (*s == '\0');
		// *p != '\0'
		if(*s == '\0'){
			for(; *p == '*'; p++)
				;
			return (*p == '\0');
		}

		// both have valid chars
		if(*p != '?' && *p != '*')
			return (*s == *p) && isMatch(s+1, p+1);
		if(*p == '?')
			return isMatch(s+1, p+1);
		else{
			// *p == '*'
			for(; *p == '*'; p++)
				;
			p--;
			for(; *s != '\0'; s++){
				if(isMatch(s, p+1))
					return true;
			}
			// *s == '\0'
			return (*(p+1) == '\0');
		}
    }
	*/
};

int main(){
		Solution s;
		cout<<s.isMatch("aaaababbbabbbbaabbaaabbbbabbbbbabaaaabbbbbaaaabbbbbaaabbaaaabbabbabbabababaabbbbaabaaabbabbaabbababbbabbbbbaaabaaaababababbaaaabaabaaabbbbbbbbbabbbaabbaaaaaabbabaabaaabbbaaabaaabaaabaabbabaabbaaabaaabb","bb*****b*ba*a**bb*b**aba**a*b*b*b*a*b*a*ba*b*a*a*****a*b***a*a**a**b**b***a*a***bbba*abb*abba*bab***")<<endl;
		return 0;
	}
