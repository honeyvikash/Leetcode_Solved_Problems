class MyCircularDeque {
public:
    int n = 1000;
    vector<int> circularDeque;
    int size;
    int front;
    int rear;
    int count;  
    
    MyCircularDeque(int k) : circularDeque(k, -1) {
        size = k;
        front = 0;
        rear = k - 1;
        count = 0;  
    }
    
    bool insertFront(int value) {
        if (count == size) return false;  
        front = (front - 1 + size) % size;  
        circularDeque[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if (count == size) return false;  
        rear = (rear + 1) % size;  
        circularDeque[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if (count == 0) return false;  
        circularDeque[front] = -1;
        front = (front + 1) % size;  
        count--;
        return true;
    }
    
    bool deleteLast() {
        if (count == 0) return false;  
        circularDeque[rear] = -1;
        rear = (rear - 1 + size) % size;  
        count--;
        return true;
    }
    
    int getFront() {
        if (count == 0) return -1;  
        return circularDeque[front];
    }
    
    int getRear() {
        if (count == 0) return -1;  
        return circularDeque[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */