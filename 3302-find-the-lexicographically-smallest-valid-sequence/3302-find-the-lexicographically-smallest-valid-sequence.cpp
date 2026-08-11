class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1=word1.length();
        int n2= word2.length();
        

        vector<int> matchcount(n1,0);
        int count=0;
        int j=n2-1;
        for(int i=n1-1;i>=0;i--){
            if(j>=0&&word1[i]==word2[j]){
                count++;
                j--;
            }
            matchcount[i]=count;
        }
        
        vector<int> seq;
        j=0;
        for(int i=0;i<n1;i++){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }
            else if(j>=n2){
                return seq;
            }
            else if(i+1<n1&&matchcount[i+1]>=n2-j-1){// we have to exclude the current index that why we check for i+1
                seq.push_back(i);
                j++;
                i++;
               
                while(i<n1&&j<n2){
                    if(word1[i]==word2[j]){
                        seq.push_back(i);
                        j++;
                    }
                    i++;
                }
                return seq;
            }
        }
        return {};
    }
};