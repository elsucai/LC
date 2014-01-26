class Solution {
public:
	void helper(vector<string> &ret, vector<string> &one, string &str, int parts, int s, int e){
		string x = "";
		if(parts == 0){
			if(s > e){
				for(int i = 0; i < one.size()-1; i++)
					x += one[i]+".";
				x += one.back();
				ret.push_back(x);
			}
			return;
		}
		if(s > e)
			return;
		if(e-s+1 > 3*parts || e-s+1 < parts)
			return;
		one.push_back(str.substr(s, 1));
		helper(ret, one, str, parts-1, s+1, e);
		one.pop_back();
		if(s+1 <= e && str[s] != '0'){
			one.push_back(str.substr(s, 2));
			helper(ret, one, str, parts-1, s+2, e);
			one.pop_back();
		}
		if(s+2 <= e){
			if(str[s] == '0' || str[s] >= '3')
				return;
			if(str[s] == '2'){
				if(str[s+1] >= '6')
					return;
				if(str[s+1] == '5' && str[s+2] >= '6')
					return;
			}
			one.push_back(str.substr(s, 3));
			helper(ret, one, str, parts-1, s+3, e);
			one.pop_back();
		}
	}

    vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		vector<string> one;
		if(s.size() > 12 || s.size() < 4)
			return ret;
		helper(ret, one, s, 4, 0, s.size()-1);
		return ret;
    }
};
