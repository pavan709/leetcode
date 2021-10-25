// https://leetcode.com/problems/ransom-note/
class Solution {
public:
    bool canConstruct(string r, string m) {
        int n=r.size(),o=m.size(),ar[26]={},am[26]={};
        for(int i=0;i<n;i++) ar[r[i]-'a']++;
        for(int i=0;i<o;i++) am[m[i]-'a']++;
        for(int i=0;i<26;i++) if(ar[i]>am[i]) return false;
        return true;
    }
};