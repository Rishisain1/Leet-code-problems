class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int first=-1,second=-1,n=fruits.size();
        vector<int> freq(2,0);
        int ans=0;
        int i=0,j=0;
        while(j<n){
            if(first==-1||fruits[j]==first){
                first=fruits[j];
                freq[0]++;
            }
            else if(second==-1||fruits[j]==second){
                second=fruits[j];
                freq[1]++;
            }
            else{
                // int f=first,s=second;
                // vector<int> temp=freq;
                while(i<n){
                    if(fruits[i]==first){
                        freq[0]--;
                        if(freq[0]==0){
                            first=fruits[j];
                            freq[0]=1;
                            i++;
                            break;
                        }
                        i++;
                    }
                    else{
                        freq[1]--;
                        if(freq[1]==0){
                            second=fruits[j];
                            freq[1]=1;
                            i++;
                            break;
                        }
                        i++;
                    }
                }
            }
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};