class UndergroundSystem {
    unordered_map<int, pair<string, int>> currCustomer;
    unordered_map<string, unordered_map<string, pair<int, int>>> trips;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        currCustomer[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int duration = t - currCustomer[id].second;
        trips[currCustomer[id].first][stationName].first += duration;
        trips[currCustomer[id].first][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double averageTime = (double)trips[startStation][endStation].first / trips[startStation][endStation].second ;
        return averageTime;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */