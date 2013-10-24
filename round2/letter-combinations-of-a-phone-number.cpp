class Solution {
public:
	void helper(string &data, vector<string> &mapping, vector<string> &ret, string& one_comb, int s, int e){
		int i;
		if(s > e){
			ret.push_back(one_comb);
			return;
		}
		
		string cur = mapping[data[s] - '0'];
		for(i = 0; i < cur.size(); i++){
			one_comb[s] = cur[i];
			helper(data, mapping, ret, one_comb, s+1, e);
		}
	}

    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
		vector<string> ret;
		string one_comb = "";
		string data = "";
		for(int i = 0; i < digits.size(); i++)
			if(digits[i] != '0' && digits[i] != '1'){
				one_comb += "0";
				data += digits.substr(i, 1);
			}
		
		vector<string> mapping(10, "");
		mapping[2] = "abc";
		mapping[3] = "def";
		mapping[4] = "ghi";
		mapping[5] = "jkl";
		mapping[6] = "mno";
		mapping[7] = "pqrs";
		mapping[8] = "tuv";
		mapping[9] = "wxyz";
		
		helper(data, mapping, ret, one_comb, 0, one_comb.size()-1);
		
		return ret;
    }
};