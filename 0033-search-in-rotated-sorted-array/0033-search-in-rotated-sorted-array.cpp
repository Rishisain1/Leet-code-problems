class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[0]>target){
                if(arr[mid]>=arr[0]){
                    s=mid+1;
                }
                else{
                    if(arr[mid]>target){
                        e=mid-1;
                    }
                    else{
                        s=mid+1;
                    }
                }
            }
            else{
                if(arr[mid]<arr[0]){
                    e=mid-1;
                }
                else{
                    if(arr[mid]>target){
                        e=mid-1;
                    }
                    else{
                        s=mid+1;
                    }
                }
            }
        }
        return -1;
    }
};