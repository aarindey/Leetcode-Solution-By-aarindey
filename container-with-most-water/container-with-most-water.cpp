class Solution {
public:
    int maxArea(vector<int>& height) {
        int length;
        int maxArea=0;
        int i=0,j=height.size()-1;
while(i<j)
{
    length=min(height[i],height[j]);
    maxArea=max(maxArea,(length*(j-i)));
    while(length>=height[i]&&i<j)
        i++;
    while(length>=height[j]&&i<j)
        j--;
}
        return maxArea;
    }
};