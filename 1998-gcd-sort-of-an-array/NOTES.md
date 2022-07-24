vector<int> v=nums;
sort(v.begin(),v.end());
for(int i=0;i<n;i++)
{
if(v[i]!=nums[i])
{
if(findPar(parent,nums[i])!=findPar(parent,v[i]))
{
return false;
}
}
}
return true;
}
};
// 7 5 4
// 7 21 3
// 7 21
// gcd(7,21)>1
// union(7,21)
// gcd(21,3)>1
// union(21,3)
// 7 21 3
// 21 7 3
// 7 3 21
// 3 7 21
// 21 3 7
// 3 21 7