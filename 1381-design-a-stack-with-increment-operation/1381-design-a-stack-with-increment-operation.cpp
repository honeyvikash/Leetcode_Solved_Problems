class CustomStack {
public:
    int count = 0;
    vector<int>vect;
    int maxsize = 0;
    CustomStack(int maxSize) {
        maxsize = maxSize;
    }
    
    void push(int x) {
        if(count<maxsize)
        {
            vect.push_back(x);
            count++;
        }
    }
    
    int pop() {
        if(count>0)
        {
            int x = vect[count-1];
            count--;
            vect.pop_back();
            return x;
        }
        else
        {
            return -1;
        }
    }
    
    void increment(int k, int val) {
        int num=k;
        if(count < k)num=count;
        for(int i=0;i<num;i++)
        {
            vect[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */