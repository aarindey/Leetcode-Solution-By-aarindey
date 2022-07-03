#define ll long long int
class node{
    public:
    node* left;
    node* right;
    int nodesCount;
    node()
    {
        left=NULL;
        right=NULL;
        nodesCount=0;
    }
};
class Solution {
public:
    int countNodes(node *root)
    {
        if(root==NULL)
        return 0;
        int l=countNodes(root->left);
        int r=countNodes(root->right);
        root->nodesCount=l+r+1;
        return l+r+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<node*> v(n);
        for(int i=0;i<n;i++)
        {
            v[i]=new node();
        }
        //v[0] is the root
        int len=parents.size();
        for(int i=1;i<len;i++)
        {
            int parentID=parents[i];
            if(v[parentID]->left==NULL)
            {
                v[parentID]->left=v[i];
            }
            else
            {
                v[parentID]->right=v[i];
            }
        }
        countNodes(v[0]);
        ll maxi=INT_MIN;
        vector<ll> temp;
        for(int i=0;i<n;i++)
        {
            int leftNodes=(v[i]->left==NULL)?0:v[i]->left->nodesCount;
            int rightNodes=(v[i]->right==NULL)?0:v[i]->right->nodesCount;
            int parentNodes=v[0]->nodesCount-leftNodes-rightNodes-1;
            ll mul=1;
            if(leftNodes>0)
            {
                mul*=leftNodes;
            }
            if(rightNodes>0)
            {
                mul*=rightNodes;
            }
            if(parentNodes>0)
            {
                mul*=parentNodes;
            }
            temp.push_back(mul);
            maxi=max(maxi,mul);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(maxi==temp[i])
            {
                ans++;
            }
        }
        return ans;
    }
};