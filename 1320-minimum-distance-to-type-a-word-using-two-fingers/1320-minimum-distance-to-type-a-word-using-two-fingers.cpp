class Solution {
public:
unordered_map<char,pair<int,int>> keyboard;
map<vector<int>,int> dp;
// vector<int>dp;
Solution(){
    keyboard={{'A',{0,0}},
            {'B',{0,1}},
            {'C',{0,2}},
            {'D',{0,3}},
            {'E',{0,4}},
            {'F',{0,5}},
            {'G',{1,0}},
            {'H',{1,1}},
            {'I',{1,2}},
            {'J',{1,3}},
            {'K',{1,4}},
            {'L',{1,5}},
            {'M',{2,0}},
            {'N',{2,1}},
            {'O',{2,2}},
            {'P',{2,3}},
            {'Q',{2,4}},
            {'R',{2,5}},
            {'S',{3,0}},
            {'T',{3,1}},
            {'U',{3,2}},
            {'V',{3,3}},
            {'W',{3,4}},
            {'X',{3,5}},
            {'Y',{4,0}},
            {'Z',{4,1}},};
}

int solve(string &word,int i,int lx,int ly,int rx,int ry){
    if(i>=word.length()){return 0;}  

    if(dp.count({i,lx,ly,rx,ry}))return dp[{i,lx,ly,rx,ry}];

    auto[x1,y1] =keyboard[word[i]];
    
    int disl=abs(lx-x1)+abs(ly-y1)+solve(word,i+1,x1,y1,rx,ry);
    
    int disr;
   
    if(rx==-1)disr=solve(word,i+1,lx,ly,x1,y1);
    else{
        disr=abs(rx-x1)+abs(ry-y1)+solve(word,i+1,lx,ly,x1,y1);
    }
    

    return dp[{i,lx,ly,rx,ry}]=min(disl,disr);
}

    int minimumDistance(string word) {
        auto[lx,ly]=keyboard[word[0]];
        
        return solve(word,1,lx,ly,-1,-1);
    }
};