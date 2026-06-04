class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num2<100)return 0;
        int ans=0;
        for(int i=num1;i<=num2;i++){
            if(i<101)continue;
            vector<int> temp;
            int x=i;
            while(x>0){
                temp.push_back(x%10);
                x=x/10;
            }
            int n=temp.size();
            for(int j=1;j<n-1;j++){
                if((temp[j]>temp[j-1]&&temp[j]>temp[j+1])||(temp[j]<temp[j-1]&&temp[j]<temp[j+1])){
                    ans++;
                }
            }
        }
        return ans;
    }
};