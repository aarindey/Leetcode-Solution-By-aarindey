class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(),products.end());
        int n=searchWord.size(),m=products.size();
        int left=0;
        int right=m-1;
        for(int i=0;i<n;i++)
        {
            char ch=searchWord[i];
            while(left<=right&&i<=products[left].size()&&products[left][i]!=ch)
            left++;
            while(left<=right&&i<=products[right].size()&&products[right][i]!=ch)
            right--;
            vector<string> temp;
            int len=right-left+1;
            for(int k=left;k<min(left+3,left+len);k++)
            {
                temp.push_back(products[k]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};