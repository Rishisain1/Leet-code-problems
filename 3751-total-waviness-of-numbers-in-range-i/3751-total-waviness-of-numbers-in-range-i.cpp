class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2<100)return 0;
        int ans=0;
        for(int i=num1;i<=num2;i++){
            if(i<101)continue;
            int a,b,c;
            int x=i;
            
            a=x%10;
            x/=10;
            b=x%10;
            x/=10;
            c=x%10;
            x/=10;
            if((a<b&&c<b)||(a>b&&c>b))ans++;
            while(x>0){
                a=b;
                b=c;
                c=x%10;
                x=x/10;
                if((a<b&&c<b)||(a>b&&c>b))ans++;
            }
        }
        return ans;
    }
};