// https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s) {
    long long num=0,i=0;
    
    while(i<s.size() && s[i]==' ')
        i++;
    
    int sig=1;
    
    if(i<s.size() && s[i]=='-' || s[i]=='+'){
        
        sig = (s[i]=='-')? -1 : 1;
        i++;
    }
    
    while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9){
        
        num*=10;
        num+=s[i]-'0';
        
        if(sig==-1 && sig*num<INT_MIN)return INT_MIN;
        
        else if(sig==1 && sig*num>INT_MAX)return INT_MAX;
        
        i++;
    }
    
    return sig*num;
    }
};