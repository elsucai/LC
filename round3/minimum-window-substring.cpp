class Solution {
public:
    string minWindow(string S, string T) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int minwindow = INT_MAX;
		string ret = "";
		if(T.empty())
			return ret;
		unordered_map<char, int> freq;
		unordered_map<char, int> local;
		int i, s, e, cnt, total, n;
		n = S.size();
		total = T.size();
		
		for(i = 0; i < T.size(); i++)
			freq[T[i]]++;
		cnt = 0;
		char cur;
		for(s = e = 0; e < n; e++){
			cur = S[e];
			if(cnt == total){
				// advance s
				// update ret
				// make cnt = total-1
				e--;
				for(; s <= e; s++){
					cur = S[s];
					if(freq.find(cur) != freq.end()){
						local[cur]--;
						if(local[cur] < freq[cur]){
							if(minwindow > e-s+1){
								minwindow = e-s+1;
								ret = S.substr(s, minwindow);
							}
							cnt--;
							s++;
							break;
						}
					}
				}
			}
			else{
				if(freq.find(cur) != freq.end()){
					local[cur]++;
					if(local[cur] <= freq[cur])
						cnt++;
				}
			}
		}
		// e == n
		if(cnt == total){
			e--;
			for(; s <= e; s++){
				cur = S[s];
				if(freq.find(cur) != freq.end()){
					local[cur]--;
					if(local[cur] < freq[cur]){
						if(minwindow > e-s+1){
							minwindow = e-s+1;
							ret = S.substr(s, minwindow);
						}
						cnt--;
						s++;
						break;
					}
				}
			}
		}
		return ret;
    }
};
