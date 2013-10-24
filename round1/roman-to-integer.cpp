class Solution {
public:
	int get_number(char x){
		switch(x){
			case 'I':
				return 1;
			case 'V':
				return 5;
			case 'X':
				return 10;
			case 'L':
				return 50;
			case 'C':
				return 100;
			case 'D':
				return 500;
			case 'M':
				return 1000;
			default:
				return 0;
		}
	}
	
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		int ret = 0;
		int i, cur, pre;
		pre = cur = 0;
		for(i = 0; i < s.size(); i++){
			cur = get_number(s[i]);
			if(i > 0)
				pre = get_number(s[i-1]);
			ret += cur;
			if(cur > pre)
				ret = ret - pre*2;
		}
		return ret;
    }
};