class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int> > minHeap;
        for(auto row:matrix)
        {
            for(auto ele:row)
            {
                minHeap.push(ele);
            }
        }
        --k;
        while(k--)
        {
            minHeap.pop();
        }
        return minHeap.top();
    }
};