class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		
		if(n == 0)
			return 0;
		int s, e;
		s = 0;
		e = n-1;
		while(s <= e){
			while(s < n && A[s] != elem)
				s++;
			while(e >= 0 && A[e] == elem)
				e--;

			// s needs to be replaced
			if(s > e)
				break;
			swap(A[s], A[e]);
			s++;
			e--;
		}
		return s;
    }
};
