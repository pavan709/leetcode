// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    string ar[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res={};
    void dfs(string d,int i,string s)
    {
        if(i==d.size())
        {
            res.push_back(s);
            return;
        }
        for(char c:ar[d[i]-'0'])
        {
            s.push_back(c);
            dfs(d,i+1,s);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;
        dfs(digits,0,"");
        return res;
    }
};