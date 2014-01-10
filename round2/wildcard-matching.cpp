class Solution {
public:

	bool helper(const char* s, int i, const char * p, int j){
		while(1){
			if(p[j] == '\0')
				return s[i] == '\0';
			if(s[i] == '\0')
				return false;
			if(p[j] == '?')
				return helper(s, i+1, p, j+1);
			if(p[j] == '*'){
				for(; p[j+1] == '*'; j++)
					;
				if(p[j+1] == '\0')
					return true;
				for(int x = i; s[x] != '\0'; x++){
					if(helper(s, x, p, j+1))
						return true;
				}
				return false;
			}
			if(s[i] != p[j])
				return false;
			i++;
			j++;
		}
	}

    bool isMatch(const char *s, const char *p) {
		if(!s || !p)
			return false;
		return helper(s, 0, p, 0);
    }
};
