// https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string lword;
        while(ss>>lword);
        return lword.size();
    }
};