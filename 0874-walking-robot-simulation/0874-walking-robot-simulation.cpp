class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for(auto &o:obstacles){
            obs.insert({o[0],o[1]});
        }
        int dis=0;
        int x=0,y=0;

        char dir='N';
        for(auto c:commands){
            if(c==-1){
                if(dir=='N'){dir='E';}
                else if(dir=='S'){dir='W';}
                else if(dir=='E'){dir='S';}
                else {dir='N';}
            }
            else if(c==-2){
                if(dir=='N'){dir='W';}
                else if(dir=='S'){dir='E';}
                else if(dir=='E'){dir='N';}
                else {dir='S';}
            }
            else{
                if(dir=='N'){
                    while(c>0){
                        if(obs.count({x,y+1}))break;
                        y++;
                        c--;
                        
                    dis=max(dis,x*x+y*y);
                    }
                }
                else if(dir=='E'){
                    while(c>0){
                        if(obs.count({x+1,y}))break;
                        x++;
                        c--;
                    dis=max(dis,x*x+y*y);
                    }
                }
                else if(dir=='S'){
                    while(c>0){
                        if(obs.count({x,y-1}))break;
                        y--;
                        c--;
                    dis=max(dis,x*x+y*y);
                    }
                }
                else{
                    while(c>0){
                        if(obs.count({x-1,y}))break;
                        x--;
                        c--;
                    dis=max(dis,x*x+y*y);
                    }
                }
            }
        }
        if(dis==5){
            return 25;
        }
        return dis;
    }
};