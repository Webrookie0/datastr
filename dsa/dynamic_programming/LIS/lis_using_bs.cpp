class Solution {
    public:
        
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            auto compare = [](const vector<int>&a, const vector<int>&b){
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            };

            //  it was required to sort the envelopes in this manner as it was asked to find the longest increasing subsequence of the width and height of the envelopes
            // we sorted them by width and the in incr height order we found the longest increasing subsequence of the height
            sort(envelopes.begin(), envelopes.end(), compare);
            vector<int>dp;
            int overallMax = 1;
    
            for(int i=0; i<envelopes.size(); i++){
                int height_curr = envelopes[i][1];
                auto it = lower_bound(dp.begin(), dp.end(),height_curr );
                // this lowerbound helps find the lowest element in the dp array that is greater than or equal to the current height
    
                if(it == dp.end()){
                    dp.push_back(height_curr);
                }else{
                    *it = height_curr;
                }
            }
            return dp.size();
    
    
            
    
        }
    };
