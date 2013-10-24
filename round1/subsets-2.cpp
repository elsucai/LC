class Solution {
public:
	
	void helper(vector<vector<int> > &ret, vector<int> &unique, vector<int> &freq, vector<int> &flag, int s, int e){
		int i, j;
		if(s > e){
			// push to ret
			vector<int> tmp;
			for(i = 0; i <= e; i++){
				for(j = 1; j <= flag[i]; j++){
					tmp.push_back(unique[i]);
				}
			}
			ret.push_back(tmp);
		}
		
		for(i = freq[s]; i >= 0; i--){
			flag[s] = i;
			helper(ret, unique, freq, flag, s+1, e);
		}
	}
	
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		S.sort();
		vector<int> unique;
		vector<int> freq;
		unordered_set<int> hs;
		
		for(int i = 0; i < S.size(); i++){
			if(hs.find(S[i]) == hs.end()){
				// not in the hash set
				unique.push_back(S[i]);
				freq.push_back(1);
			}
			else{
				freq[freq.size()-1]++;
			}
		}
		
		vector<vector<int> > ret;
		vector<int> flag(unique.size(), 0);
		helper(ret, unique, freq, flag, 0, unique.size()-1);
		
		return ret;
    }
};