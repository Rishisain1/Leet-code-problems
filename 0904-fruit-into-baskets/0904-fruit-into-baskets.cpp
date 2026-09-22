class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0,n=fruits.size(),t1=-1,t2=-1,f1=0,f2=0,ans=0;
        while(j<n){
            if(t1==-1||t1==fruits[j]){
                t1=fruits[j];
                f1++;
            }
            else if(t2==-1||t2==fruits[j]){
                t2=fruits[j];
                f2++;
            }
            else{
                while(f1!=0&&f2!=0){
                    if(fruits[i]==t1){
                        f1--;
                    }
                    else{
                        f2--;
                    }
                    i++;
                }
                if(f1==0){
                    f1=1;
                    t1=fruits[j];
                }
                else{
                    f2=1;
                    t2=fruits[j];
                }
            }
            ans=max(ans,f1+f2);
            j++;
        }
        ans=max(ans,f1+f2);
        return ans;
    }
};