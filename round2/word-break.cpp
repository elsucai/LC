class Solution {
public:
	
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		int size = s.size();
		int i, j;
		vector<bool> D(size+1, false);
			D[size] = true;

		for(i = size-1; i >= 0; i--){
			for(j = i; j < size; j++){
				if(dict.find(s.substr(i, j-i+1)) != dict.end()){
					if(D[j+1]){
						D[i] = true;
						break;
					}
				}
			}
		}

		return D[0];
    }
};
