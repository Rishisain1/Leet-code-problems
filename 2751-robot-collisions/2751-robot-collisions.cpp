class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        set<pair<int,int>> set;
        int n=positions.size();
        for(int i=0;i<n;i++){
            set.insert({positions[i],i});
        }
        stack<int> stack;
        for(auto [position,i]:set){
            if(directions[i]=='R'){
                stack.push(i);                
            }
            else{// case for L
                while(stack.size()>0){
                    int j=stack.top();
                    if(healths[j]>healths[i]){
                        healths[j]--;
                        healths[i]=-1;
                        break;
                    }
                    else if(healths[j]==healths[i]){
                        stack.pop();
                        healths[j]=-1;
                        healths[i]=-1;
                        break;
                    }
                    else{
                        stack.pop();
                        healths[j]=-1;
                        healths[i]--;
                    }
                }

            }
        }
        int i=0;
        for(int i=0;i<healths.size();i++){
            if(healths[i]==-1){
                healths.erase(healths.begin()+i);
                i--;
            }
        }
        return healths;
    }
};