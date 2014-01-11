class Solution {
public:
	bool is_trailing_star(char* p){
		while(*p != '\0'){
			if(*(p+1) != '*')
				return false;
			p += 2;
		}
		return true;
	}

	bool helper(const char* s, char* p){
		if(*p == '\0')
			return (*s == '\0');
		if(*s == '\0')
			return is_trailing_star(p);
		const char* tmp;

		if(*(p+1) != '*'){
			return ((*s == *p || *p == '.') && helper(s+1, p+1));
		}
		// next char is '*'
		if(helper(s, p+2))
			return true;
		for(tmp = s; *tmp != '\0' && (*tmp == *p || *p == '.'); tmp++){
			if(helper(tmp+1, p+2))
				return true;
		}
		return false;
	}

    bool isMatch(const char *s, const char *p) {
		if(!p || !s)
			return false;

		char* np = new char[(strlen(p)+1) * sizeof(char)];
		char* ptr = np;
		const char *ori;
		for(ori = p; *ori != '\0';){
			if(*ori == '*'){
				for(; *(ori+1) == '*'; ori++)
					;
			}
			*ptr = *ori++;
			ptr++;
		}
		*ptr = '\0';
		if(*np == '*')
			return false;	// not a valid pattern
		return helper(s, np);
    }
};
