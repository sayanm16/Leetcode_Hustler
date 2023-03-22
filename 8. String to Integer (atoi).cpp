class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' ')i++;
        int sign=1;
        if(s[i]=='+' || s[i]=='-'){
            if(s[i]=='-') sign= -1;
            i++;
        }
        int ans=0;
        
        for(;i<s.size();i++){
            if(!isdigit(s[i])) return ans;
            int dig= (s[i]-'0')*sign;
            if(sign== 1 && (ans> INT_MAX/10  || (ans==INT_MAX/10 && dig>(INT_MAX%10)))) return INT_MAX;
            if(sign== -1 && (ans< INT_MIN/10 || (ans==INT_MIN/10 && dig<(INT_MIN%10)))) return INT_MIN;
            
            ans= (1LL*ans*10)+ dig;
        }
        return ans;
    }
};
