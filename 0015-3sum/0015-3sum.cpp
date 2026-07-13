class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        map<tuple<int,int,int>,int> visited;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            int target=-(nums[i]);
            
            while(j<k){
                int sum=nums[j]+nums[k];
                if(sum<=target){
                    if(sum==target&&!visited.count({nums[i],nums[j],nums[k]})){
                        ans.push_back({nums[i],nums[j],nums[k]});
                        visited[{nums[i],nums[j],nums[k]}]=1;
                    }

                    
                    j++;
                    while(j<n&&nums[j-1]==nums[j]){
                        j++;
                    }
                }
               
                else{
                    k--;
                    while(k>=0&&nums[k+1]==nums[k]){
                        k--;
                    }
                }
            }
        }
        return ans;
        
    }
};