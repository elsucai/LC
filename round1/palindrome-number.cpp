#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
/*
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
    	if(x < 0)
			return false;

		int last, first, d;
		while(x >= 10){
			last = x%10;
			x /= 10;
			d = 10;
			while(x/d > 0)
				d *= 10;
			d /= 10;
			first = x/d;
			if(first != last)
				return false;
			x = x - first*d;
		}
		return true;
	}
*/

	bool isPalindrome(int x) {
		if (x < 0) return false;
		int div = 1;
		while (x / div >= 10) {
			div *= 10;
		}        
		while (x != 0) {
			cout<<"x = "<<x<<endl;
			int l = x / div;
			int r = x % 10;
			cout<<"l - r: "<<l<<" - "<<r<<endl;
			if (l != r) return false;
			x = (x % div) / 10;
			div /= 100;
		}
		return true;
	}
};

int main(){

	Solution s;
	cout<<s.isPalindrome(10101)<<endl;
	return 0;
}

