class Solution {
public:

void bitcount(vector<int>& nums,unordered_map<int,int> &bitc){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int x=nums[i];
        int count=0;
        while(x>0){
            if(x&1){
                count++;
            }
            x=x>>1;
        }
        bitc[nums[i]]=count;
    }
}

    bool canSortArray(vector<int>& nums) {
        vector<vector<int>> temp;
        
        int n=nums.size();        
        unordered_map<int,int> bitc;
        bitcount(nums,bitc);
        int prev=-1;
        vector<int> temp1;
        for(auto i:nums){
            if(prev==-1){
                temp1.push_back(i);
                prev=i;
            }
            else{
                if(bitc[prev]==bitc[i]){
                    temp1.push_back(i);
                    prev=i;
                }
                else{
                    temp.push_back(temp1);
                    temp1.clear();
                    temp1.push_back(i);
                    prev=i;

                }
            }
        }
        temp.push_back(temp1);
        sort(nums.begin(),nums.end());
        for(auto &u:temp){// in this line you forget to pass by value so it not really sort the temp 
            sort(u.begin(),u.end());
        }
        temp1.clear();
        for(auto u:temp){
            for(auto i:u){
                temp1.push_back(i);
            }
        }
        if(temp1==nums){
            return true;
        }
        return false;
    }
};