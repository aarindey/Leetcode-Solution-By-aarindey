class Solution {
public:
    long long int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
      int n=arr.size();
     
      long long c=0;
      for(int i=0;i<n;i++)
      {
          vector<int> count(101,0);
          
          for(int j=i+1;j<n;j++)
          {
              int k=target-arr[i]-arr[j];
              if(k>=0&&k<=100&&count[k]>0)
              {
                  c+=count[k];
                  c%=mod;
              }
              count[arr[j]]++;
          }
      }
        return (int)c;
    }
};