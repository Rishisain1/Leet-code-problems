class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> queue;
        int n=arr.size();
        vector<int> visited(n,0);
        visited[start]=1;
        queue.push(start);
        while(!queue.empty()){
            int i=queue.front();
            queue.pop();
            if(arr[i]==0){
                return true;
            }
            if(arr[i]+i<n&&!visited[arr[i]+i]){
                queue.push(arr[i]+i);
                visited[arr[i]+i]++;
            }
            if(i-arr[i]>=0&&!visited[i-arr[i]]){
                queue.push(i-arr[i]);
                visited[i-arr[i]]++;
            }

        }
        return false;
    }
};