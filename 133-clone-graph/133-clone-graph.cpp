/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        Node* root=new Node(node->val,{});
        mp[node]=root;
        while(!q.empty())
        {
            Node* ele=q.front();
            q.pop();
            vector<Node*> v=ele->neighbors;
            for(Node* &x:v)
            {
                if(mp.find(x)==mp.end())
                {
                    Node* temp=new Node(x->val,{});
                    mp[x]=temp;
                    q.push(x);
                }
                mp[ele]->neighbors.push_back(mp[x]);
            }
        }
        return mp[node];
    }
};