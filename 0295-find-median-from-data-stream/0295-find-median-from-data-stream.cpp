class MedianFinder {
public:
priority_queue<int>MaxHeap;
priority_queue<int,vector<int>,greater<int>>MinHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) 
    {
       MaxHeap.push(num);
       MinHeap.push(MaxHeap.top());
       MaxHeap.pop();
       if(MinHeap.size()>MaxHeap.size())
       {
           MaxHeap.push(MinHeap.top());
           MinHeap.pop();
       } 
    }
    
    double findMedian() 
    {
        if(MaxHeap.size()>MinHeap.size())
        {
            return MaxHeap.top();
        }
        else
        {
            return (MaxHeap.top()+MinHeap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */