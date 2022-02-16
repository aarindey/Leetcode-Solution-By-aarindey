class Solution {
public:
    int longestWPI(vector<int>& hours) {
      int n=hours.size(),ans=0,currSum=0;
        unordered_map<int,int> mp;
       for(int i=0;i<n;i++)
       {
           if(hours[i]>8)
           {
               currSum++;
           }
           else
           {
               currSum--;
           }  
           if(currSum>0)
           {
               ans=max(ans,i+1);
           }
           else
           {
               if(mp.find(currSum-1)!=mp.end())
               {
                   ans=max(ans,i-mp[currSum-1]);
               }
           }
           if(mp.find(currSum)==mp.end())
           {
               mp[currSum]=i;
           }
       }
        return ans;
    }
};