class Solution {
public:
    int minOperations(int n) {
     int arr[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
        arr[i]=(2 * i) + 1;
        sum+=arr[i];    
        }
        int target=sum/n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(target-arr[i]>0)
            ans+=target-arr[i]; 
            else
            break;    
        }   
       return ans; 
    }
};