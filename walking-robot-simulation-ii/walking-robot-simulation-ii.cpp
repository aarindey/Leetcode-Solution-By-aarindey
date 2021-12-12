class Robot {
public:
    int width,height;
    int dir=0;
   int x=0,y=0;
    Robot(int width, int height) {
        this->width=width;
        this->height=height;
    }
    void step(int num)
    {
         int peri=2*(height+width)-4;
         if(num%peri!=0)
         num%=peri;
          if(dir==0)
        {
                
            if(x+num<=width-1)
            {
                x=x+num;
                num=0;
                // if(x==width-1)
                // {
                // dir=(dir+1)%4;
                // }
            }
            else
            {
                num-=(width-1-x);
                x=width-1;
                dir=(dir+1)%4;
                move(num);
            }
        }
        else if(dir==1)
        {
            
            if(y+num<=height-1)
            {
                y=y+num;
                num=0;
                // if(y==height-1)
                // dir=(dir+1)%4;
            }
            else
            {
                num-=(height-1-y);
                y=height-1;
                dir=(dir+1)%4;
                move(num);
            }    

        }
        else if(dir==2)
        {
            
           if(x-num>=0)
            {
                x=x-num;
                num=0;
                // if(x==0)
                // dir=(dir+1)%4;
            }
            else
            {
                num-=x;
                x=0;
                dir=(dir+1)%4;
                move(num);
            }
        }
        else if(dir==3)
        {
            
            if(y-num>=0)
            {
                y=y-num;
                num=0;
                // if(y==0)
                // dir=(dir+1)%4;
            }
            else
            {
                num-=(y);
                y=0;
                dir=(dir+1)%4;
                move(num);
            }
        }
    }
    void move(int num) {
     int peri=2*(height+width)-4;
        if(num%peri!=0)
         num%=peri;
        step(num);
    }
    
    vector<int> getPos() {
        vector<int> pos(2);
        pos[0]=x;
        pos[1]=y;
        return pos;
    }
    
    string getDir() {
        if(dir==0)
        return "East";
        else if(dir==1)
        return "North";
        else if(dir==2)
        return "West";
        else if(dir==3)
        return "South";
        return "";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */