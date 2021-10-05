class Solution {
public:
    int findLHS(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int count=0,maxi=INT_MIN,j=0,n=nums.size(),i=0;
    bool check;
    while(i<n&&j<n)
    {
     check=false;
     while(i<n&&(nums[i]==nums[j]||nums[i]==nums[j]+1))
     {
         i++;
         if(i<n&&nums[i]==nums[j]+1)
         check=true;
     }
     if(check)
     count=max(count,i-j);
     int prev=nums[j];
     while(j<n&&nums[j]==prev)
     j++;
    }
    return count;
    }
};