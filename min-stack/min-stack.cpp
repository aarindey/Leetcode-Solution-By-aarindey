class MinStack {
int *arr;
    int *newarr;
    int size;
    int nextIndex;
    int firstIndex;
    int capacity;
    public:
    /** initialize your data structure here. */
    MinStack() {
        capacity=10000;
       arr=new int[capacity];
        size=0;
        nextIndex=0;
        firstIndex=-1;
    }
    
    void push(int val) {
        if(capacity==size)
        {
         newarr=new int[capacity*2];
            int j=0;
            for(int i=firstIndex;i<capacity;i++)
            {
                newarr[j]=arr[i];
                j++;
                
            }
            for(int i=0;i<firstIndex;i++)
            {
                newarr[j]=arr[i];
                j++;
            }
        }
        
        arr[nextIndex]=val;
        size++;
        nextIndex=(nextIndex+1)%capacity;
    }
    
    void pop() {
        if(size==0)
        return;
        else
        {
        nextIndex=(nextIndex-1);
        size--;
        }
    }
    
    int top() {
        if(size==0)
            return 0;
        
        return arr[nextIndex-1];
        
    }
    
    int getMin() {
       int min=INT_MAX;
        int i;
    for(i=0;i<size;i++){
        if(arr[i]<min)
            min=arr[i];
    }
    return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */