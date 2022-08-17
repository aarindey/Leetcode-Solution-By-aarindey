class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> ref={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> v;
        int count=1;
        for(int i=0;i<words.size();i++)
        {string s="";
            for(char c: words[i])
            {
                int n=c-97;
                s+=ref[n];
            }
         v.push_back(s);
         }
       int n=v.size();
      // Pick all elements one by one
    for (int i = 1; i < n; i++) {
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if (v[i] == v[j])
                break;
        }
        // If not printed earlier, then print it
        if (i == j)
            count++;
    }
        if(v.size()==0)
            return 0;
      return count;
        }   
};