class Solution {
public:
    int minTimeToType(string word) {
      int n=word.length();
        int ans=0;
        char p='a';
        for(int i=0;i<n;i++)
        {
            ans+=min((p-word[i]+26)%26,(word[i]-p+26)%26);
            p=word[i];
        }
        ans+=n;
        return ans;
    }
};