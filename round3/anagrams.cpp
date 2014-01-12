class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
		vector<string> ret;
		unordered_map<string, vector<string> > hm;
		unordered_map<string, vector<string> >::iterator it;
		string label;
		for(int i = 0; i < strs.size(); i++){
			label = strs[i];
			sort(label.begin(), label.end());
			if(hm.find(label) == hm.end()){
				hm[label] = vector<string>();
			}
			(hm[label]).push_back(strs[i]);
		}
		
		for(it = hm.begin(); it != hm.end(); it++){
			if((it->second).size() > 1){
				for(int i = 0; i < (it->second).size(); i++)
					ret.push_back((it->second)[i]);
			}
		}
		return ret;
    }
};
