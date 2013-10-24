class Solution {
public:

	bool is_ana(string a, string b){
		if(a.empty() && b.empty())
			return true;
		if(a.size() != b.size())
			return false;
			
		int hm[26] = {0};
		for(int i = 0; i < a.size(); i++){
			hm[a[i]-'a']++;
		}
		//check
		for(int j = 0; j < b.size(); j++){
			if(hm[b[j]-'a'] == 0)
				return false;
			hm[b[j]-'a']--;
		}
		return true;
	}
	
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		//return all groups of anagrams in the input strings
		vector<vector<string>> anas;
		vector<string> ret;
		
		if(strs.empty())
			return ret;
		string cur;
		int i,j;
		for(i = 0; i < strs.size(); i++){
			cur = strs.at(i);
			for(j = 0; j < anas.size(); j++){
				if(is_ana(cur, anas.at(j).at(0))){
					anas.at(j).push_back(cur);
					break;
				}
			}
			if(j == anas.size()){
				vector<string> tmp;
				tmp.push_back(cur);
				anas.push_back(tmp);
			}
		}
		
		// fill ret vector
		for(i = 0; i < anas.size(); i++){
			if(anas.at(i).size() > 1){
				for(j = 0; j < anas.at(i).size(); j++)
					ret.push_back(anas.at(i).at(j));
			}
		}
		
		return ret;
    }
};