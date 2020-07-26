#include<bits/stdc++.h>
#define dispv(a) for(int i=0; i<a.size(); ++i) cout << a[i] << ' '; cout << '\n'
using namespace std;

class Edge {
public:
    int from, to, weight;    
    Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

class Graph {
public:
    vector<Edge> edges;
    int num_vertices;

    Graph(int v) : num_vertices(v) {}
    Graph(int v, vector<Edge> e) : num_vertices(v), edges(e) {}

    void sortEdgesByWeight() {
        sort(edges.begin(), edges.end(), [](const Edge &e1, const Edge &e2)->bool {
            return e1.weight < e2.weight;
        });
    }
};

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        for(int i=0; i<n; ++i) parent[i] = i;
    }

    int find(int v) {
        if(parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }

    void merge(int u, int v) {
        int urep = find(u);
        int vrep = find(v);
        parent[vrep] = urep;
    }
};

/*
    Kruskal's Algorithm To find MST
    Time Complexity: O(ElogE) or O(ElogV). 
        Sorting of edges takes O(ELogE) time. After sorting, we iterate through all edges and apply find-union algorithm. 
        The find and union operations can take atmost O(LogV) time. 
        So overall complexity is O(ELogE + ELogV) time. 
        The value of E can be atmost O(V2), so O(LogV) are O(LogE) same. 
        Therefore, overall time complexity is O(ElogE) or O(ElogV)
    Space Complexity: O(V) - For DSU
*/
int spanningTree(Graph &g) {
    g.sortEdgesByWeight();
    int num_edges_in_mst = 0;
    int i=0, sum=0;
    DSU mst(g.num_vertices);

    for(;num_edges_in_mst < g.num_vertices - 1 && i < g.num_vertices; ++i) {
        int fromRep = mst.find(g.edges[i].from);
        int toRep = mst.find(g.edges[i].to);
        if(fromRep == toRep) continue;

        mst.merge(fromRep, toRep);

        num_edges_in_mst++;
        sum += g.edges[i].weight;
    }

    return sum;
}

int main() {
    int v, e;
    cin >> v >> e;
    Graph g(v);
    int from, to, weight;
    for(int i=0; i<e; ++i) {
        cin >> from >> to >> weight;
        g.edges.push_back(Edge(from, to, weight));
    }

    cout  << "Sum of weights in MST: " << spanningTree(g) << '\n';

    return 0;
}