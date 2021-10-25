// https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        string a,b;
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i])||isalnum(s[i]))
            {
                a.push_back(tolower(s[i]));
                b.push_back(tolower(s[i]));
            }
        }
        reverse(a.begin(),a.end());
        return a==b;
    }
};