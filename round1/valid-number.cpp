class Solution {
public:

	bool is_digit(char x){
		return (x <= '9' && x >= '0');
	}

    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int dot_allowed = 1;
		int e_allowed = 1;
		int pm_allowed = 1;
		bool has_digit = false;
		bool nomore_symbol = false;

		if(*s == '\0')
			return false;
		const char* p = s;
		for(; *p != '\0' && *p == ' '; p++)
			;
		if(*p == '-' || *p == '+')
			p++;
	
		if(*p == '\0')
			return false;
				
		for(; *p != '\0'; p++){
			if(is_digit(*p) && !nomore_symbol)
				has_digit = true;
			else if(*p == '.' && !nomore_symbol){
				if(dot_allowed <= 0)
					return false;
				if(e_allowed <= 0)
					return false;
				if(!has_digit && !is_digit(*(p+1)))
					return false;	
				dot_allowed--;
			}
			else if((*p == 'e' || *p == 'E') && !nomore_symbol){
				if(e_allowed <= 0)
					return false;
				if(!has_digit)
					return false;
				if(!is_digit(*(p+1)) && *(p+1) != '+' && *(p+1) != '-')
					return false;
				e_allowed--;
			}
			else if(*p == '+' || *p == '-'){
				if(pm_allowed <= 0)
					return false;
				if(*(p-1) != 'e' && *(p-1) != 'E')
					return false;
				if(!is_digit(*(p+1)))
					return false;
				pm_allowed--;
			}
			else if(*p == ' '){
				nomore_symbol = true;
			}
			else
				return false;
		}
		
		return true;
    }
};
