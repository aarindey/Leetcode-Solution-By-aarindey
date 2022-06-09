class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vec;
        int left=0,right=numbers.size()-1;
        int sum=0;
        while(left<right)
        {
            sum=numbers[left]+numbers[right];
            if(sum==target)
            {
                vec.push_back(left+1);
                vec.push_back(right+1);
                 break;
            }
            else if(sum<target)
            {
                left++;
            }
            else
            {
                right--;
            }       
        }
        return vec;
    }
};