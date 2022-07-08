class node{
public:
bool isTerminal;
node* child[26];
node()
{
isTerminal=false;
for(int i=0;i<26;i++)
child[i]=NULL;
}
};
void add(string word,node* root)
{
int n=word.size();
for(int i=0;i<n;i++)
{
if(root->child[word[i]-'A']==NULL)
root->child[word[i]-'A']=new node();
root=root->child[word[i]-'A'];
}
root->isTerminal=true;
}
​
class Solution {
public:
bool wordBreak(string s, vector<string>& wordDict) {
node *root=new node();
for(int i=0;i<wordDict.size();i++)
add(wordDict[i],root);
return root->isTerminal;
}
};