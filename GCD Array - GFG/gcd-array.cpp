//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    void factor(vector<int>& arr, int n)
  {
      for(int i = 1;i*i<=n;i++)
      {
          if(n%i == 0)
          {
              arr.push_back(i);
              if((n/i) != i)
                arr.push_back(n/i);
          }
      }
      return;
  }
  
    int solve(int n, int k, vector<int> &arr) {
        int tot = 0;
        for(int i = 0;i<n;i++)  tot = tot + arr[i];
        vector<int> nums;
        factor(nums, tot);
        int ans = 1;
        for(int i = 0;i<nums.size();i++)
        {
            int temp = nums[i], sum = 0;
            tot = 0;
            for(int j = 0;j<n;j++)
            {
                sum = sum + arr[j];
                if(sum%temp == 0)    tot++;
            }
                
            if(tot >= k)    ans = max(ans, temp);
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends