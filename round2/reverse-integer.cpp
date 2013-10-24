class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int flag = 1;
		if(x < 0)
			flag = -1;
		if(x <= 9 && x >= -9)
			return x;
		
		long long ret = 0;
		long long input = flag * (long long)x;
		
		while(input > 0){
			ret = ret*10 + input%10;
			input /= 10;
		}
		
		if(flag == 1){
			if(ret > INT_MAX)
				return INT_MAX;
			return ret;
		}
		else{
			if(-ret < INT_MIN)
				return INT_MIN;
			return -ret;
		}
    }
};