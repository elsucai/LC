class Solution {
public:
	void helper(vector<string> &ret, vector<string> &one, string &str, int s ,int e, int parts){
		string tmp = "";
		int i, len;
		if(parts == 0){
			if(s <= e)
				return;
			for(i = 0; i < one.size()-1; i++)
				tmp += one[i]+".";
			tmp += one[i];
			ret.push_back(tmp);
			return;
		}
		
		if(s > e)
			return;
		len = e-s+1;
		if(len > 3*parts || len < parts)
			return;
		
		//first part can be 1, 2, or 3 digit
		one.push_back(str.substr(s,1));
		helper(ret, one, str, s+1, e, parts-1);
		one.erase(one.end()-1);
		
		if(s+1 <= e && str[s] != '0'){
			one.push_back(str.substr(s,2));
			helper(ret, one, str, s+2, e, parts-1);
			one.erase(one.end()-1);
		}
		
		if(s+2 <= e && str[s] <= '2' && str[s] >= '1'){
			if(str[s] == '1' || str[s+1] < '5' || (str[s+1] == '5' && str[s+2] <= '5')){
				one.push_back(str.substr(s,3));
				helper(ret, one, str, s+3, e, parts-1);
				one.erase(one.end()-1);
			}
		}
	}

    vector<string> restoreIpAddresses(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ret;
		if(s.empty())
			return ret;
		if(s.size() > 12 || s.size() < 4)
			return ret;
		vector<string> one;
		helper(ret, one, s, 0, s.size()-1, 4);
		return ret;
    }
};