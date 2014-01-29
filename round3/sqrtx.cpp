class Solution {
public:
    int sqrt(int x) {
		if(x <= 0)
			return 0;
		int s = 1;
		int e = x;
		int cur, val;
		while(s <= e){
			cur = s + (e-s)/2;
			val = x/cur;
			if(val == cur)
				return cur;
			if(val < cur)
				e = cur-1;
			else
				s = cur+1;
		}
		return e;
    }
};
