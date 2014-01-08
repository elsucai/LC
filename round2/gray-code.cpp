class Solution {
public:
	void get_next_code(vector<string> &code){
		vector<string> copy = code;
		int size = code.size();
		for(int i = 0; i < size; i++){
			code[i] = "0"+code[i];
			copy[i] = "1"+copy[i];
		}
		for(int i = size-1; i >= 0; i--)
			code.push_back(copy[i]);
	}

	int to_int(string s){
		int ret = 0;
		for(int i = 0; i < s.size(); i++)
			ret = (ret<<1) + s[i] - '0';
		return ret;
	}

    vector<int> grayCode(int n) {
		vector<int> ret;
		if(n < 0)
			return ret;
		if(n == 0){
			ret.push_back(0);
			return ret;
		}
		if(n == 1){
			ret.push_back(0);
			ret.push_back(1);
			return ret;
		}
		if(n == 2){
			ret.push_back(0);
			ret.push_back(1);
			ret.push_back(3);
			ret.push_back(2);
			return ret;
		}

		vector<string> code;
		code.push_back("00");
		code.push_back("01");
		code.push_back("11");
		code.push_back("10");

		for(int i = 3; i <= n; i++)
			get_next_code(code);
		for(int i = 0; i < code.size(); i++)
			ret.push_back(to_int(code[i]));
		return ret;
    }
};
