class ParkingSystem {
public:
    int b=0,m=0,s=0;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) {
        if(carType==1)
        {
            return (b--)>0?1:0;
        }
        else if(carType==2)
        {
            return (m--)>0?1:0;
        }
        else
        {
            return (s--)>0?1:0;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */