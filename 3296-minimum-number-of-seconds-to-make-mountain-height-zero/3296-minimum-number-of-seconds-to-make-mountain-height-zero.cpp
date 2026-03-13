class Solution {
public:
    bool solve(long long mid,long long mountainHeight, vector<int>&time){
       long long heightBreaken=0;
       for(auto&ti:time){
           long long h=(-1+sqrt(1+8*mid/ti))/2;
           heightBreaken+=h;
           if(heightBreaken>=mountainHeight)return true;
       }
       return heightBreaken>=mountainHeight;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long l=1,r=1e18;
        long long ans=-1;
        while(l<=r){
           long long mid=l+(r-l)/2;
           if(solve(mid,mountainHeight,workerTimes)){
             ans=mid;
             r=mid-1;
           }else{
             l=mid+1;
           }
        }
        return ans;
    }
};