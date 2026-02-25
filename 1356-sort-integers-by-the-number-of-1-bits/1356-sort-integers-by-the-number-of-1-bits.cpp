class Solution {
public:



    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> array;
        for(auto i:arr){
            array.push_back({__builtin_popcount(i),i});
        }
        sort(array.begin(),array.end());
        vector<int> ans;
        for(auto [s,i]:array){
            ans.push_back(i);
        }
        return ans;
    }
};