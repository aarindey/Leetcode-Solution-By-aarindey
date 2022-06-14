class Solution {
public:
    string getPermutation(int n, int k) {
    string ans="";
        vector<int> num;
        int fact=1;
        for(int i=1;i<=n;i++)
        {
            num.push_back(i);
            fact=fact*i;
        }
        fact=fact/n;
        k--;
        while(true)
        {
            int ff=num[k/fact];
            ans+=to_string(ff);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
            {
                break;
            }
            k=k%fact;
            fact=fact/num.size();
        }
        return ans;
    }
};