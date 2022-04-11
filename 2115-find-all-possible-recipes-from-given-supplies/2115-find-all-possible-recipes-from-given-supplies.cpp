class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
      map<string,vector<string> > mp;
        int n=recipes.size();
        for(int i=0;i<n;i++)
        {
            mp[recipes[i]]=ingredients[i];
        }
        unordered_set<string> avail(supplies.begin(),supplies.end());
        vector<string> ans;
        while(recipes.size()!=0)
        {
            int c=0;
            for(int i=0;i<recipes.size();i++)
            {
                bool ok=true;
                for(auto &s:mp[recipes[i]])
                {
                    if(avail.find(s)==avail.end())
                    {
                        ok=false;
                        break;
                    }
                }
                if(ok)
                {
                    ans.push_back(recipes[i]);
                    avail.insert(recipes[i]);
                    recipes.erase(recipes.begin()+i);
                    c++;
                }
            }
            if(c==0)
            break;
        }
        return ans;
    }
};