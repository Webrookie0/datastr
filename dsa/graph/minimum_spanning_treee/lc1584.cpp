class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            priority_queue<pair<int, int>, vector< pair<int , int>>, greater<pair<int , int>>>pq;
            vector<bool>vis(points.size(), false);
    
            vector<vector<pair<int, int>>>adj(points.size());
            for(int i=0; i<points.size(); i++){
                for(int j=i+1; j<points.size(); j++){
                    int x = abs(points[i][0]- points[j][0]);
                    int y = abs(points[i][1]-points[j][1]);
                    adj[i].push_back({x+y, j});
                    adj[j].push_back({x+y , i});  
                }
            }
            int res=0;
            int visnodes=0;
    
            pq.push({0, 0});
            while(!pq.empty()){
                auto x = pq.top();
                pq.pop();
                int wt = x.first;
                int u = x.second;
                if(vis[u])
                continue;
    
                res+=wt;
                vis[u]= true;
                visnodes++;
                for(auto &it: adj[u]){
                    int newwt= it.first;
                    int newnode= it.second;
                    if(!vis[newnode]){
    
                        pq.push({newwt,newnode});
                        cout<<res;
                    }
                }
            }
            cout<<visnodes;
            return res;
    
        }
    };