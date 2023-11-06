class SeatManager {
public:
    int total;
    priority_queue<int,vector<int>,greater<int>> minh;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
        {
            minh.push(i);
        }
    }
    
    int reserve() {
        while (!minh.empty())
        {
           int temp=minh.top(); 
           minh.pop();
           return temp;
        }
        return 0;
    }
    
    void unreserve(int seatNumber) {
        if(minh.size()<total)
        {
            int temp=seatNumber;
            minh.push(temp);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */