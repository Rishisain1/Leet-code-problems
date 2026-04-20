class Solution {
public:
    int maxDistance(vector<int>& colors) {
        for(int i = 0; i < colors.size()-1; i++) {
    if(colors[0] != colors[colors.size()-1-i] || colors[colors.size()-1] != colors[i]) {
        return colors.size()-i-1;
    }
}
return 0;
    }
};