class Solution {
    public:
        vector<int> getBiggestThree(vector<vector<int>>& grid) {
            // it is pretty important to go in a cyclic manner to avoid repeated addition of some elements
            // rhombus must have a square shaped 
            vector<int>prefdiag;
            set<int, std::greater<int>> st;
            for(int i =0; i<grid.size(); i++){
                for(int j=0; j<grid[0].size(); j++){
                    st.insert(grid[i][j]);
                    int k=1;
                    while(i+2*k<grid.size() && j+k<grid[0].size() && j-k>=0){
                        int sum =0;
                        int x=i; 
                        int y=j;
                        // going from top to right
                        for(int t=0; t<k ; t++){
                            sum+=grid[x+t][y+t];
                        }
                        // going from right to bottom
                        for(int t=0; t<k ; t++){
                            sum+=grid[x+k+t][y-t+k];
                        }
                        // going form bottom to left 
                        for(int t=0; t<k ; t++){
                            sum+=grid[x+2*k-t][y-t];
                        }
                        // going from left to top 
                        for(int t=0; t<k ; t++){
                            sum+=grid[x+k-t][y+t-k];
                        }
                        
                        st.insert(sum);
                        k++;
                    }
                }
            }
            vector<int>ans;
            int times =3;
            for(auto it: st){
                if(times>0){
                    ans.push_back(it);
                    times--;
                }
            }
            return ans;
            
        }
    };