class Solution {
public:
// one more impreovement as the whole code is same so instead of two different function call we done it in a single function
// void buildpsmin(vector<vector<int>> &spmin,vector<int>& nums,int n){
//     int m=nums.size();
//     for(int i=0;i<m;i++){
//         spmin[0][i]=nums[i];
//     }
//     for(int a=1;a<n;a++){
//         int i=0;
//         int p2=pow(2,a-1);
//         while( i+p2 <m){
//             spmin[a][i]=min(spmin[a-1][i],spmin[a-1][i+p2]);
//             i++;
//         }
//     }
// }

// void buildpsmax(vector<vector<int>> &spmin,vector<int>& nums,int n){
//     int m=nums.size();
//     for(int i=0;i<m;i++){
//         spmin[0][i]=nums[i];
//     }
//     for(int a=1;a<n;a++){
//         int i=0;
//         int p2=pow(2,a-1);
//         while( i+p2 <m){
//             spmin[a][i]=max(spmin[a-1][i],spmin[a-1][i+p2]);
//             i++;
//         }
//     }
// }

void buildsp(vector<vector<int>> &spmin,vector<vector<int>> &spmax,vector<int>& nums,int n){
    int m=nums.size();
    for(int i=0;i<m;i++){
        spmin[0][i]=nums[i];
        spmax[0][i]=nums[i];
    }
    for(int a=1;a<n;a++){
        int i=0;
        int p2=pow(2,a-1);
        while( i+p2 <m){
            spmin[a][i]=min(spmin[a-1][i],spmin[a-1][i+p2]);
            spmax[a][i]=max(spmax[a-1][i],spmax[a-1][i+p2]);
            i++;
        }
    }
}


// intead of range use log2  in built function 
// vector<int> range(int n){
//         vector<int> result;
//         int p2=1;
//         int count=0;
//         while(p2<n){
//             p2*=2;
//             count++;
//         }
//         while(n>0){
//             if(n>=p2){
//                 result.push_back(count);
//                 n-=p2;
//             }
//             p2/=2;
//             count--;
//         }
//         return result;
//     }

    long long maxTotalValue(vector<int>& nums, int k) {
       
        int n=nums.size();
        int m=1;
        int count=1;
        while(m<=n){
            m*=2;
            count++;
        }
        if(m>n){
            count--;
        }
        vector<vector<int>> spmin(count,vector<int>(n));
        vector<vector<int>> spmax(count,vector<int>(n));
        // buildpsmin(spmin,nums,count);
        // buildpsmax(spmax,nums,count);
        buildsp(spmin,spmax,nums,count);
        priority_queue<tuple<int,int,int>> pq;
        for(int i=0;i<n;i++){
            // vector<int> op=range(n-i);//instead of this use the log2 
            // int j=i;// instead of two seperate for loops we do it in 1 for loop 
            // int mini=INT_MAX;
            // int maxi=INT_MIN;
            // for(int o:op){
            //     mini=min(mini,spmin[o][j]);
            //     maxi=max(maxi,spmax[o][j]);
            //     j+=pow(2,o);
            // }
            int len=n-i;
            int j=i;
            int mini=INT_MAX;
            int maxi=INT_MIN;
            while(len>0){
                int p=log2(len);
                mini=min(mini,spmin[p][j]);
                maxi=max(maxi,spmax[p][j]);
                len-=pow(2,p);
                j+=pow(2,p);
            }
            pq.push({maxi-mini,i,n-1});
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            auto [a,l,r]=pq.top();
            pq.pop();
            ans+=a;
            int len=r-l;
            int j=l;
            int mini=INT_MAX;
            int maxi=INT_MIN;
            while(len>0){
                int p=log2(len);
                mini=min(mini,spmin[p][j]);
                maxi=max(maxi,spmax[p][j]);
                len-=pow(2,p);
                j+=pow(2,p);
            }
            if(maxi!=INT_MIN)
            pq.push({maxi-mini,l,r-1});

        }
        return ans;
    }
};