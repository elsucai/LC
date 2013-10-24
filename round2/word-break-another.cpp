class Solution {
public:
	
	bool helper(vector<vector<int> > &D, unordered_set<string> &dict, string &str, int s, int e){
		if(s > e || dict.find(str.substr(s, e-s+1)) != dict.end()){
			D[s][e] = 1;
			return true;
		}
		if(s == e){
			if(dict.find(str.substr(s, 1)) != dict.end()){
				D[s][e] = 1;
				return true;
			}
			else{
				D[s][e] = 0;
				return false;
			}
		}
		bool tmp;
		if(D[s][e] != -1)
			return D[s][e] == 1 ? true : false;
			
		for(int i = s; i < e; i++){
			if(D[s][i] == -1){
				tmp = helper(D, dict, str, s, i);
				D[s][i] = tmp ? 1 : 0;
			}
			if(D[s][i] == 1){
				if(D[i+1][e] == -1){
					tmp = helper(D, dict, str, i+1, e);
					D[i+1][e] = tmp ? 1 : 0;
				}
				if(D[i+1][e] == 1){
					D[s][e] = 1;
					break;
				}
			}
		}
		if(D[s][e] == 1)
			return true;
		D[s][e] = 0;
			return false;
	}

    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int size = s.size();
		vector<vector<int> > D(size+1, vector<int>(size+1, false));
		int i,j;
		for(i = 0; i <= size; i++){
			for(j = 0; j <= size; j++){
				D[i][j] = -1;
			}
		}
		for(i = 0; i <= size; i++){
			for(j = 0; j < i; j++){
				D[i][j] = 1;
			}
		}
		
		return helper(D, dict, s, 0, size-1);
    }
};