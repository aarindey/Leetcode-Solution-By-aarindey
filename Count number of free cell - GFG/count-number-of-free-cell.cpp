//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){

      

      

    

     int cnt=n*n;

 

      vector<int>mp(n+1,0);

      vector<int>mp2(n+1,0);

      int mpc=0;

      int mp2c=0;

     vector<long long int>ans;

      for(int i=0;i<k;i++)

      {

          int row=arr[i][0];

          int col=arr[i][1];

          if(mp[row]==0)

          {

              cnt-=n;

              if(mp[row]==0)

              {

                   mpc++; 

              }

              mp[row]++;

              

            

              cnt+=mp2c;

         

          }

          if(mp2[col]==0)

          {

              cnt-=n;

              if(mp2[col]==0)

              {

                  mp2c++;

              }

               mp2[col]++;

              cnt+=mpc;

           

          }

          ans.push_back(cnt);

        

      }

      return ans;

 

      

  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends