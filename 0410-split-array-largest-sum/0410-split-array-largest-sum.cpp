class Solution {
public:
    
    bool f(int lmao,int k,vector<int> &nums)
    {
        int sum=0;
        int cnt=0;
        for(auto &it : nums)
        {
            if(it>lmao)return 0;
            sum+=it;
            if(sum>lmao){
                sum=it;
                cnt++;
            }
        }
        cnt+=1;
        return sum<=lmao && cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=0;
        for(auto &it : nums)
            high+=it;
        
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(f(mid,k,nums))
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};