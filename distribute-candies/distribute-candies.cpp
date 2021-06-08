class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n=candyType.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[candyType[i]]++;
        }
        int types=mp.size();
        if(types<=(n/2))
         return types;
        else
          return (n/2);  
    }
};