class Solution {
public:
    bool detectCapitalUse(string word) {
      int count1=0,count2=0;
        for(char c:word)
        {
            if(c>=97&&c<=122)
              count1++;
            else if(c<=90&&c>=65)
                count2++;
        }
        if(word[0]<=90&&word[0]>=65)
          return (count2==1)||(count2==word.size());
        return (count1==word.size())||(count2==word.size());
    }
};