class Solution {
public:
	bool isdigit(char c){
		return (c <= '9' && c >= '0');
	}

    bool isNumber(const char *s) {
		const char* p;
		bool dot = false;
		bool e = false;
	
		if(!s || s[0] == '\0')
			return false;
		// ignore leading spaces
		for(p = s; *p != '\0' && *p == ' '; p++)
			;
		if(*p == '\0')
			return false;
		
		if(!isdigit(*p)){
			if(*p == '+' || *p == '-'){
				p++;
				// check if we have a leading dot
				if(*p == '.'){
					dot = true;
					if(!isdigit(*(p+1)))
						return false;
					p++;
				}
			}
			else if(*p == '.'){
				dot = true;
				if(!isdigit(*(p+1)))
					return false;
				p++;
			}
			else
				return false;
		}

		for(; *p != '\0'; p++){
			if(isdigit(*p))
				continue;
			if(*p == '.'){
				if(dot || e)
					return false;
				dot = true;
			}
			else if(*p == 'e' || *p == 'E'){
				if(e)
					return false;
				e = true;
				if(!isdigit(*(p-1)) && *(p-1) != '.')
					return false;
				if(*(p+1) == '+' || *(p+1) == '-'){
					p++;
				}
				if(!isdigit(*(p+1)))
					return false;
			}
			else if(*p == ' '){
				// if it's trailing spaces, fine
				for(; *p != '\0' && *p == ' '; p++)
					;
				if(*p == '\0')
					return true;
				return false;
			}
			else
				return false;
		}
		return true;
    }
};
