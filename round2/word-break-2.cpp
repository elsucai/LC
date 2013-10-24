class Solution {
	public:
		vector<string> wordBreak(string s, unordered_set<string> &dict) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			if(s.empty()){
				vector<string> ret;
				return ret;
			}

			int size = s.size();
			int i, j, k;
			vector<vector<string> > D;
			vector<string> tmp;
			for(i = 0; i <= size; i++){
				D.push_back(tmp);
			}

			D[size].push_back("");

			string curhead;
			for(i = size-1; i >= 0; i--){
				for(j = i; j < size; j++){
					curhead = s.substr(i, j-i+1);
					if(dict.find(curhead) != dict.end()){
						if(!D[j+1].empty()){
							if(D[j+1][0] == ""){
								D[i].push_back(curhead);
							}
							else{
								for(k = 0; k < D[j+1].size(); k++){
									D[i].push_back(curhead+" "+D[j+1][k]);
								}
							}
						}
					}
				}
			}

			return D[0];
		}
};
