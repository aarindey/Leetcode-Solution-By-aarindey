```
class Solution {
public:
int findBestValue(vector<int>& arr, int target) {
int n=arr.size();
sort(arr.begin(),arr.end());
int ans,diff=INT_MAX;
for(int i=0;i<n;i++)
{
int low;
if(i<=1)
low=0;
else
low=arr[i-1]+1;
int high=arr[i];
int mul=n-i;
while(low<=high)
{
int mid=(low+high)/2;
int x=mid*mul;
if(diff>abs(target-x))
{
diff=abs(target-x);
ans=mid;
}
if(target>x)
{
low=mid+1;
}
else
{
high=mid-1;
}
}
target-=arr[i];
}
return ans;
}
};
```