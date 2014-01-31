class Solution {
public:
	bool validchar(char c){
		if(c <= '9' && c >= '0')
			return true;
		if(c <= 'Z' && c >= 'A')
			return true;
		if(c <= 'z' && c >= 'a')
			return true;
		return false;
	}

	bool match(char x, char y){
		if(x >= 'A' && x <= 'Z')
			x -= ('A' - 'a');
		if(y >= 'A' && y <= 'Z')
			y -= ('A' - 'a');
		return x == y;
	}

    bool isPalindrome(string s) {
		int i, j;
		for(i = 0, j = s.size()-1; i <= j; ){
			if(!validchar(s[i]))
				i++;
			else if(!validchar(s[j]))
				j--;
			else{
				if(!match(s[i], s[j]))
					return false;
				i++;
				j--;
			}
		}
		return true;
    }
};
