// https://leetcode.com/problems/find-the-difference/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size(),m=t.size(),as[26]={},at[26]={};
        for(int i=0;i<n;i++) as[s[i]-'a']++;
        for(int i=0;i<m;i++) at[t[i]-'a']++;
        for(int i=0;i<26;i++) if(as[i]!=at[i]) return ('a'+i);
        return 'a';
    }
};