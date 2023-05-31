// #include<bits/stdc++.h>
// using namespace std;

// NM...POD
// Design Prob

class UndergroundSystem
{
public:
    // id-> {stationName, currentTime} for the checkIn
    map<int, pair<string, int>> checkInStn;

    // Route -> {totalTimeTaken, count}
    map<string, pair<int, int>> checkOutStn;
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkInStn[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto it = checkInStn[id];
        checkInStn.erase(id);

        string route = it.first + "_" + stationName;

        checkOutStn[route].first += t - it.second;
        checkOutStn[route].second += 1;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string route = startStation + "_" + endStation;
        auto time = checkOutStn[route];

        return (double)time.first / time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

// int main(){
//     return 0;
// }