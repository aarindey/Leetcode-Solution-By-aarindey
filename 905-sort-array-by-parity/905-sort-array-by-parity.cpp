class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> vec;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]%2==0)
                vec.push_back(A[i]);
        }
        for(int j=0;j<A.size();j++)
        {
            if(A[j]%2!=0)
                vec.push_back(A[j]);
        }
        return vec;
    }
};