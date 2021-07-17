class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1=abs(ax1-ax2)*abs(ay1-ay2);
        int area2=abs(bx1-bx2)*abs(by1-by2);
        int length,breadth,areaOverlap=0;
        if(!overlap(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2))
        {
            return (area1+area2);
        }
        else
        {
            //finding the length
         if(bx1<=ax2&&bx1>=ax1)
         {
          if(bx2>=ax2&&bx2>=ax1)
          {
                  length=abs(ax2-bx1);    
          } 
             else if(bx2<=ax2&&bx2<=ax1)
             {
                 length=abs(bx1-ax1);
             }  
             else if((bx2<=ax2&&bx2>=bx1)||(bx2<=bx1&&bx2>=ax1))
             {
                 length=abs(bx2-bx1);
             }  
         }
         else if(bx2<=ax2&&bx2>=ax1)
         {
          if(bx1>=ax2&&bx1>=ax1)
          {
                  length=abs(ax2-bx2);    
          } 
             else if(bx1<=ax2&&bx1<=ax1)
             {
                 length=abs(bx2-ax1);
             }  
             else if((bx1<=ax2&&bx1>=bx2)||(bx1<=bx2&&bx1>=ax1))
             {
                 length=abs(bx2-bx1);
             }  
         }
            else
            {
                length=abs(ax1-ax2);
            }
            //finding the breadth
                     if(by1<=ay2&&by1>=ay1)
         {
          if(by2>=ay2&&by2>=ay1)
          {
                  breadth=abs(ay2-by1);    
          } 
             else if(by2<=ay2&&by2<=ay1)
             {
                 breadth=abs(by1-ay1);
             }  
             else if((by2<=ay2&&by2>=by1)||(by2<=by1&&by2>=ay1))
             {
                 breadth=abs(by2-by1);
             }  
         }
         else if(by2<=ay2&&by2>=ay1)
         {
          if(by1>=ay2&&by1>=ay1)
          {
                  breadth=abs(ay2-by2);    
          } 
             else if(by1<=ay2&&by1<=ay1)
             {
                 breadth=abs(by2-ay1);
             }  
             else if((by1<=ax2&&by1>=by2)||(by1<=by2&&by1>=ay1))
             {
                 breadth=abs(by2-by1);
             }  
         }
            else
            {
                breadth=abs(ay1-ay2);
            }
        }
        areaOverlap=length*breadth;
        return area1+area2-areaOverlap;
    }
        bool overlap(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
      if((ax1<=bx1&&ax1<=bx2&&ax2<=bx1&&ax2<=bx2)||(ax1>=bx1&&ax1>=bx2&&ax2>=bx1&&ax2>=bx2))
      {
         return false; 
    }
    else if((ay1<=by1&&ay1<=by2&&ay2<=by1&&ay2<=by2)||(ay1>=by1&&ay1>=by2&&ay2>=by1&&ay2>=by2))
    {
        return false;
    }
    else
    return true;  
    }
};