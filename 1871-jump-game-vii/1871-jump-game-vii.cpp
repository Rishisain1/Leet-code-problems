class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<int> arr(n,0);
        int rc=0;
        arr[0]=1;
        for(int i=1;i<n;i++){
            if(i-minJump>=0&&arr[i-minJump]){
                rc++;
            }
            if(i-maxJump-1>=0&&arr[i-maxJump-1]){
                rc--;
            }
            if(s[i]=='0'&&rc>0){
                arr[i]=1;
            }
        }
        return arr[n-1];
    }
};