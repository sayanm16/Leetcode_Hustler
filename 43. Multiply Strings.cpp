class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        int max_len=len1+len2;
        int i=len2-1;
        vector<int>result(max_len,0);
        int pf=0;
        while(i>=0){
            int j=len1-1;
            int ival=num2[i]-'0';
            int carry=0;
            int k=result.size()-1-pf;
            while(j>=0 || carry!=0){
                int jval=j>=0?num1[j]-'0':0;
                int product=ival*jval+carry+result[k];
                result[k]=product%10;
                carry=product/10;
                k--;
                j--;
            }
            pf++;
            i--;
        }
        string ans="";
         i=0;
        while(i<result.size() && result[i]==0) i++;
        while(i<result.size()){
            ans+=result[i]+'0';
            i++;
        }
        if(ans.length()==0) ans+='0';
        return ans;
    }
};
