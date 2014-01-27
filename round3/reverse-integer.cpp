class Solution {
public:
    int reverse(int x) {
		long long a = (long long) x;
		int flag = 1;
		if(a < 0){
			flag = -1;
			a = -a;
		}
		long long b = 0;
		while(a){
			b = b*10+a%10;
			a /= 10;
		}
		if(flag == 1){
			return b;
		}
		return -b;
    }
};
