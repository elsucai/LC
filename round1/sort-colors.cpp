class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1)
        	return;
        	
        int rc, wc, bc;
        int r, w, b, i;
        rc = wc = bc = 0;
        for(i = 0; i < n; i++){
        	switch(A[i]){
        		case 0:
        			rc++;
        			break;
        		case 1:
        			wc++;
        			break;
        		case 2:
        			bc++;
        			break;
        		default:
        			break;
        	}
        }
        
        r = 0;
        w = rc;
        b = rc+wc;
        
        for(i = 0; i < n; ){
        	switch(A[i]){
        		case 0:	// red
        			if(i >= rc){
        				// need swap
        				while(A[r] == 0)
        					r++;
        				swap(A[i], A[r]);
        				r++;
        			}
        			else
        				i++;
        			break;
        		case 1:	// white
        			if(i < rc || i >= rc+wc){
        				// need swap
        				while(A[w] == 1)
        					w++;
        				swap(A[i], A[w]);
        				w++;
        			}
        			else
        				i++;
        			break;
        		case 2:	// blue
        			if(i < rc+wc){
        				// need swap
        				while(A[b] == 2)
        					b++;
        				swap(A[i], A[b]);
        				b++;
        			}
        			else
        				i++;
        			break;
        		default:
        			break;	        			
        	}
        }
    }
};
