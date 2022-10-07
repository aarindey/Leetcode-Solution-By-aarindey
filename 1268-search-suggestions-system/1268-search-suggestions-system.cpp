class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        vector<string> temp;
        sort(products.begin(),products.end());
        string word="";
        int n=products.size();
        for(char &ch:searchWord)
        {
            word+=ch;
            temp.clear();
            int idx=lower_bound(products.begin(),products.end(),word)-products.begin();
            for(int i=idx;i<n;i++)
            {
                if(products[i].substr(0,word.size())==word&&temp.size()<3)
                {
                    temp.push_back(products[i]);
                }
                else 
                {
                    break;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};