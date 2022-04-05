class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int num1=edges[0][0],num2=edges[0][1];
        if(num1==edges[1][0]||num1==edges[1][1])
        return num1;
        
        return num2;
    }
};