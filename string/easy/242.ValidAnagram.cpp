// https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size(),m=t.size();
        if(n!=m)
            return false;
        int ar[26]={};
        for(int i=0;i<n;i++) ar[s[i]-'a']++;
        for(int i=0;i<m;i++) ar[t[i]-'a']--;
        for(int i=0;i<26;i++) if(ar[i]!=0)  return false;
        return true;
    }
};