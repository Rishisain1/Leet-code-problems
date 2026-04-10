class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        unordered_map<int,vector<int>> arr;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            arr[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto [i,f]:freq){
            if(f>=3){
                int j=arr[i][0],k=arr[i][1],l;
                int x=2;
                while(f>=3){
                    l=arr[i][x];
                    ans=min(ans,2*(l - j));
                    j=k;
                    k=l;                    
                    x++;
                    f--;
                }

            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};