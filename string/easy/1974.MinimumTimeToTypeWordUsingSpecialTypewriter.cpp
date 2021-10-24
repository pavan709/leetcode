// https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
class Solution {
public:
    int minTimeToType(string word) {
        int ans=0;
        char pre='a';
        for(char cur:word)
        {
            ans+=min(abs(cur-pre),26-abs(cur-pre))+1;
            pre=cur;
        }
        return ans;
    }
};