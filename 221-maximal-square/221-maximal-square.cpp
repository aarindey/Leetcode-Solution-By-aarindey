#define ll long long int
class Solution {
public:
    ll maximumHistogram(vector<ll>& heights)
      {
        ll maxi=INT_MIN,n=heights.size();
        vector<ll> ps(n,-1),ns(n,n);
        stack<ll> s;
        for(ll i=0;i<n;i++)
        {
          while(!s.empty()&&heights[s.top()]>=heights[i])
          s.pop();
          if(s.empty())
          ps[i]=-1;
          else
          ps[i]=s.top();
          s.push(i);
        }
        stack<ll> s2;
        for(ll i=n-1;i>=0;i--)
        {
         while(!s2.empty()&&heights[s2.top()]>=heights[i])
         s2.pop();
         if(s2.empty())
         ns[i]=n;
         else
         ns[i]=s2.top();
         s2.push(i);
        }
       for(ll i=0;i<n;i++)
       {
           ll z=min(ns[i]-ps[i]-1,heights[i]);
           maxi=max(maxi,z*z);
       }
        return maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty())
    return 0;

    ll n=matrix.size();
    ll m=matrix[0].size();
    vector<ll> currRow(m,0);
    for(ll i=0;i<m;i++)
    {
        currRow[i]+=(matrix[0][i]-'0');
    }
    int maxi=maximumHistogram(currRow);
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(matrix[i][j]=='1')
            currRow[j]+=1;
            else
            currRow[j]=0;
        }
        int maxArea=maximumHistogram(currRow);
        maxi=max(maxi,maxArea);
    }
    return maxi;
    }
};