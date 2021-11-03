class Solution {
public:
    bool isLongPressedName(string name, string typed) {
      int i=0,j=0;
      while(j<typed.length())
      {
          if(i!=name.length()&&name[i]==typed[j])
          {
              i++;
              j++;
          }
          else if(name[i]!=typed[j]&&j!=0&&j<typed.length()&&typed[j]==typed[j-1])
          {
              j++;
          }
          else
          break;
      }
    return (i==name.length()&&j==typed.length());
    }
};