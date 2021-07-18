// //1935. Maximum Number of Words You Can Type
// class Solution {
// public:
//     int canBeTypedWords(string text, string brokenLetters) {
//      unordered_set<char> s;
//         for(int i=0;i<brokenLetters.size();i++)
//         {
//             s.insert(brokenLetters[i]);
//         }
//         int count=0;
//         text+=' ';
//         string str;
//         int left=0;
//         bool check;
//         for(int i=0;i<text.length();i++)
//         {
//             if(text[i]==' ')
//             {
//                 check=true;
//                 str=text.substr(left,i-left);
//                 for(int j=0;j<str.length();j++)
//                 {
//                     if(s.find(str[j])!=s.end())
//                     {
//                         check=false;
//                         left=i+1;
//                         break;
//                     }
//                     else
//                     {
//                         left=i+1;
//                     }
//                 }
//                 if(check)
//                 count++;
//             }
//         }
//         return count;
//     }
// };
class Solution {
public:
    int c=0,k=1;
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool>map;
        for(auto i:brokenLetters)
            map[i]=true;
        
        for(int i=0;i<text.length();i++)
            if(text[i]==' ')
                k++;
        
        stringstream iss(text);
        string word;
        
        while(iss >> word) {
            for(int i=0;i<word.size();i++){
               if(map[word[i]]==true){
                    k--;
                     break;   
               }
            } 
        }
        return k;
    }
};