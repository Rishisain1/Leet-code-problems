class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int,int>> arr;
        int n=positions.size();
        for(int i=0;i<n;i++){
            arr.push_back({positions[i],i});
        }
        sort(arr.begin(),arr.end());
        stack<int> stack;
        stack.push(-1);
        for(auto [p,i]:arr){
            int j=stack.top();
            if(directions[i]=='R'||(j==-1&&directions[i]=='R')){
                stack.push(i);
            }
            else if(directions[i]=='L'){
                if(j==-1){
                    continue;
                }
                else if(healths[i]==healths[j]){
                    healths[i]=-1;
                    healths[j]=-1;
                    stack.pop();
                }
                else if(healths[i]<healths[j]){
                    healths[i]=-1;
                    healths[j]-=1;
                }
                else{
                    while(stack.top()!=-1&&healths[stack.top()]<healths[i]){
                        healths[stack.top()]=-1;
                         healths[i]-=1;
                         stack.pop();
                    }
                    if(stack.top()!=-1&&healths[stack.top()]>healths[i]){
                        healths[i]=-1;
                        healths[stack.top()]-=1;
                    }
                    else if(stack.top()!=-1&&healths[stack.top()]==healths[i]){
                        healths[i]=-1;
                        healths[stack.top()]=-1;
                        stack.pop();
                    }
                }
            }
        }
        vector<int>ans;
        for(auto h:healths){
            if(h!=-1){
                ans.push_back(h);
            }
        }
        return ans;
    }
};