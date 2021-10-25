// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char> sm,tm;int n=t.size();
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            if(sm.count(c))
            {
                if(sm[c]!=t[i])
                    return false;
            }
            else if(tm.count(t[i]))
            {
                if(tm[t[i]]!=s[i])
                    return false;
            }
            else
                sm[c]=t[i],tm[t[i]]=c;
        }
        return true;
    }
};