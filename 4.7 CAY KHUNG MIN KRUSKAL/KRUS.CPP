#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
    bool operator<(const Edge& other) const
    {
        if (w == other.w) {
            if (u == other.u) return v < other.v;
            return u < other.u;
        }
        return w < other.w;
    }
};

struct DSU
{
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int find(int i)
    {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);

        if(root_u != root_v){
            if(rank[root_u] < rank[root_v]) parent[root_u] = root_v;
            else if(rank[root_u] > rank[root_v]) parent[root_v] = root_u;
            else{
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            return 1;
        }
        return 0;
    }
};

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for(int i = 0; i < E; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(V);
    vector<Edge> mst;
    long long trong_so_min = 0;
    int edge_count = 0;

    for(auto edge : edges){
        if(dsu.unite(edge.u, edge.v)){
            trong_so_min += edge.w;
            edge_count++;
            mst.push_back(edge);
            if(edge_count == V - 1) break;
        }
    }

    if (edge_count == V - 1) {
        cout << trong_so_min << "\n";
        for (int i = 0; i < mst.size(); i++) {
            cout << min(mst[i].u, mst[i].v) << " "
                 << max(mst[i].u, mst[i].v) << " "
                 << mst[i].w << "\n";
        }
    }
    else cout << 0 << "\n";

    return 0;
}
