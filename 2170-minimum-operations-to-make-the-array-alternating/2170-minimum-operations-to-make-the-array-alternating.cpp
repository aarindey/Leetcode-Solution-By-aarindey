class Solution {
public:
    int minimumOperations(vector<int>& nums) {
     unordered_map<int,int> mp1,mp2;
        int c1=0,c2=0,c3=0,c4=0;;
        int n=nums.size();
        int num1,num2;
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                mp1[nums[i]]++;
                if(mp1[nums[i]]>c1)
                {
                    c1=mp1[nums[i]];
                    num1=nums[i];
                }else if(nums[i]!=num1)
                {
                    c3=max(c3,mp1[nums[i]]);
                }
            }else{
                mp2[nums[i]]++;
                if(mp2[nums[i]]>c2)
                {
                    c2=mp2[nums[i]];
                    num2=nums[i];
                }else if(nums[i]!=num2)
                {
                    c4=max(c4,mp2[nums[i]]);
                }
            }
        }
        if(num1!=num2)
        return n-c1-c2;
        
        
        return min(n-c1-c4,n-c3-c2);
    }
};