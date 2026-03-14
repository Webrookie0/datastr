class Solution {
    public:
        
    
        bool canEatInTime(vector<int>& piles, int k, int h) {
            int hours = 0;
            for (int pile : piles) {
                int div = pile / k;
                hours += div;
                if (pile % k != 0)
                    hours++;
            }
            return hours <= h;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
    
            int low = 1;
            int high = INT_MAX ;
            int mid;
            // The diffrence between <= and < is when using <=, the binary search range is [𝐿,𝑅], and when using <, the range is [𝐿,𝑅).
            // here the ans can be anywhere between 1 and INT_MAX so we use this <=
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (canEatInTime(piles, mid, h))
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low;
        }
    };