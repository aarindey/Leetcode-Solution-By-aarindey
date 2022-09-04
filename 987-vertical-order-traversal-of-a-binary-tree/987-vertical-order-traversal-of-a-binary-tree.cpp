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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> mp;
        queue<pair<pair<int,int>, TreeNode *>> q;
        q.push(make_pair(make_pair(0,0), root));
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i<size; i++)
            {
                TreeNode * front = q.front().second;
                int level = q.front().first.second;
                int dis = q.front().first.first;
                mp[dis][level].push_back(front->val);
                q.pop();
                
                if(front->left)
                q.push(make_pair(make_pair(dis-1,level+1), front->left));
                if(front->right)
                q.push(make_pair(make_pair(dis+1,level+1), front->right));
            }
        }
        for(auto&pr:mp)
        {
            vector<int> temp;
            for(auto &j:pr.second)
            {
                vector<int> z=j.second;
                
                sort(z.begin(), z.end());
                for(auto k : z)
                    temp.push_back(k);
            }
            ans.push_back(temp);            
        }
        return ans;
    }
};