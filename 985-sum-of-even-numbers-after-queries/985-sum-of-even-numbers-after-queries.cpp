class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int evenSum=0;
        for(auto &x:A)
        {
            if(!(x&1))
            {
                evenSum+=x;
            }
        }
        int n=queries.size();
        for(int i=0;i<n;i++)
        {
            int val=queries[i][0];
            int idx=queries[i][1];
            if(A[idx]&1)
            {
                if(abs(val)%2==0)
                {
                    A[idx]+=val;
                }
                else
                {
                    evenSum+=A[idx]+val;
                    A[idx]+=val;
                }
            }
            else
            {
                if(abs(val)%2==0)
                {
                    evenSum+=val;
                    A[idx]+=val;
                }
                else
                {
                    evenSum-=A[idx];
                    A[idx]+=val;
                }
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};