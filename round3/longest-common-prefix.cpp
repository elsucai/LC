class Solution {
public:
	string find_common(string &c, string &s){
		int n = c.size();
		int i;
		for(i = 0; i < n; i++){
			if(c[i] != s[i])
				break;
		}
		if(i == 0)
			return "";
		return c.substr(0, i);
	}

    string longestCommonPrefix(vector<string> &strs) {
		int min_index;
		int min_len = INT_MAX;
		string common = "";
		if(strs.empty())
			return common;
		if(strs.size() == 1)
			return strs[0];
		for(int i = 0; i < strs.size(); i++){
			if(strs[i].size() < min_len){
				min_len = strs[i].size();
				min_index = i;
			}
		}
		common = strs[min_index];
		swap(strs[0], strs[min_index]);

		for(int i = 1; i < strs.size(); i++){
			common = find_common(common, strs[i]);
			if(common.empty())
				return common;
		}
		return common;
    }
};
