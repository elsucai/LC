class Solution {
public:
	/*
	string minWindow(string S, string T) {
		if(T.empty())
			return "";
		if(S.size() < T.size())
			return "";
		int minstart = 0;
		unordered_map<char, int> freq;
		unordered_map<char, int> found;
		int cnt = 0;

		for(int i = 0; i < T.size(); i++){
			freq[T[i]]++;
		}

		int minlen = INT_MAX;
		int start, end;
		int n = S.size();
		for(start = end = 0; end < n; end++){
			if(freq.find(S[end]) != freq.end()){
				found[S[end]]++;
				if(found[S[end]] <= freq[S[end]])
					cnt++;
			}
			if(cnt == T.size()){

				while(start <= end){
					if(freq.find(S[start]) == freq.end()){
						start++;
					}
					else if(found[S[start]] > freq[S[start]]){
						found[S[start]] --;
						start++;
					}
					else{
						break;
					}
				}
				if(minlen > end-start+1){
					minlen = end-start+1;
					minstart = start;
				}
				found[S[start]]--;
				start++;
				cnt--;
			}
		}
		if(minlen == INT_MAX)
			return "";
		return S.substr(minstart, minlen);
	}
	*/

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
