class Solution {
public:

    void solve(string &customers,vector<int> &Y,vector<int> &N){
        int y=0,n=0;
        int m=customers.size();
        for(int i=0;i<m;i++){
            if(customers[i]=='N')n++;
            N[i+1]=n;
        }
        for(int i=m-1;i>=0;i--){
            Y[i+1]=y;
            if(customers[i]=='Y')y++;
        }
        Y[0]=y;

    }

    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> Y(n+1,0);
        vector<int> N(n+1,0);
        solve(customers,Y,N);

        int ans=-1;
        int penality=INT_MAX;
        for(int i=0;i<=n;i++){
            if(Y[i]+N[i]<penality){
                ans=i;
                penality=Y[i]+N[i];
            }
        }
        return ans;
    }
};