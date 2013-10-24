class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  
  		if(n == 0 || n == 1)
  			return 1;
  		if(n == 2)
  			return 2;
  			
  		int left;
  		int right;
  		int sum;
  		sum = left = right = 0;
  		for(int i = 0; i < n; i++){
  			left = numTrees(i);
  			right = numTrees(n-1-i);
  			sum += left*right;
  		}
  		
  		return sum;
    }
};
