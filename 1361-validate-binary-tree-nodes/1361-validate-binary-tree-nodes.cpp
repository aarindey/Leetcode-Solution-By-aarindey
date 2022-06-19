class Solution {
public:
    int countNodes(int root,vector<int> &left,vector<int> &right)
    {
        if(root==-1)
        {
            return 0;
        }
        return 1+countNodes(left[root],left,right)+countNodes(right[root],left,right);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                indegree[leftChild[i]]++;
                if(indegree[leftChild[i]]>1)
                return false;
            }
            if(rightChild[i]!=-1)
            {
                indegree[rightChild[i]]++;
                if(indegree[rightChild[i]]>1)
                return false;
            }
        }
        int root=-1;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                if(root=-1)
                root=i;
                else
                return false;
            }
        }
        if(root==-1)
        return false;
        
        int c=countNodes(root,leftChild,rightChild);
        return c==n;
    }
};