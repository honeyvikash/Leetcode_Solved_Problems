class UndergroundSystem {
public:
    map<int,pair<string,int>> in;
    map<pair<string,string>,pair<int,int>> out;
    UndergroundSystem() {
        in.clear();
        out.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        out[{in[id].first,stationName}].first+=t-in[id].second;
       out[{in[id].first,stationName}].second++; 
    }
    
    double getAverageTime(string startStation, string endStation) {
        // cout<<out[{startStation,endStation}].first/
        // out[{startStation,endStation}].second<<" ";
        return (double)out[{startStation,endStation}].first/out[{startStation,endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */