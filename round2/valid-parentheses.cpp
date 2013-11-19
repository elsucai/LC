class Solution {
public:
    bool isValid(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<char> st;
        if(s.empty())
            return true;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                    st.push(s[i]);
                    break;
                case ')':
                    if(st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                case '}':
                    if(st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                default:
                    return false;
            }
        }
        return st.empty();
    }
};