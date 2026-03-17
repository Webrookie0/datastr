class Solution {
    public:
        // this solve fn is the largest rectangle in histogram also 
        int solve(vector<int>& heights) {
            int n = heights.size();
            vector<int>prevs;
            vector<int>nexts;
            // prevs[0]= 0;
            stack<pair<int, int>>st;
            for(int i=0; i<n; i++){
    
                while(!st.empty() && st.top().first>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    prevs.push_back(-1);
                }else{
                    prevs.push_back(st.top().second);
                }
                st.push({heights[i], i});
            }
            while(!st.empty()) st.pop();
            for(int i=n-1; i>=0; i--){
    
                while(!st.empty() && st.top().first>=heights[i]){
                    st.pop();
                }
                if(st.empty()){
                    nexts.push_back(n);
                }else{
                    nexts.push_back(st.top().second);
                }
                st.push({heights[i], i});
            }
            reverse(nexts.begin(), nexts.end());
            // i used prev smaller and next smaller 
            long long ans=INT_MIN;
            for(int i=0; i<n; i++){
                int heightmax = heights[i];
                int lenmax= nexts[i]-prevs[i]-1;
                long long temp = heightmax*lenmax;
                ans= max(ans, temp);
    
    
            }
            return ans;
        }
        int maximalRectangle(vector<vector<char>>& matrix) {
            vector<int>ans(matrix[0].size());
            for(int i=0; i<matrix[0].size(); i++){
                char temp = matrix[0][i];
                ans[i]= temp-'0';
            }
            int res= solve(ans);
            for(int i=1; i<matrix.size(); i++){
                for(int j=0; j<matrix[0].size(); j++){
                    int r= matrix[i][j];
                    if(r=='1'){
                        ans[j]++;
                    }else{
                        ans[j]=0;
                    }
                }
                // int temp =0;
                int x =solve(ans);
                res = max(res, x);
    
            }
            return res;
        }
    };