class Solution 
{
    public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders){
        set<string> s;
        map<int,vector<string>> mp2;
        map<string,map<string,int>> mp;
        int n=orders.size();
        for(int i=0;i<n;i++)
        {
            s.insert(orders[i][2]);
            mp2[stoi(orders[i][1])].push_back(orders[i][2]);
            mp[orders[i][1]][orders[i][2]]++;
        }
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back("Table");
        for(auto it=s.begin();it!=s.end();it++)
        {
            temp.push_back(*it);
        }
        ans.push_back(temp);
        for(auto pr:mp2)
        {
            temp.clear();
            temp.push_back(to_string(pr.first));
            vector<string> v;
            v=pr.second;
            for(auto it=s.begin();it!=s.end();it++)
            {
                if(find(v.begin(),v.end(),*it)!=v.end())
                {
                    temp.push_back(to_string(mp[to_string(pr.first)][*it]));
                }
                else
                {
                    temp.push_back("0");
                }
            }
            ans.push_back(temp);
        }
        return ans;
       }
};