class Solution {
public:
	/*
	bool is_trailingstar(char* p){
		while(*p != '\0'){
			if(*(p+1) != '*')
				return false;
			p += 2;
		}
		return true;
	}
	*/
	bool helper(const char* s, char* p){
		if(*p == '\0')
			return *s == '\0';
	//	if(*s == '\0'){
	//		return is_trailingstar(p);
	//	}
		if(*(p+1) != '*')
			return ((*s == *p || (*p == '.' && *s != '\0')) && helper(s+1, p+1));
		if(helper(s, p+2))
			return true;
		for(int i = 0;  *(s+i) == *p || (*p == '.' && *(s+i) != '\0'); i++){
			if(helper(s+i+1, p+2))
				return true;
		}
		return false;
	}

    bool isMatch(const char *s, const char *p) {
		char* np = new char[strlen(p)+2];
		int i, j;
		for(i = 0; *p != '\0'; ){
			if(*p != '*'){
				np[i] = *p;
				i++;
				p++;
			}
			else{
				np[i] = *p;
				i++;
				for(p++; *p == '*'; p++)
					;
			}
		}
		np[i] = '\0';

		return helper(s, np);
    }
};
