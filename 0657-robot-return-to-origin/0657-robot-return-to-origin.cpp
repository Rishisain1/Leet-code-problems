class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(auto m:moves){
            if(m=='U'){
                i--;
            }
            else if(m=='D'){
                i++;
            }
            else if(m=='R'){
                j++;
            }
            else{
                j--;
            }
        }
        return i==0&&j==0;
    }
};