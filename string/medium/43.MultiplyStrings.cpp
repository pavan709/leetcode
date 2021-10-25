// https://leetcode.com/problems/multiply-strings/
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;int a,b,c=0,d=0;
        reverse(num1.begin(),num1.end());reverse(num2.begin(),num2.end());
        // cout<<num2<<" "<<num1<<endl;
        for(int i=0;i<num2.size();i++)
        {
            string temp;   
            a=num2[i]-'0';
            d=0;
                for(int j=0;j<num1.size();j++)
                {
                    b=num1[j]-'0';
                    c=(a*b+d)%10;
                    d=(a*b+d)/10;
                    temp.push_back('0'+c);
                }
         if(d)
             temp.push_back('0'+d);
            
         int j=i,k=0;d=0;
         while(j<res.size()&&k<temp.size())
         {
             a=res[j]-'0',b=temp[k]-'0';
             c=(a+b+d)%10;
             d=(a+b+d)/10;
             res[j]='0'+c;
             j++,k++;
         }
            
         while(k<temp.size())
         {
             b=temp[k]-'0';
             c=(b+d)%10;
             d=(b+d)/10;
             // cout<<c;
             res.push_back('0'+c);
             k++;
         }
         if(d)
             res.push_back('0'+d);
        }
        
        reverse(res.begin(),res.end());
        bool flag=1;
        for(char x:res)
            if(x!='0')
                flag=0;
        if(flag)
            return "0";
        return res;
    }
};