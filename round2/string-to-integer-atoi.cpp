class Solution {
public:
	int is_digit(char x){
		if(x <= '9' && x >= '0')
			return 1;
		return 0;
	}

    int atoi(const char *str) {
		int i, ret, s, e, size;
		char clean[12] = {'\0'};
		if(!str)
			return 0;
		for(s = 0; str[s] != '\0' && str[s] == ' '; s++)
			;
		if(str[s] == '\0')
			return 0;
		int flag = 1;

		if(!is_digit(str[s])){
			if(str[s] == '-')
				flag = -1;
			else if(str[s] != '+')
				return 0;
			else
				;
			s++;
		}

		// find the end of last digit
		for(e = s; str[e] != '\0' && is_digit(str[e]); e++)
			;
		e--;
		for(; str[s] != '\0' && str[s] == '0'; s++)
			;
		if(e < s)
			return 0;
		size = e-s+1;
		if(size > 10)
			return flag == 1 ? INT_MAX : INT_MIN;
		for(i = 0; s <= e; i++, s++)
			clean[i] = str[s];

		if(size == 10){
			if(flag == 1){
				if(strcmp(clean, "2147483647") >= 0)
					return INT_MAX;
			}
			else{
				if(strcmp(clean, "2147483648") >= 0)
					return INT_MIN;
			}
		}
		// good to compute
		ret = 0;
		for(i = 0; i < size; i++){
			ret = ret*10 + clean[i]-'0';
		}
		return flag == 1 ? ret : -ret;
    }
};
