class Solution {
public:
	void helper(vector<string> &ret, string &one, vector<string> &mapping, string &d, int s, int e){
		if(s > e){
			ret.push_back(one);
			return;
		}
		for(int i = 0; i < mapping[d[s]-'0'].size(); i++){
			one += mapping[d[s]-'0'][i];
			helper(ret, one, mapping, d, s+1, e);
			one = one.substr(0, one.size()-1);
		}
	}

    vector<string> letterCombinations(string digits) {
		vector<string> ret;
		vector<string> mapping(10, "");
		mapping[2] = "abc";
		mapping[3] = "def";
		mapping[4] = "ghi";
		mapping[5] = "jkl";
		mapping[6] = "mno";
		mapping[7] = "pqrs";
		mapping[8] = "tuv";
		mapping[9] = "wxyz";

		string d = "";
		for(int i = 0; i < digits.size(); i++){
			if(digits[i] != '0' && digits[i] != '1')
				d += digits[i];
		}

		if(d.empty())
			return ret;
		string one = "";
		helper(ret, one, mapping, d, 0, d.size()-1);
		return ret;
    }
};
