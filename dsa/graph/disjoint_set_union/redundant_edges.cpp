class unionfind{
    vector<int>parent;
    vector<int>len;
public:
    unionfind(int size){
        parent.resize(size);
        len.resize(size);

        for(int i=0; i<size; i++){
            parent[i]=i;
            len[i]=1;
        }
    }

    int find(int node){
        if(parent[node]==node)return node;
        return find(parent[node]);
    }

    bool unite(int x, int y){
        int xrep= find(x);
        int yrep= find(y);
        if(xrep==yrep)return false;

        // doing union by size
        if(len[xrep]>len[yrep]){
            len[xrep]+=len[yrep];
            parent[yrep]= xrep;
        }else{
            len[yrep]+=len[xrep];
            parent[xrep]=yrep;
        }
        return true;
    }    
};




class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unionfind uf(n);

        // here we made the union find object and then we build that object 
        // then we use this object and then if while building 
        //  we find that the union is not possible , then this means that eedge is causing redundancy 
        // return that edge
        for(auto & it: edges){
            if(!uf.unite(it[0]-1, it[1]-1))return {it[0], it[1]};

        }
        // otherwise return the empty vector
        return {};
    }
};