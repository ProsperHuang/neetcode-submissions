class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        //binary search through the possible speeds
        int low = 1;
        int high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }
        int mid = low + ((high-low)/2);

        int min_k = high;

        while (low <= high){
            //if it takes too long, increase speed
            if (totalHours(piles, mid) > h){
                low = mid + 1;  
            }
            //if it's fast enough, decrease speed
            else if (totalHours(piles, mid) <= h){
                high = mid - 1;
                if (mid < min_k){
                    min_k = mid;
                }
            }
            mid = low + ((high-low)/2);
        }
        
        return min_k;
    }

    long totalHours(vector<int>& piles, int speed){
        long hours = 0;
        for (int i = 0; i<piles.size(); i++){
            if(piles[i]%speed != 0){
                hours += piles[i]/speed + 1;
            }
            else{
                hours += piles[i]/speed;
            }
        }
        return hours;
    }
};