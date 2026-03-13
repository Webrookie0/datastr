class unionfind{
    vector<int>parent;
    vector<int>len;
public:
    unionfind(int size){
        parent.resize(size);
        len.resize(size);

        for(int i=0; i<size; i++){
            parent[i]=i;
            size[i]=1;
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
        if(size[xrep]>size[yrep]){
            size[xrep]+=size[yrep];
            parent[yrep]= xrep;
        }else{
            size[yrep]+=size[xrep];
            parent[xrep]=yrep;
        }
        return true;
    }    
};
