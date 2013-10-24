class Solution {
public:
	
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		//return all groups of anagrams in the input strings
		unordered_map<string, vector<string>> hs;
		vector<string> ret;
		
		if(strs.empty())
			return ret;
		string cur, copy;
		int i,j;
		for(i = 0; i < strs.size(); i++){
			copy = cur = strs.at(i);
			sort(copy.begin(), copy.end());
			if(hs.find(copy) != hs.end()){
				hs[copy].push_back(cur);
			}
			else{
				vector<string> tmp;
				tmp.push_back(cur);
				hs[copy] = tmp;
			}
		}
		
		// fill ret vector
		unordered_map<string, vector<string>>::iterator it;
		for(it = hs.begin(); it != hs.end(); it++){
			if((*it).second.size() > 1){
				for(j = 0; j < (*it).second.size(); j++)
					ret.push_back((*it).second.at(j));
			}
		}
		
		return ret;
    }
};