class Solution {
public:
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

    int f=0;
    unordered_map<int,int>m;
    
    for(auto u:A)
        for(auto v:B)
            m[u+v]++;

    for(auto u:C)
        for(auto v:D)
        {
            auto it=m.find(0-u-v);
            if(it!=m.end())
                f += it->second;
        }

    return f;
}
};