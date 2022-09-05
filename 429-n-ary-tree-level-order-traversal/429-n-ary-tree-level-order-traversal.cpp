/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        queue<Node*> q; 
        if(root==NULL)
            return v;
        vector<int> temp;
        q.push(root);
        q.push(NULL);
while(!q.empty())
{   
    Node* f=q.front();
    q.pop();
    if(f==NULL)
    {
    v.push_back(temp);
    temp.clear();
        if(!q.empty())
        {
            q.push(NULL);
        }  
        else
         return v;   
    }
    else
    {
            
            temp.push_back(f->val);
     
            for(int i=0;i<f->children.size();i++)
            {
                q.push(f->children[i]);
                
            }    
    }    
    }
        return v;
    }
};