class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    

        int i;
        if(*p == '\0')
			return (*s == '\0');
		if(*s == '\0'){
			// return true iff p is of the form .*.*.*.* ...
			for(const char* x = p; *x != '\0'; x += 2){
				if(*x == '*')
					return false;
				if(*(x+1) != '*')
					return false;
			}
			return true;
		}

		// both valid chars
		if(*p == '*')
			return false;	// not a valid regex
		else if(*(p+1) != '*'){
			// must match current char
			if(*p == '.')
				return isMatch(s+1, p+1);

			if(*s != *p)
				return false;
			return isMatch(s+1, p+1);
		}
		else{
			// dealwith *
			for(i = 0; *(s+i) != '\0' && (*(s+i) == *p || *p == '.'); i++){
				if(isMatch(s+i, p+2))
					return true;
			}
			return isMatch(s+i, p+2);
		}
    }
};
