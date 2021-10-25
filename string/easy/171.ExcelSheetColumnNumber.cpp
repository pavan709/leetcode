// https://leetcode.com/problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string cl) {
        int ans=0,n=cl.size();
        for(int i=0;i<n;i++)
        {
            ans=(ans*26)+((cl[i]-'A')+1);
        }
        return ans;
    }
};