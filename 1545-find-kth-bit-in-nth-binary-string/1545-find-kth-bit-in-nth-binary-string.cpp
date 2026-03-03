class Solution {
public:

string ri(string str){
    string invert=str;
    int n=str.length();
    for(int i=0;i<n;i++){
        if(str[i]=='0'){
            invert[i]='1';
        }
        else{
            invert[i]='0';
        }
    }
    reverse(invert.begin(),invert.end());

    return invert;
}
    char findKthBit(int n, int k) {
        string s="0";
    for(int i=1;i<n;i++){
        string temp=s+"1"+ri(s);
        s=temp;

    }
    return s[k-1];
    }
};