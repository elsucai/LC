class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		string ret = "";
		if(T.empty())
			return ret;
		
		int needtofind[256] = {0};
		int hasfound[256] = {0};
		int s, e;
		for(s = 0; s < T.size(); s++)
			needtofind[T[s]]++;
		
		int cnt = 0;
		int cur_len;
		int min = INT_MAX;
		for(s = e = 0; e < S.size(); e++){
			if(needtofind[S[e]] != 0){
				if(hasfound[S[e]] < needtofind[S[e]])
					cnt++;
				hasfound[S[e]]++;
				
				if(cnt == T.size()){
					// move s forward, update ret
					while(cnt == T.size()){
						if(needtofind[S[s]] == 0)
							s++;
						else if(hasfound[S[s]] > needtofind[S[s]]){						
							hasfound[S[s]]--;
							s++;
						}
						else{
							hasfound[S[s]]--;
							cnt--;
						}
					}
					// update minimum window
					cur_len = e-s+1;
					if(min > cur_len){
						min = cur_len;
						ret = S.substr(s, cur_len);
					}	
					s++;
				}
			}
		}
		return ret;
	}
};