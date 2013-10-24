class Solution {
public:
    
    vector<string> anagrams(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ret;
		unordered_map<string, vector<string> > hm;
		
		string key;
		vector<string> tmp;
		for(int i = 0; i < strs.size(); i++){
			key = strs[i];
			sort(key.begin(), key.end());
			if(hm.find(key) == hm.end()){
				tmp.clear();
				hm[key] = tmp;
			}
			hm[key].push_back(strs[i]);
		}
		
		unordered_map<string, vector<string> > :: iterator it;
		for(it = hm.begin(); it != hm.end(); it++){
            if((it->second).size() < 2)
                continue;
			for(int i = 0; i < (it->second).size(); i++)
				ret.push_back((it->second)[i]);
		}
		return ret;
    }
};