class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        //sort the cars in order of position first
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.rbegin(), cars.rend());

        //put all the finishing times based on starting position
        double time_to_end;
        vector <double> time;
        for (int i = 0; i < cars.size(); i++){
            time_to_end = (double) (target-cars[i].first) / cars[i].second;
            time.push_back(time_to_end);
        }

        //if it can reach the end at or before the FLEET in front, it's part of the fleet
        double fleet_time = time[0];
        int fleets = 1;
        for (int i = 1; i<cars.size(); i++){
            //if new fleet is created, all cars in new fleet just need to reach this fleet leader
            if (time[i] > fleet_time){
                fleets++;
                fleet_time = time[i];
            }

        }
        return fleets;
        
    }
};
