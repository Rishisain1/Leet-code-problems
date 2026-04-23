class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<long long>> pos;
        int n=nums.size();
         vector<long long> ans(n,0);
        for(int i=0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        for(auto &[a,arr]:pos){
            int m=arr.size();
            if(m==1){
                continue;
            }
            vector<long long> pre(m);
            vector<long long> post(m);
            long long pr=0;
            for(int i=0;i<m;i++){
                pre[i]=pr;
                pr+=arr[i];
            }
            long long po=0;
            for(int i=m-1;i>=0;i--){
                post[i]=po;
                po+=arr[i];
            }
            for(int i=0;i<m;i++){
                long long sum=abs(arr[i]*i - pre[i]);
                sum+= abs(arr[i]*(m-i-1)-post[i]);
                ans[arr[i]]=sum;
            }
        }
        return ans;
    }
};