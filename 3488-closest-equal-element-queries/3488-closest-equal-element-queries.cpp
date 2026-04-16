class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> pos;
        unordered_map<int,int> indx;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pos[nums[i]].push_back(i);
            indx[i]=(pos[nums[i]].size())-1;
        }
        vector<int> ans;
        for(auto q:queries){
            auto &arr=pos[nums[q]];
            int j=indx[q];
            int m=arr.size();
            if(m==1){
                ans.push_back(-1);
                continue;
            }
            if(j==0){
                int left=n-arr[m-1]+arr[0];
                int right=arr[j+1]-arr[j];
                ans.push_back(min(left,right));
            }
            else if(j==m-1){
                int left=arr[j]-arr[j-1];
                int right=n-arr[j]+arr[0];
                ans.push_back(min(left,right));
            }
            else{
                int left=arr[j]-arr[j-1];
                int right=arr[j+1]-arr[j];
                ans.push_back(min(left,right));
            }
        }
        return ans;
    }
}; 