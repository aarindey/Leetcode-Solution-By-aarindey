struct Node{
    private:
    Node *links[2];
    public:
    Node()
    {
        links[0]=NULL;
        links[1]=NULL;
    }
    bool containsKey(int idx){
        return (links[idx]!=NULL);
    } 
    Node* get(int idx)
    {
        return links[idx];
    }
    void put(int idx,Node* node)
    {
        links[idx]=node;
    }
};
class Trie{
  private:
    Node* root;
public:
    Trie()
    {
        root=new Node;
    }
public:
    void insert(int num)
    {
        Node* node=root;
        int bit;
        for(int i=31;i>=0;i--)
        {
            bit=(num>>i)&1;
            if(!node->containsKey(bit))
            {
                node->put(bit,new Node);
            }
            node=node->get(bit);
        }
    }
public:
    int findMax(int num)
    {
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
            int bit;
            bit=(num>>i)&1;
            if(node->containsKey(!bit))
            {
                maxNum|=(1<<i);
                node=node->get(!bit);
            }
            else
            {
                node=node->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
       Trie trie;
        for(auto &num:nums) 
        {
           trie.insert(num);
        }
        int maxi=0;
        for(auto &num:nums)
        {
            maxi=max(maxi,trie.findMax(num));
        }
        return maxi;
    }
};