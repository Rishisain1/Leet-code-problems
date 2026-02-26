class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int count=0;
        while(n>1){
            count++;
            if(s[n-1]=='1'){
                int i=n-1;
                char c='0';
                while(i>=0){
                    if(s[i]=='1'){
                        
                        s[i]='0';
                        c='1';
                    }
                    else if(s[i]=='0'&&c=='1'){
                        s[i]='1';
                         c='0';
                         break;               
                    }
                    i--;
                }
                if(c=='1'){
                    s="1"+s;
                    n++;
                }
            }
            else{
                n--;
            }
        }
        return count;
    }
};