class Solution {
public:

	void helper(vector<string> &phone, string digits, int s, int e, vector<string> &ret){
		if(s > e)
			return;
		helper(phone, digits, s+1, e, ret);
		
		if(digits[s] == '0' || digits[s] == '1')
			return;
		string key = phone[digits[s]-'0'];
		
		int ori_size = ret.size();
		if(ori_size == 0){
			for(int i = 0; i < key.size(); i++)
				ret.push_back(key.substr(i,1));
			return;
		}

		for(int i = 0; i < key.size() - 1; i++){
			for(int j = 0; j < ori_size; j++){
				ret.push_back(ret[j]);
			}
		}

		int start = 0;
		for(int i = 0; i < key.size(); i++){
			string cur = key.substr(i,1);
			for(int j = 0; j < ori_size; j++, start++){
				ret[start] = cur+ret[start];
			}
		}
	}


    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	
		vector<string> ret;
		ret.push_back("");
		vector<string> phone(10, "");
		phone[2] = "abc";
		phone[3] = "def";
		phone[4] = "ghi";
		phone[5] = "jkl";
		phone[6] = "mno";
		phone[7] = "pqrs";
		phone[8] = "tuv";
		phone[9] = "wxyz";

		if(digits.empty())
			return ret;

		helper(phone, digits, 0, digits.size()-1, ret);
		return ret;
    }
};
