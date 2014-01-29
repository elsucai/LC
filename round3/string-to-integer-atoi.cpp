class Solution {
public:
    int atoi(const char *str) {
		int flag = 1;
		long long ret = 0;

		if(!str)
			return 0;
		for(; *str != '\0' && *str == ' '; str++)
			;
		if(*str == '\0')
			return 0;
		if(*str == '-'){
			flag = -1;
			str++;
		}
		else if(*str == '+')
			str++;
		else
			;
		for(; *str != '\0'; str++){
			if(*str > '9' || *str < '0')
				return ret;
			ret = ret*10 + flag * (*str - '0');
			if(flag == 1 && ret > INT_MAX)
				return INT_MAX;
			if(flag == -1 && ret < INT_MIN)
				return INT_MIN;
		}
		return ret;
    }
};
