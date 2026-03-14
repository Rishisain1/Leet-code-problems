class Solution {
public:

void solve(int i,int n,string temp,vector<string> &arr){
    if(i+1>=n){
       arr.push_back(temp);
        return;
    }
    if(temp[i]=='a'){
        solve(i+1,n,temp+'b',arr);
        solve(i+1,n,temp+'c',arr);
    }
    if(temp[i]=='b'){
        solve(i+1,n,temp+'a',arr);
        solve(i+1,n,temp+'c',arr);
    }
    if(temp[i]=='c'){
        solve(i+1,n,temp+'a',arr);
        solve(i+1,n,temp+'b',arr);
    }
}

    string getHappyString(int n, int k) {
        vector<string> arr;
        solve(0,n,"a",arr);
        solve(0,n,"b",arr);
        solve(0,n,"c",arr);
        if(arr.size()<k){
            return "";
        }
        return arr[k-1];
    }
};