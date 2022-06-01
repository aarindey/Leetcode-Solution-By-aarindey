class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> temp;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            temp.push_back(sum);
        }
        return temp;
    }
    int main()
    {
        int n;
        vector<int> vec;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int t;
            cin>>t;
            vec.push_back(t);
        }
        runningSum(vec);
        return 0;
    }
};