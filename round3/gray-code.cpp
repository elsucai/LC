class Solution {
public:
	int s2i(string s){
		int ret = 0;
		for(int i = 0; i < s.size(); i++){
			ret = (ret<<1)+(s[i]-'0');
		}
		return ret;
	}

	void gen_next(vector<string> &gray){
		vector<string> copy = gray;
		int size = gray.size();
		for(int i = 0; i < size; i++){
			gray[i] = "0"+gray[i];
			copy[i] = "1"+copy[i];
		}
		for(int i = size-1; i >= 0; i--)
			gray.push_back(copy[i]);
		copy.clear();
	}

	void convert_gray_to_int(vector<string> &gray, vector<int> &ret){
		for(int i = 0; i < gray.size(); i++)
			ret.push_back(s2i(gray[i]));
	}

    vector<int> grayCode(int n) {
		vector<int> ret;
		if(n == 0){
			ret.push_back(0);
			return ret;
		}
		if(n == 1){
			ret.push_back(0);
			ret.push_back(1);
			return ret;
		}

		// n >= 2
		vector<string> gray;
		gray.push_back("0");
		gray.push_back("1");

		for(int i = 1; i < n; i++)
			gen_next(gray);
		convert_gray_to_int(gray, ret);
		return ret;
    }
};
