class Solution {
public:
    int reverse(int num)
    {
        int num2=0;
        while(num>0)
        {
            int d=num%10;
            num/=10;
            num2=num2*10+d;
        }
        return num2;
    }
    int countNicePairs(vector<int>& nums) {
        long long int mod=1e9+7;
        int n=nums.size();
        long long int ans=0;
        vector<int> rev;
        for(int i=0;i<n;i++)
        rev.push_back(reverse(nums[i]));
        unordered_map<int,int> lookUp;
        for(int i=0;i<n;i++)
        {
            int key=nums[i]-rev[i];
            if(lookUp.find(key)!=lookUp.end())
            {
                ans=(ans+lookUp[key])%mod;
                lookUp[key]++;
            }
            else
            {
                lookUp[key]=1;
            }
        }
        return (int)(ans%mod);
    }
};