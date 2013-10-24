class Solution {
public:
	void get_next(vector<string> & gray){
		vector<string> reflected;
		int size = gray.size();
		int i;
		for(i = size-1; i >= 0; i--)
			reflected.push_back(gray[i]);
		
		for(i = 0; i < size; i++){
			gray[i] = "0"+gray[i];
		}
		for(i = 0; i < size; i++){
			gray.push_back("1"+reflected[i]);
		}
	}
	
	vector<int> convert_to_decimal(vector<string>& gray){
		vector<int> ret;
		for(int i = 0; i < gray.size(); i++){
			string tmp = gray[i];
			int sum = 0;
			for(int j = 0; j < tmp.size(); j++){
				sum = sum * 2 + (tmp[j]-'0');
			}
			ret.push_back(sum);
		}
		return ret;
	}
	
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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
		
		vector<string> gray;
		gray.push_back("00");
		gray.push_back("01");
		gray.push_back("11");
		gray.push_back("10");
		
		for(int i = 3; i <= n; i++){
			get_next(gray);
		}
		
		ret = convert_to_decimal(gray);
		return ret;
	}
};