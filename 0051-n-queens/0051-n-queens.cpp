class Solution {
public:

bool check(vector<string> &board,int i,int j,int n){
    int dif=i-j;
    int sum=i+j;
    for(int l=0;l<i;l++){
        for(int k=0;k<n;k++){
            if(board[l][k]=='Q'){
                if(l-k==dif){
                    return false;
                }
                if(l+k==sum){
                    return false;
                }
                if(k==j){
                    return false;
                }
            }
        }
    }
    return true;
}
void solve(vector<string> &board,int &n,vector<vector<string>> &ans,int i){
    if(i>=n){
        ans.push_back(board);
    }
    for(int j=0;j<n;j++){
        if(check(board,i,j,n)){
            board[i][j]='Q';
            solve(board,n,ans,i+1);
            board[i][j]='.';
        }
    }
}

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for(int i=0;i<n;i++){
            string temp=string(n,'.');
            board.push_back(temp);
        }
        vector<vector<string>> ans;
        solve(board,n,ans,0);
        return ans;

    }
};