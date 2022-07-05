class Solution {
public:
vector<string> printVertically(string s) {
vector<string> ans;
s+=' ';
vector<string> words;
int left=0;
int maxi=INT_MIN;
for(int i=0;i<s.length();i++)
{
if(s[i]==' ')
{
string str=s.substr(left,i-left);
// while(str[str.length()-1]==' ')
// {
//     str.pop_back();
// }
left=i+1;
words.push_back(str);
if(str.length()>maxi)
maxi=str.length();
}
}
for(int i=0;i<maxi;i++)
{
string res="";
for(int j=0;j<words.size();j++)
{
if(j<words[i].size())
{
res+=words[i][j];
}
else
{
res+=' ';
}
}
ans.push_back(res);
}
return ans;
}
};