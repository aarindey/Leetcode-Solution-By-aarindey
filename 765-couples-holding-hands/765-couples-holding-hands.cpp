class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int l=row.size();
        map<int,int> mp;
        for(int i=0;i<l;i++)
        {
            mp[row[i]]=i;
        }
        int ans=0;
        unordered_map<int,int> hash;
        for(int i=0;i<60;i+=2)
        {
            hash[i]=i+1;
            hash[i+1]=i;
        }
        for(int i=0;i<l;i+=2)
        {
            int partner=hash[row[i]];
            if(partner==row[i+1])
            continue;
            int i1,i2;
            i1=mp[row[i+1]];
            i2=mp[partner];
            mp[row[i+1]]=i2;
            mp[partner]=i1;
            swap(row[i1],row[i2]);
            ans++;
        }
        return ans;
    }
};
