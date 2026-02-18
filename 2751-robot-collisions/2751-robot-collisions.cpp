class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

// we are not going to use set because it take more time as compare to sort a vector not complexity wise but the constant factor of set is more because it implement using red black tree

        // set<pair<int,int>> set; 
        // for(int i=0;i<n;i++){
        //     set.insert({positions[i],i});
        // }

        vector<pair<int,int>> sortedpos;
        for(int i=0;i<n;i++){
            sortedpos.push_back({positions[i],i});
        }
        sort(sortedpos.begin(),sortedpos.end());
        stack<int> stack;
        for(auto [position,i]:sortedpos){
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
        // this way is very heavy so we use another array
        // for(int i=0;i<healths.size();i++){
        //     if(healths[i]==-1){
        //         healths.erase(healths.begin()+i);
        //         i--;
        //     }
        // }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(healths[i]!=-1){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};