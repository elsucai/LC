class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!s)
            return 0;
        int size = strlen(s);
        int b, e;
        
        for(e = size-1; e >= 0 && s[e] == ' '; e--)
            ;
        if(e < 0)
            return 0;
        
        for(b = e; b >= 0 && s[b] != ' '; b--)
            ;
        
        b++;
        
        return e-b+1;
    }
};
