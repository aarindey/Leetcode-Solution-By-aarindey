}
while(j<=end)
{
temp[k++]=nums[j++];
}
for(int i=start;i<=end;i++)
{
nums[i]=temp[i];
}
return pairs;
}
int mergeSort(int start,int end,vector<int> &nums)
{
if(start>=end)
return 0;
int pairs=0;
int mid=start+(end-start)/2;
pairs+=mergeSort(start,mid,nums);
pairs+=mergeSort(mid+1,end,nums);
pairs+=merge(start,mid,end,nums);
return pairs;
}
int reversePairs(vector<int>& nums) {
n=nums.size();
return mergeSort(0,n-1,nums);
}
};