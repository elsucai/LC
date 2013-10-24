class Solution {
public:
    		
	int helper(string &S, int s, int e, int lsize, int wsize, unordered_map<string, int> &freq){
		int i = s;
		string sub;
		int cnt = lsize;
		
		unordered_map<string, int> tmp;

		while(i <= e){
			sub = S.substr(i, wsize);
			if(freq.find(sub) == freq.end())
				return -1;
			tmp[sub]++;
			if(tmp[sub] > freq[sub])
				return -1;
			cnt--;
			if(cnt == 0)
				return s;
			i += wsize;
		}
		return -1;
	}


    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> ret;

		if(L.empty()){
			for(int i = 0; i < S.size(); i++)
				ret.push_back(i);
			return ret;
		}
		
		int wsize = L[0].size();
		int lsize = L.size();
		
		if(lsize * wsize > S.size())
			return ret;

		int s, e, i;
		unordered_map<string, int> freq;

		for(i = 0; i < lsize; i++){
			if(freq.find(L[i]) == freq.end()){
				freq[L[i]] = 1;
			}
			else{
				freq[L[i]]++;
			}
		}
		
		int start;
		s = 0;
		e = lsize*wsize -1;
		
		while(e < S.size()){
			start = helper(S, s, e, lsize, wsize, freq);
			if(start >= 0)
				ret.push_back(start);
			s++;
			e++;
		}

		return ret;
    }
};
