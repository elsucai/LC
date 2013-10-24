class Solution {
public:
	bool is_digit(char x){
		return (x <= '9' && x >= '0');
	}

    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		assert(str);
		char buf[15] = {'0'};
		int s, e, b;
		int cnt = 0;
		int ret = 0;
		int flag = 1;
		s = e = b = 0;
		
		while(str[s] == ' ')
			s++;
			
		if(str[s] == '+')
			s++;
		else if(str[s] == '-'){
			flag = -1;
			s++;
		}
		else
			;
		
		if(str[s] == '\0')
			return 0;

		for(e = s; str[e] != '\0'; e++){
			if(!is_digit(str[e])){
				break;
			}
			cnt++;
			if(cnt <= 10){
				buf[b++] = str[e];
			}
			else{
				if(flag == 1)
					return 2147483647;
				else
					return -2147483648;
			}
		}
		
		if(cnt == 10){
			if(flag == 1){
				if(strcmp(buf, "2147483647") >= 0)
					return 2147483647;
			}
			
			if(flag == -1){
				if(strcmp(buf, "2147483648") >= 0)
					return -2147483648;
			}
		}

		for(int i = 0; i < cnt; i++){
			ret = ret*10+(buf[i]-'0');
		}
		return flag*ret;
    }
};
