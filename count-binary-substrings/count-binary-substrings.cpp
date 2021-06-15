class Solution {
public:
    int countBinarySubstrings(string s) {
        int binaryStrings=0;
        int currBlock=1;
        int prevBlock=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==s[i-1])
            {
                currBlock++;
            }
            else
            {
                binaryStrings+=min(currBlock,prevBlock);
                prevBlock=currBlock;
                currBlock=1;
            }
        }
     binaryStrings+=min(currBlock,prevBlock);
        return binaryStrings;
    }
};