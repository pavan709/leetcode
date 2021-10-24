// https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());reverse(b.begin(),b.end());
        string res;
        if(a.size()>b.size())
        {
            string temp=a;a=b,b=temp;
        }
        int i=0;char prev='0';
        while(i<a.size())
        {
            if(a[i]=='0'&&b[i]=='0')
                res.push_back(prev),prev='0';
            else if(a[i]=='1'&&b[i]=='1')
                res.push_back(prev),prev='1';
            else if(a[i]=='0'||b[i]=='0')
            {
                if(prev=='1')
                    res.push_back('0');
                else
                    res.push_back('1');
            }
            i++;
        }
        while(i<b.size())
        {
            if(prev=='1'&&b[i]=='1')
                res.push_back('0');
            else if(prev=='0'&&b[i]=='0')
                res.push_back('0');
            else if(prev=='0'||b[i]=='0')
            {
                res.push_back('1');prev='0';
            }
            i++;
        }
        if(prev=='1')
            res.push_back('1');
        reverse(res.begin(),res.end());
        return res;
    }
};