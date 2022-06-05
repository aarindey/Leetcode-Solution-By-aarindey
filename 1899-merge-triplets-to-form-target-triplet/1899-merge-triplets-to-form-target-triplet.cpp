class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        for(int i=0;i<n;i++)
        {
            if(triplets[i][0]>target[0]||triplets[i][1]>target[1]||triplets[i][2]>target[2])
            {
                triplets[i][0]=-1;
                triplets[i][1]=-1;
                triplets[i][2]=-1;
            }
        }
        int a,b,c;
        a=b=c=1;
        for(int i=0;i<n;i++)
        {
            a=max(a,triplets[i][0]);
            b=max(b,triplets[i][1]);
            c=max(c,triplets[i][2]);
        }
        if(a==target[0]&&b==target[1]&&c==target[2])
        {
            return true;
        }
        return false;
    }
};