class Solution {
public:
	char check(char x){
		int diff = 'A'-'a';
		if(!(x <= 'Z' && x >= 'A') && !(x <= 'z' && x >= 'a') && !(x <= '9' && x >= '0'))
			return '\0';
		if(x <= 'Z' && x >= 'A')
			return (char)(x-diff);
	}

    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(s.empty())
			return true;
		int i = 0;
		int j = s.size()-1;

		char a,b;
		a = '\0';
		b = '\0';
		while(i < j){
			a = check(s[i]);
			b = check(s[j]);

			if(a != '\0' && b != '\0'){
				if(a != b)
					return false;
				i++;
				j--;
				continue;
			}

			// at least one of them is not valid
			if(a == '\0')
				i++;
			if(b == '\0')
				j--;
		}
		return true;
    }
};
