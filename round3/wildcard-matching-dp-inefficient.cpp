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

		int i,j,starcnt;
		vector<bool> next(n+1, false);
		vector<bool> pre(n+1, false);
		vector<bool> cache(n+1, false);
		cache[n] = true;
		next[n] = true;
		starcnt = 0;
		
		for(j = n-1; j >= 0; j--){
			if(np[j] == '*'){
			    starcnt++;
				next[j] = next[j+1];
				cache[j] = cache[j] || next[j];
			}
		}

		for(i = m-1; i >= 0; i--){
			for(j = n-1; j >= 0; j--){
				//set dp[i][j]
				if(m-i < n-j-starcnt){
				    pre[j] = false;
				    continue;
				}
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
};