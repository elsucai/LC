class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 1)
            return s;
        vector<string> ret(nRows, "");
        int row = 0;
        int inc = 1;
        for(int i = 0; i < s.size(); i++){
            ret[row] += s.substr(i, 1);
            row += inc;
            if(row == nRows-1 || row == 0)
                inc *= -1;
        }
        string rs = "";
        for(int i = 0; i < nRows; i++)
            rs += ret[i];
        return rs;
    }
};
