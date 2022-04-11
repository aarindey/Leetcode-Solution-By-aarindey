class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        int n=arr.size();
        if(sum==0)
        return {0,n-1};
        if(sum%3!=0)
        return {-1,-1};
        int x=sum/3;
     
        int ones=0;
        vector<int> right,left,mid;
        int b=n-1;
        
        for(int i=n-1;i>=0;i--)
        {
            right.push_back(arr[i]);
            if(arr[i]==1)
            {
                ones++;
                
            }
            if(ones==x)
            {
                b=i;
                break;    
            }
        }
        
        reverse(right.begin(),right.end());
        bool ok=true;
        int a=0;
        for(int i=0;i<n;i++)
        {
            if(ok&&arr[i]==0)
            {
                continue;
            }
            ok=false;
            left.push_back(arr[i]);
            if(arr[i]==1)
            {
                ones++;
            }
            if(left.size()==right.size())
            {
                a=i;
                break;    
            }
        }
        
        if(left!=right)
        return {-1,-1};
        
        ok=true;
        for(int i=a+1;i<b;i++)
        {
            if(ok&&arr[i]==0)
            {
                continue;
            }
            ok=false;
            mid.push_back(arr[i]);
            if(arr[i]==1)
            {
                ones++;
            }
            if(mid.size()==right.size())
            {
                b=i;
                break;    
            }
        }
        if(mid!=right)
        return {-1,-1};
        
        return {a,b+1};
    }
};