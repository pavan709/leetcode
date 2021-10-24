// https://leetcode.com/problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int cl) {
        string res;
        while(cl)
        {
            cl--;
            int mod = cl%26;
            res.push_back('A'+mod);
            cl=cl/26;
        }

        reverse(res.begin(),res.end());
        return res;
        
    }
};