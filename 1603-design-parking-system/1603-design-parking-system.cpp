class ParkingSystem {
public:
    int a, b, c;
    ParkingSystem(int big, int medium, int small) {
        a = big, b = medium, c = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1 && a>0) { a--; return true; }
        if(carType == 2 && b>0) { b--; return true; }
        if(carType == 3 && c>0) { c--; return true; }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */