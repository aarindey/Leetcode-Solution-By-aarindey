/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        int n=d.size();
        map<int,TreeNode*> mp;
        set<int> st;
        for(int i=0;i<n;i++)
        {
            TreeNode* temp;
            if(mp.find(d[i][0])!=mp.end())
            {
                temp=mp[d[i][0]];
            }
            else
            {
                temp=new TreeNode(d[i][0]);
                mp[d[i][0]]=temp;
            }
            bool isleft=d[i][2];
            if(isleft)
            {
                TreeNode* t2;
                if(mp.find(d[i][1])!=mp.end())
                {
                    t2=mp[d[i][1]];
                }
                else
                {
                    t2=new TreeNode(d[i][1]);
                    mp[d[i][1]]=t2;
                    // st.insert(d[i][1]);
                }
                st.insert(d[i][1]);
                temp->left=t2;
            }
            else
            {
                TreeNode* t2;
                if(mp.find(d[i][1])!=mp.end())
                {
                    t2=mp[d[i][1]];
                }
                else
                {
                    t2=new TreeNode(d[i][1]);
                    mp[d[i][1]]=t2;
                }
                st.insert(d[i][1]);
                temp->right=t2;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(st.find(d[i][0])==st.end())
            return mp[d[i][0]];
        }
        return NULL;
    }
};