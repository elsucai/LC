class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		string prefix = "";
		if(strs.empty())
			return prefix;

		int i, min;
		int size = strs.size();
		prefix = strs[0];
		min = strs[0].size();

		for(i = 1; i < size; i++){
			if(strs[i].size() < min){
				min = strs[i].size();
				prefix = strs[i];
			}
		}

		int x;
		string cur;
		for(i = 0; i < size; i++){
			x = 0;
			cur = strs[i];
			while(x < min && prefix[x] == cur[x]){
				x++;
			}
			if(x == 0){
				return ""; 
			}
			min = x;
			prefix = prefix.substr(0, min);
		}
		return prefix;
    }
};
