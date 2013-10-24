class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        long long ret = 0;
        long long n = (long long) x;
        
        int flag = 1;
        if(n < 0){
            n = -n;
            flag = -1;
        }
        
        while(n){
            ret = ret * 10 + n % 10;
            n /= 10;
        }
        
        return (int) (flag*ret);
    }
};