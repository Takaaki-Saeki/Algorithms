class UnionFind {
public:
    vector<ll> par;
    vector<ll> size;

    UnionFind(ll N){
        par.resize(N);
        size.resize(N);
        for(int i=0; i<N; i++){
            par[i] = i;
            size[i] = 1;
        }
    }

    ll root(ll x) {
        if (par[x] == x) return x;
        return root(par[x]);
    }

    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(size[rx] <= size[ry]){
            par[rx] = ry;
            size[ry] += size[rx]; 
        }else{
            par[ry] = rx;
            size[rx] += size[ry]; 
        }
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return true;
        else return false;
    }

    ll get_size(ll x){
        ll rx = root(x);
        return size[rx];
    }
};