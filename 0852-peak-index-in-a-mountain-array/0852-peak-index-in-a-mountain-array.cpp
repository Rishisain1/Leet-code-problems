class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int left=0,right=n-1;
        while(left<=right){
            int mid=(left+right)/2;
            
            if(arr[mid+1]<arr[mid]&&arr[mid-1]<arr[mid])return mid;
            else if(arr[mid-1]<arr[mid]) left=mid;
            else right=mid;
        }
        return -1;
    }
};