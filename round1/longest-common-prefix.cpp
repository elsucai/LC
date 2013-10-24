class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		string ret = "";
		if(strs.empty())
			return ret;

		// find the shortest string
		int min = INT_MAX;
		int min_index;
		int i,j;
		for(i = 0; i < strs.size(); i++){
			if(strs[i].size() < min){
				min = strs[i].size();
				min_index = i;
			}
		}

		swap(strs[0], strs[min_index]);
		
		ret = strs[0];
		for(i = 1; i < strs.size(); i++){
			string cur = strs[i];
			for(j = 0; j < ret.size(); j++){
				if(cur[j] != ret[j])
					break;
			}
			if(j == 0){
				return "";
			}
			if(j < ret.size())
				ret = ret.substr(0, j);
		}

		return ret;
    }
};
