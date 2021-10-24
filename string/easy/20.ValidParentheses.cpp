// https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        if(s.size()==1)
            return 0;
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else
            {
                if(st.size()!=0&&st.top()=='('&&s[i]==')')
                    st.pop();
                else if(st.size()!=0&&st.top()=='{'&&s[i]=='}')
                    st.pop();
                else if(st.size()!=0&&st.top()=='['&&s[i]==']')
                    st.pop();
                else 
                    return false;
            }
        }
         if(st.size()!=0)
             return false;
        return true;
    }
};