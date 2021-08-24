class Solution {
public:
    vector<int> minOperations(string boxes) {
    int n=boxes.length();
    vector<int> ans(n);
    vector<int> pos;
    for(int i=0;i<n;i++)
    {
        if(boxes[i]=='1')
        pos.push_back(i);    
    }
    for(int i=0;i<n;i++)
    {
        for(int num:pos)
        {
            ans[i]+=abs(num-i);
        }    
    }  
    return ans;    
    }
};