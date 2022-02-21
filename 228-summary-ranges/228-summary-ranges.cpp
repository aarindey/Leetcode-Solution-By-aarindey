class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> ans;
        if(n==1)
        {
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        int i=0;
        bool enter;
        string temp;
        while(i<n)
        {
            enter=false;
            temp=to_string(nums[i]);
            while(i+1<n&&!(nums[i+1]>0&&nums[i]<0)&&nums[i+1]-nums[i]==1)
            {
              i++;
              enter=true;
            }
            if(enter)
            {
                temp+="->";
                temp+=to_string(nums[i]);
                ans.push_back(temp);
            }
            else
            {
                ans.push_back(temp);
            }
            i++;
        }
        return ans;
    }
};