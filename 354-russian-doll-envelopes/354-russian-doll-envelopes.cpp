class Solution {
    bool static comp(vector<int>& a, vector<int>& b){
        if(a[0]==b[0]) 
        return a[1]>b[1];
        return a[0]<b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        int n = en.size();
        sort(en.begin(), en.end(), comp);
        vector<int> lis;
        for(int i = 0;i<en.size();i++){
        int ele = en[i][1];
        int idx = lower_bound(lis.begin(), lis.end(), ele) - lis.begin();    
        if(idx >= lis.size())
        lis.push_back(ele);
        else 
        lis[idx] = ele;
        }
        return lis.size();
    }
};
/*
[[1,2],[2,3],[2,6],[3,4]]
[[1,2],[2,6],[2,4],[2,3],[3,4]]
*/