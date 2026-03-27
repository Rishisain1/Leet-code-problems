class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat[0].size();
        k=k%n;
        if(k==0)return true;
        for(auto arr:mat){
            vector<int> nums=arr;
            rotate(arr.begin(),arr.begin()+k,arr.end());
            if(arr!=nums){
                return false;
            }
        }
        return true;
    }
};