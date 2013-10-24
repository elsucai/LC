class Solution {
public:
    string minWindow(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

		unordered_map<char, int> needtofind;
		unordered_map<char, int> hasfound;
		int missing = T.size();
		if(missing == 0)
			return "";

		for(int i = 0; i < T.size(); i++){
			if(needtofind.find(T[i]) == needtofind.end())
				needtofind[T[i]] = 1;
			else
				needtofind[T[i]]++;
		}

		int s, e, curlen, minwindow, mins, mine;
		int need, has;
		minwindow = INT_MAX;
		mins = mine = -1;

		for(s = e = 0; e < S.size(); e++){
			if(needtofind.find(S[e]) != needtofind.end()){
				need = needtofind[S[e]];
				if(hasfound.find(S[e]) == hasfound.end()){
					hasfound[S[e]] = 1;
					missing--;
				}
				else{
					has = hasfound[S[e]];
					if(has < need){
						missing--;
					}
					hasfound[S[e]]++;
				}
				if(missing == 0){
					//update min window
					while(s <= e){
						if(needtofind.find(S[s]) == needtofind.end()){
							s++;
							continue;
						}
						if(hasfound[S[s]] > needtofind[S[s]]){
							hasfound[S[s]]--;
							s++;
						}
						else
							break;
					}
					// [s--e] is the sub string
					curlen = e-s+1;
					if(minwindow > curlen){
						minwindow = curlen;
						mins = s;
						mine = e;
					}
					hasfound[S[s]]--;
					missing++;
					s++;
				}
			}
		}

		if(mins == -1)
			return "";
		return S.substr(mins, minwindow);
    }
};
