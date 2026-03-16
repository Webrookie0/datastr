// pure prims type hai 
// pehle min spanning tree bana lo 
// uske baad usme check karo ki jo node ki priority 1 nhi hai to usko double kardo 
// aise k node ko double karo aur ans nikal lo 
class Solution {
    public:
        int maxStability(int n, vector<vector<int>>& edges, int k) {
            
            priority_queue<pair<int , vector<int>>>pq;
            vector<bool>vis(edges.size(), false);
            // an integer n , representing n nodes , nodes from 0 to n-1, 
            
            vector<vector<tuple<int, int, int>>>adj(n);
            for(int i=0; i<edges.size(); i++){
                adj[edges[i][0]].push_back({edges[i][1], edges[i][2], edges[i][3]});
                adj[edges[i][1]].push_back({edges[i][0], edges[i][2], edges[i][3]});
    
            }
            vector<vector<int>>mst;
            pq.push({1, {0, 1, -1}});
            while(!pq.empty()){
                auto x = pq.top();
                pq.pop();
                int wt = x.second[0];
                int u = x.second[1];
                int p =x.first;
                int parent= x.second[2];
                if(vis[u]){
                    if(p==1)return -1;
                    continue;
                }
                if(parent!=-1) mst.push_back({parent , u, wt , p});
                vis[u]=true;
    
                
                for(auto &it: adj[u]){
                    int newnode= get<0>(it);
                    int weight= get<1>(it);
                    int canhave = get<2>(it);
                    if(!vis[newnode]){
    
                        pq.push({canhave, {weight, newnode, u}});
                        
                    }
                }
            }
            if(mst.size()!=n-1 )return -1;
            sort(mst.begin(), mst.end(), [](const vector<int>&a, const vector<int>&b){
                return a[2]<b[2];
            });
    
            int count =0;
            int i=0;
    
            while(count<k && i<mst.size()){
                if(mst[i][3] ==1){
                    i++;
                }else{
                    mst[i][2] = mst[i][2]*2;
                    i++;
                    count++;
                }
            }
            int stability = INT_MAX;
            for(auto & edge : mst){
                stability = min(stability , edge[2]);
            }
    
            
            return stability;
    
        }
    };