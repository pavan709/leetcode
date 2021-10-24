// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> se;
        int res=0,temp=0,j=0;
        for(int i=0;i<s.size();i++)
        {
            if(se.count(s[i]))
            {
                int k=j;
               for(;s[k]!=s[i];k++)
               {
                   temp--;
                   se.erase(s[k]);
               }
                res=max(temp,res);
                 j=k+1;
            }
            else
            {
                se.insert(s[i]);
                temp++;
                res=max(res,temp);
            }
        }
        res=max(res,temp);
        return res;
    }
};