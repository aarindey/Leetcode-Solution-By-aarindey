class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,vector<int>> mp;
        for(vector<int> p:pieces)
        {
            mp[p[0]]=p;
        }
        int i=0;
        while(i<arr.size())
        {
            if(mp.find(arr[i])!=mp.end())
            {
                vector<int> piece=mp[arr[i]];
                for(int j=0;j<piece.size();j++)
                {
                if(arr[i]==piece[j])
                i++;
                else
                return false;
                }
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};