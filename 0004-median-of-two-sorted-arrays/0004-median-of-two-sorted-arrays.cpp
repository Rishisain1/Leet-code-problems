class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0;
        int j=0;
        
        int n=nums1.size();
        int m=nums2.size();
        vector<double> arr;
        while(i<n&&j<m){
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i++]);
            }
            else{
                arr.push_back(nums2[j++]);
            }
        }
        while(i<n){
             arr.push_back(nums1[i++]);
        }
        while(j<m){
             arr.push_back(nums2[j++]);
        }
        int l=arr.size();
        cout<<l;
        if(l%2==0){
            return (arr[l/2]+arr[(l/2)-1])/2;
        }
        else{
            return arr[l/2];
        }
    }
};