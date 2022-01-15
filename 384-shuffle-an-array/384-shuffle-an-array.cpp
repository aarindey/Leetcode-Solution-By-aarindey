class Solution {
private:
 vector<int> original;
 vector<int> curr;
public:
    Solution(vector<int>& nums) {
        original=nums;
        curr=nums;
    }
    
    vector<int> reset() {
        curr=original;
        return curr;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled;
        set<int> check;
        int n=curr.size();
        while(check.size()!=n)
        {
            int i=rand()%n;
            if(check.find(i)==check.end())
            {
            shuffled.push_back(curr[i]);
            check.insert(i);
            }
        }
        curr=shuffled;
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */