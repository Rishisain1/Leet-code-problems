class Solution {
public:

    vector<int> solvel(vector<int>& height){
        int n=height.size();
        vector<int>temp(n);
        stack<int> stack;
        stack.push(-1);
        for(int i=0;i<n;i++){
            while(stack.top()!=-1&&height[stack.top()]<height[i])stack.pop();//here we can't pop equal heights 
            temp[i]=stack.top();
            stack.push(i);
        }
        return temp;
    }
    vector<int> solver(vector<int>& height){
        int n=height.size();
        vector<int>temp(n);
        stack<int> stack;
        stack.push(-1);
        for(int i=n-1;i>=0;i--){
            while(stack.top()!=-1&&height[stack.top()]<height[i])stack.pop();//here we can't pop equal heights 
            temp[i]=stack.top();
            stack.push(i);
        }
        return temp;
    }

    int trap(vector<int>& height) {
        vector<int> left=solvel(height);
        vector<int> right=solver(height);
        int ans=0;
        int n=height.size();
        int i=0;
        while(i<n){
            if(left[i]!=-1){               
                int water=min(height[i],height[left[i]]);
                for(int j=i-1;j>left[i];j--){
                    ans+=(water-height[j]);
                    height[j]=water;
                }
            }
            if(right[i]!=-1){
                int water =min(height[i],height[right[i]]);
                for(int j=i+1;j<right[i];j++){
                    ans+=(water-height[j]);
                    height[j]=water;
                }
                i=right[i];
            }
            else{
                i++;
            }
        }
        return ans;
    }
};