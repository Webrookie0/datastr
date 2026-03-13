
class Solution{
public:
    int prims(vector<vector<int>& points, int V){
        priority_queue<pair<int, int>, vector< pair<int , int>>, greater<pair<int , int>>>pq;
    vector<bool>visited(points.size(), false);

    int res = 0;

    // Start from node 0
    pq.push({0, 0});

    while(!pq.empty()) {

        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if(visited[u])
            continue;

        res += wt;
        visited[u] = true;

        // Push adjacent edges
        for(auto &v : adj[u]) {

            if(!visited[v[0]]) {
                pq.push({v[1], v[0]});
            }
        }
    }

    return res;
    }
    
}