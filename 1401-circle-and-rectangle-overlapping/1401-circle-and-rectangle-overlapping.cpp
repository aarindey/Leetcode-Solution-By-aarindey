class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        x1-=xCenter;
        x2-=xCenter;
        y1-=yCenter;
        y2-=yCenter;
        int minX,minY;
        if(x1*x2>0)
            minX=min(x1*x1,x2*x2);
        else
            minX=0;
        if(y1*y2>0)
            minY=min(y1*y1,y2*y2);
        else
            minY=0;
        return minX+minY<=radius*radius;
    }
};