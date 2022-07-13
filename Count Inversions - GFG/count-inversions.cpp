// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    #define ll long long int
ll n;
ll merge(ll start,ll mid,ll end,ll arr[],ll temp[])
{
    ll inv=0;
    // ll temp[n+1];
    ll k=start;
    ll i,j;
    i=start;
    j=mid+1;
    ll left_size=mid;
    ll right_size=end;
    while(i<=left_size&&j<=right_size)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv+=(mid-i+1);
        }
    }
    while(i<=left_size)
    {
        temp[k++]=arr[i++];
    }
    while(j<=right_size)
    {
        temp[k++]=arr[j++];
    }
    for(ll f=start;f<=end;f++)
    {
        arr[f]=temp[f];
    }

    return inv;
}

ll mergeSort(ll start,ll end,ll arr[],ll temp[])
{
    ll inv=0;
    if(start==end)
    return 0;
    if(start<end)
    {
        ll mid=(end+start)/2;
        inv+=mergeSort(start,mid,arr,temp);
        inv+=mergeSort(mid+1,end,arr,temp);
        inv+=merge(start,mid,end,arr,temp);
    }
    return inv;
}
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        n=N;
        ll temp[N];
        return mergeSort(0,N-1,arr,temp);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends