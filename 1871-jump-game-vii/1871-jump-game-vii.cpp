class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int far=0;
        int n=s.length();
        vector<int> arr(n,0);
        arr[0]=1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)continue;
            int start=max(minJump+i,far+1);
            int end=min(i+maxJump,n-1);
            for(int j=start;j<=end;j++){
                if(s[j]=='0'){
                    arr[j]=1;
                }
            }
            far=max(end,far);
        }
        return arr[n-1];
    }
};